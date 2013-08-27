// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/inc/MathFunctions.h
//! @brief     Define many functions in namespace MathFunctions,
//!              and provide inline implementation for most of them
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include "Types.h"
#include "Units.h"
#include "Numeric.h"

#include <cstdlib>
#include <vector>

#include "gsl/gsl_sf_bessel.h"
#include "gsl/gsl_sf_trig.h"
#include "gsl/gsl_sf_expint.h"
#include "gsl/gsl_integration.h"

#ifndef GCCXML_SKIP_THIS
#include <Eigen/Core>
#endif

//! Various mathematical functions.

namespace MathFunctions
{

BA_CORE_API_ double Gaussian(double value, double average, double std_dev);

BA_CORE_API_ double IntegratedGaussian(double value, double average, double std_dev);

BA_CORE_API_ double GenerateNormalRandom(double average, double std_dev);

BA_CORE_API_ double StandardNormal(double value);

BA_CORE_API_ double GenerateStandardNormalRandom();

BA_CORE_API_ double GenerateUniformRandom();

//! Bessel function of the first kind and order 1
BA_CORE_API_ double Bessel_J1(double value);

//! Bessel function  Bessel_J1(x)/x
BA_CORE_API_ inline double Bessel_C1(double value);

//! Sine integral function: \f$Si(x)\equiv\int_0^x du \sin(u)/u\f$
BA_CORE_API_ double Si(double value);

//! Sinc function: \f$Sinc(x)\equiv\sin(x)/x\f$
BA_CORE_API_ double Sinc(double value);

//! Complex Sinc function: \f$Sinc(x)\equiv\sin(x)/x\f$
BA_CORE_API_ complex_t Sinc(const complex_t &value);

BA_CORE_API_ complex_t Laue(const complex_t &value, size_t N);

enum TransformCase { ForwardFFT, BackwardFFT };
std::vector<complex_t > FastFourierTransform(const std::vector<complex_t > &data, TransformCase tcase);

std::vector<complex_t > FastFourierTransform(const std::vector<double > &data, TransformCase tcase);

std::vector<complex_t> ConvolveFFT(const std::vector<double> &signal, const std::vector<double> &resfunc);

//! fast sine calculations (not actually fast)
double FastSin(const double& x);

//! fast cosine calculation  (not actually fast)
double FastCos(const double& x);

//! fast complex sine calculation
complex_t FastSin(const complex_t &x);

//! fast complex cosine calculation
complex_t FastCos(const complex_t &x);

//! simultaneous complex sine and cosine calculations
void FastSinCos(const complex_t &x, complex_t &xsin, complex_t &xcos);

#ifndef GCCXML_SKIP_THIS
Eigen::Matrix2d Norm(Eigen::Matrix2cd &M);
#endif

} // Namespace MathFunctions

inline double MathFunctions::GenerateNormalRandom(double average, double std_dev)
{
    return GenerateStandardNormalRandom()*std_dev + average;
}

inline double MathFunctions::GenerateUniformRandom()
{
    int random_int = std::rand();
    return (double)random_int / RAND_MAX;
}

inline double MathFunctions::Bessel_J1(double value)
{
    return gsl_sf_bessel_J1(value);
}

inline double MathFunctions::Bessel_C1(double value)
{
    return ( value > Numeric::double_epsilon ? gsl_sf_bessel_J1(value)/value : 0.5);
}

inline double MathFunctions::Si(double value)  // int_0^x du Sin(u)/u
{
    return gsl_sf_Si(value);
}

inline double MathFunctions::Sinc(double value)  // Sin(x)/x
{
    return gsl_sf_sinc(value/M_PI);
}

// TODO: protection against complex number like (-246.977,-399.616)
inline complex_t MathFunctions::Sinc(const complex_t &value)  // Sin(x)/x
{
    if(std::abs(value)<Numeric::double_epsilon)
        return complex_t(1.0, 0.0);
    return std::sin(value)/value;
}

inline complex_t MathFunctions::Laue(const complex_t &value, size_t N) // Exp(iNx/2)*Sin((N+1)x)/Sin(x)
{
    if (N==0)
        return complex_t(1.0, 0.0);
    if(std::abs(value)<Numeric::double_epsilon)
        return complex_t(N+1.0, 0.0);
    return std::exp(complex_t(0.0, 1.0)*value*(double)N/2.0)*std::sin(value*(N+1.0)/2.0)/std::sin(value/2.0);
}

//! fast sine calculations (not actually fast)
inline double MathFunctions::FastSin(const double& x) {
    const double P = 0.225f;
    const double A = 16 * std::sqrt(P);
    const double B = (1 - P) / std::sqrt(P);
    double y = x / (2 * M_PI);
    y = y - std::floor(y + 0.5);  // y in range -0.5..0.5
    y = A * y * (0.5 - std::abs(y));
    return y * (B + std::abs(y));
}

//! fast cosine calculation  (not actually fast)
inline double MathFunctions::FastCos(const double& x) {
    const double P = 0.225f;
    const double A = 16 * std::sqrt(P);
    const double B = (1 - P) / std::sqrt(P);
    double y = x / (2 * M_PI)+0.25; // pi/2. shift
    y = y - std::floor(y + 0.5);  // y in range -0.5..0.5
    y = A * y * (0.5 - std::abs(y));
    return y * (B + std::abs(y));
}

//! fast complex sine calculation
inline complex_t MathFunctions::FastSin(const complex_t &x) {
    // sin(a+bi) = sin(a)cosh(b) + i*cos(a)*sinh(b);
    //return complex_t( FastSin(x.real())*std::cosh(x.imag()), FastCos(x.real())*std::sinh(x.imag()));
    return complex_t( std::sin(x.real())*std::cosh(x.imag()), std::cos(x.real())*std::sinh(x.imag()));
}

//! fast complex cosine calculation
inline complex_t MathFunctions::FastCos(const complex_t &x) {
    // cos(a+bi) = cos(a)cosh(b) - i*sin(a)*sinh(b);
    //return complex_t( FastCos(x.real())*std::cosh(x.imag()), -1*FastSin(x.real())*std::sinh(x.imag()));
    return complex_t( std::cos(x.real())*std::cosh(x.imag()), -1*std::sin(x.real())*std::sinh(x.imag()));
}

//! simultaneous complex sine and cosine calculations
inline void MathFunctions::FastSinCos(const complex_t &x,
                                      complex_t &xsin, complex_t &xcos)
{
    double sina = FastSin(x.real());
    double cosa = std::sqrt(1-sina*sina);
    double sinhb = std::sinh(x.imag());
    double coshb = std::sqrt(1-sinhb*sinhb);
    xsin = complex_t( sina*coshb,  cosa*sinhb );
    xcos = complex_t( cosa*coshb, -sina*sinhb );
}

#ifndef GCCXML_SKIP_THIS
inline Eigen::Matrix2d MathFunctions::Norm(Eigen::Matrix2cd &M) {
    Eigen::Matrix2d result;
    result(0,0) = std::norm((complex_t)M(0,0));
    result(0,1) = std::norm((complex_t)M(0,1));
    result(1,0) = std::norm((complex_t)M(1,0));
    result(1,1) = std::norm((complex_t)M(1,1));
    return result;
}
#endif

#endif // MATHFUNCTIONS_H


