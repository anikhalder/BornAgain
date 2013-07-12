// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/inc/SpecularMatrix.h
//! @brief     Defines class SpecularMatrix.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef SPECULARMATRIX_H_
#define SPECULARMATRIX_H_

#include "Types.h"
#include "ISimulation.h"
#include "MultiLayer.h"

#include "Eigen/Core"

//! Implements the matrix formalism for the calculation of wave amplitudes of
//! the coherent wave solution in a multilayer

class SpecularMatrix : public ISimulation
{
public:
    SpecularMatrix() {}

   //! layer coefficients for matrix formalism
   class LayerMatrixCoeff {
   public:
       LayerMatrixCoeff() : lambda(0) {}
       ~LayerMatrixCoeff() {}
       complex_t R() const { return (phi_psi(1)+phi_psi(0)/lambda)/2.0; }
       complex_t T() const { return (phi_psi(1)-phi_psi(0)/lambda)/2.0; }
       // A - amplitude of initial wave, R, T - amplitudes of reflected and transmitted waves
       complex_t lambda; // positive eigenvalue of transfer matrix
       Eigen::Vector2cd phi_psi;
       Eigen::Matrix2cd l;
       Eigen::Matrix2cd l_accumulated;
   };

   //! multi layer coefficients for matrix formalism
   class MultiLayerMatrixCoeff
   {
   public:
       inline LayerMatrixCoeff& operator[](size_t i) { return m_data[i]; }
       inline const LayerMatrixCoeff& operator[](size_t i) const { return m_data[i]; }
       inline size_t size() const { return m_data.size(); }
       inline void clear() { m_data.clear(); }
       inline void resize(size_t size) { m_data.resize(size); }
       complex_t R; // total reflection coefficient
       Eigen::Matrix2cd L;
   private:
       std::vector<LayerMatrixCoeff > m_data;
   };

   typedef MultiLayerMatrixCoeff MultiLayerCoeff_t; // set of layer coefficients for matrix formalism

   //! Returns Fresnel coefficients for given multi layer and kvector
   void execute(const MultiLayer& sample, const kvector_t& k, MultiLayerCoeff_t& coeff);

private:
   std::vector<Eigen::Matrix2cd> m_roughness_pmatrices;

   void calculateEigenvalues(const MultiLayer& sample, const kvector_t& k,
           MultiLayerCoeff_t& coeff) const;
   void calculateTransferAndBoundary(const MultiLayer& sample,
           const kvector_t& k, MultiLayerCoeff_t& coeff) const;
   Eigen::Matrix2cd calculatePMatrix(double sigma_eff,
           complex_t lambda_lower, complex_t lambda_upper) const;
   Eigen::Matrix2cd getUnitMatrix() const;
   complex_t getPMatrixElement(complex_t sigma_lambda) const;
};

#endif /* SPECULARMATRIX_H_ */
