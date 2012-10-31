#ifndef ISQUAREDFUNCTION_H_
#define ISQUAREDFUNCTION_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   ISquaredFunction.h
//! @brief  Definition of
//! @author Scientific Computing Group at FRM II
//! @date   Jul 20, 2012

#include "Numeric.h"

#include <cmath>
#include <iostream>

class ISquaredFunction
{
public:
    virtual ~ISquaredFunction() {}
    virtual ISquaredFunction *clone() const=0;

    virtual double calculateSquaredDifference(double real_value, double simulated_value) const=0;
};

class DefaultSquaredFunction : public ISquaredFunction
{
public:
    DefaultSquaredFunction() {}
    virtual ~DefaultSquaredFunction() {}
    virtual DefaultSquaredFunction *clone() const { return new DefaultSquaredFunction(); }

    virtual double calculateSquaredDifference(double real_value, double simulated_value) const;
};

//inline double DefaultSquaredFunction::calculateSquaredDifference(
//        double real_value, double simulated_value) const
//{
//    double diff_squared = (simulated_value-real_value)*(simulated_value-real_value);
//    if (diff_squared < Numeric::double_epsilon) {
//        return 0.0;
//    }
////    double normalization = std::max(std::abs(real_value), 1.0);
//    double normalization = 1.0;
//    return diff_squared/normalization;
//}


inline double DefaultSquaredFunction::calculateSquaredDifference(
        double real_value, double simulated_value) const
{
//    real_value = std::max(real_value, 1.0);
//    simulated_value = std::max(simulated_value, 1.0);
    double diff_squared = (simulated_value-real_value)*(simulated_value-real_value);
    if (diff_squared < Numeric::double_epsilon) {
        return 0.0;
    }
    double sigma1 = std::max(real_value,1.0);
    double sigma2 = std::max(simulated_value,1.0);
    double sigma = std::sqrt(sigma1*sigma1 + sigma2*sigma2);
    double normalization = sigma;
    return diff_squared/normalization;
}




#endif /* ISQUAREDFUNCTION_H_ */
