#include "CustomBinAxis.h"
#include "Units.h"
#include <iomanip>

CustomBinAxis::CustomBinAxis(const std::string &name, size_t nbins, double start, double end)
    : VariableBinAxis(name, nbins)
    , m_start(start)
    , m_end(end)
{
    if(m_start >= m_end)
        throw Exceptions::LogicErrorException("CustomBinAxis::CustomBinAxis() -> Error. start >= end is not allowed.");

    double start_sin = std::sin(start);
    double end_sin = std::sin(end);
    double step = (end_sin - start_sin)/(m_nbins-1);  // m_nbins-1 is intentionally

    m_bin_centers.resize(m_nbins, 0.0);
    for(size_t i=0; i<m_bin_centers.size(); ++i) {
        m_bin_centers[i] = std::asin(start_sin + i*step);
    }

    std::vector<double> bin_boundaries;
    bin_boundaries.resize(m_nbins + 1, 0.0);
    for(size_t i=0; i<bin_boundaries.size(); ++i) {
        bin_boundaries[i] = std::asin(start_sin -step/2. + step*i);
    }
    setBinBoundaries(bin_boundaries);

//    for(size_t i=0; i<m_centers.size(); ++i) {
//        std::cout << i << " " << Units::rad2deg(m_bin_boundaries[i]) << " " << Units::rad2deg(m_centers[i]) << Units::rad2deg(m_bin_boundaries[i+1]) << std::endl;
//    }

}


CustomBinAxis *CustomBinAxis::clone() const
{
    return new CustomBinAxis(getName(), m_nbins, m_start, m_end);
}

Bin1D CustomBinAxis::getBin(size_t index) const
{
    if(index >= m_nbins)
        throw Exceptions::OutOfBoundsException("CustomBinAxis::getBin() -> Error. Wrong index.");

    Bin1D result = { m_bin_centers[index], m_bin_centers[index] };
    return result;
}

std::vector<double> CustomBinAxis::getBinCenters() const
{
    return m_bin_centers;
}


void CustomBinAxis::print(std::ostream &ostr) const
{
    ostr << "CustomBinAxis(\"" << m_name << "\", " << getSize() << ", " << std::setprecision(std::numeric_limits<double>::digits10+2) << m_start << ", " << m_end << ")";
}


bool CustomBinAxis::equals(const IAxis &other) const
{
    if (!IAxis::equals(other)) return false;
    if (const CustomBinAxis *otherAxis = dynamic_cast<const CustomBinAxis *>(&other)) {
        if (getSize() != otherAxis->getSize()) return false;
        if ( std::abs(m_start - otherAxis->m_start) > Numeric::double_epsilon) return false;
        if ( std::abs(m_end - otherAxis->m_end) > Numeric::double_epsilon) return false;
        return true;
    }
    return false;
}