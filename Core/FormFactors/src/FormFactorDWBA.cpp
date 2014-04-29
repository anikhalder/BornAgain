// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/src/FormFactorDWBA.cpp
//! @brief     Implements class FormFactorDWBA.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorDWBA.h"

#include <cmath>

FormFactorDWBA::FormFactorDWBA(IFormFactor *p_form_factor)
    : IFormFactorDecorator(p_form_factor)
    , mp_specular_info(0)
{
    setName("FormFactorDWBA");
}

FormFactorDWBA::~FormFactorDWBA()
{
    delete mp_specular_info;
}

FormFactorDWBA* FormFactorDWBA::clone() const
{
    FormFactorDWBA *result = new FormFactorDWBA(mp_form_factor->clone());
    if (mp_specular_info) {
        result->setSpecularInfo(*mp_specular_info);
    }
    result->setName(getName());
    return result;
}

complex_t FormFactorDWBA::evaluate(const cvector_t& k_i,
        const Bin1DCVector& k_f_bin, const Bin1D &alpha_f_bin) const
{
    calculateTerms(k_i, k_f_bin, alpha_f_bin);
    return m_term_S + m_term_RS + m_term_SR + m_term_RSR;
}

void FormFactorDWBA::setSpecularInfo(
        const LayerSpecularInfo& layer_specular_info)
{
    delete mp_specular_info;
    mp_specular_info = layer_specular_info.clone();
}

void FormFactorDWBA::calculateTerms(const cvector_t& k_i,
        const Bin1DCVector& k_f_bin, const Bin1D &alpha_f_bin) const
{
    // Retrieve the two different incoming wavevectors in the layer
    const ILayerRTCoefficients *p_in_coeff =
            mp_specular_info->getInCoefficients();
    cvector_t k_i_R = k_i;
    k_i_R.setZ(p_in_coeff->getScalarKz());
    cvector_t k_i_T = k_i;
    k_i_T.setZ(-k_i_R.z());
    // Retrieve the two different outgoing wavevector bins in the layer
    kvector_t k_real_lower(k_f_bin.m_q_lower.x().real(),
                           k_f_bin.m_q_lower.y().real(),
                           k_f_bin.m_q_lower.z().real());
    double k_length = k_real_lower.mag();
    double z_min = std::sin(alpha_f_bin.m_lower)*k_length;
    double z_max = std::sin(alpha_f_bin.m_upper)*k_length;
    double zeta_lower = 0.0;
    double zeta_upper = 0.0;
    if (alpha_f_bin.m_lower != alpha_f_bin.m_upper) {
        zeta_lower = (k_f_bin.m_q_lower.z().real() - z_min) / (z_max - z_min);
        zeta_upper = (k_f_bin.m_q_upper.z().real() - z_min) / (z_max - z_min);
    }

    const ILayerRTCoefficients *p_out_lower = getOutCoeffs(alpha_f_bin.m_lower);
    const ILayerRTCoefficients *p_out_upper = getOutCoeffs(alpha_f_bin.m_upper);
    Bin1DCVector k_f_T_bin = k_f_bin;
    complex_t kfz_lower = p_out_lower->getScalarKz() + zeta_lower*
            (p_out_upper->getScalarKz() - p_out_lower->getScalarKz());
    complex_t kfz_upper = p_out_lower->getScalarKz() + zeta_upper*
            (p_out_upper->getScalarKz() - p_out_lower->getScalarKz());
    k_f_T_bin.m_q_lower.setZ(kfz_lower);
    k_f_T_bin.m_q_upper.setZ(kfz_upper);
    Bin1DCVector k_f_R_bin = k_f_bin;
    k_f_R_bin.m_q_lower.setZ(-k_f_T_bin.m_q_lower.z());
    k_f_R_bin.m_q_upper.setZ(-k_f_T_bin.m_q_upper.z());



    // The four different scattering contributions; S stands for scattering
    // off the particle, R for reflection off the layer interface
    double alpha_f = alpha_f_bin.getMidPoint();
    const ILayerRTCoefficients *p_out_coeff = getOutCoeffs(alpha_f);
    m_term_S = p_in_coeff->getScalarT()*mp_form_factor->evaluate(k_i_T,
            k_f_T_bin, alpha_f_bin) * p_out_coeff->getScalarT();
    m_term_RS = p_in_coeff->getScalarR()*mp_form_factor->evaluate(k_i_R,
            k_f_T_bin, alpha_f_bin) * p_out_coeff->getScalarT();
    m_term_SR = p_in_coeff->getScalarT()*mp_form_factor->evaluate(k_i_T,
            k_f_R_bin, alpha_f_bin) * p_out_coeff->getScalarR();
    m_term_RSR = p_in_coeff->getScalarR()*mp_form_factor->evaluate(k_i_R,
            k_f_R_bin, alpha_f_bin) * p_out_coeff->getScalarR();
}


