#include "IParameterized.h"
#include "RealParameter.h"
#include "ParameterPool.h"
#include "FitParameterLinked.h"

#include "gtest/gtest.h"

class FitParameterLinkedTest : public ::testing::Test
{
 protected:
    FitParameterLinkedTest(){}
    virtual ~FitParameterLinkedTest(){}
};

TEST_F(FitParameterLinkedTest, defaultConstructor)
{
    FitParameterLinked fitParameterLinked;

    EXPECT_EQ("", fitParameterLinked.name());
    EXPECT_EQ(0.0, fitParameterLinked.value());
    EXPECT_EQ(0.0, fitParameterLinked.step());
    EXPECT_EQ(0.0, fitParameterLinked.error());

    EXPECT_FALSE(fitParameterLinked.limits().isLowerLimited());
    EXPECT_FALSE(fitParameterLinked.limits().isUpperLimited());
    EXPECT_FALSE(fitParameterLinked.limits().isLimited());
    EXPECT_FALSE(fitParameterLinked.limits().isFixed());
}

TEST_F(FitParameterLinkedTest, fullConstructor)
{
    AttLimits limits = AttLimits::limited(-10.0, 2.0);
    FitParameterLinked fitParameter("FitPL", 2.0, limits, 0.2);

    EXPECT_EQ("FitPL", fitParameter.name());
    EXPECT_EQ(2.0, fitParameter.value());
    EXPECT_EQ(0.2, fitParameter.step());
    EXPECT_EQ(-10.0, fitParameter.limits().lowerLimit());
    EXPECT_EQ(2.0, fitParameter.limits().upperLimit());
}

TEST_F(FitParameterLinkedTest, addParameter)
{
    class ParametrizedObject : public IParameterized
    {
    public:
        ParametrizedObject(double p1, double p2) : m_par1(p1), m_par2(p2)
        {
            registerParameter("par1", &m_par1);
            registerParameter("par2", &m_par2);
        }
        virtual void onChange() final {}
        double m_par1, m_par2;
    };
    ParametrizedObject obj1(1., 2.);
    ParametrizedObject obj2(3., 4.);

    const RealParameter* par11 = obj1.getParameter("par1");
    const RealParameter* par21 = obj2.getParameter("par2");

    FitParameterLinked linked;
    linked.addParameter(*par11);
    linked.addParameter(*par21);

    const double newValue(11.2);
    linked.setValue(newValue);
    EXPECT_EQ(linked.value(), newValue);

    EXPECT_EQ(obj1.getParameter("par1")->getValue(), newValue);
    EXPECT_EQ(obj1.m_par1, newValue);
    EXPECT_EQ(obj1.getParameter("par2")->getValue(), 2.0);
    EXPECT_EQ(obj1.m_par2, 2.0);

    EXPECT_EQ(obj2.getParameter("par1")->getValue(), 3.0);
    EXPECT_EQ(obj2.m_par1, 3.0);
    EXPECT_EQ(obj2.getParameter("par2")->getValue(), newValue);
    EXPECT_EQ(obj2.m_par2, newValue);
}

TEST_F(FitParameterLinkedTest, addMatchedParameters)
{
    ParameterPool pool;
    double par1(0.0), par2(0.0), par3(0.0);

    pool.addParameter(new RealParameter("/MultiLayer/Layer/Particle/height", &par1));
    pool.addParameter(new RealParameter("/MultiLayer/Layer/Particle/width", &par2));
    pool.addParameter(new RealParameter("/MultiLayer/Layer/thickness", &par3));

    double newValue(42.0);
    FitParameterLinked link1("/MultiLayer/Layer/thickness", 0.0, AttLimits::limitless());
    link1.addMatchedParameters(&pool);
    link1.setValue(newValue);
    EXPECT_EQ(link1.value(), newValue);
    EXPECT_EQ(par1, 0.0);
    EXPECT_EQ(par2, 0.0);
    EXPECT_EQ(par3, newValue);

    newValue = 100.0;
    par1 = par2 = par3 = 0.0;
    FitParameterLinked link2("*/Particle/*", 0.0, AttLimits::limitless());
    link2.addMatchedParameters(&pool);
    link2.setValue(newValue);
    EXPECT_EQ(link2.value(), newValue);
    EXPECT_EQ(par1, newValue);
    EXPECT_EQ(par2, newValue);
    EXPECT_EQ(par3, 0.0);
}

TEST_F(FitParameterLinkedTest, clone)
{
    ParameterPool pool;
    double par1(0.0), par2(0.0), par3(0.0);

    pool.addParameter(new RealParameter("/MultiLayer/Layer/Particle/height", &par1));
    pool.addParameter(new RealParameter("/MultiLayer/Layer/Particle/width", &par2));
    pool.addParameter(new RealParameter("/MultiLayer/Layer/thickness", &par3));

    const double value(1.0), step(0.1), lim1(0.2), lim2(10.0);
    const std::string pattern("*/Particle/*");
    FitParameterLinked *link = new FitParameterLinked(
                pattern, value, AttLimits::limited(lim1, lim2), step);
    link->addMatchedParameters(&pool);
    link->setValue(value);

    // deleting original and checking that clone is pointing to the same real parameters
    std::unique_ptr<FitParameterLinked> clone(link->clone());
    delete link;

    EXPECT_EQ(clone->name(), pattern);
    EXPECT_EQ(clone->value(), value);
    EXPECT_EQ(clone->startValue(), value);
    EXPECT_EQ(clone->step(), step);
    EXPECT_EQ(clone->error(), 0.0);

    // checking setValue for clone
    const double newValue(42.0);
    clone->setValue(newValue);
    EXPECT_EQ(clone->value(), newValue);
    EXPECT_EQ(par1, newValue);
    EXPECT_EQ(par2, newValue);
    EXPECT_EQ(par3, 0.0);
}
