// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/src/OutputDataWriteStrategy.cpp
//! @brief     Implements class OutputDataWriteStrategy.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "OutputDataWriteStrategy.h"
#include "OutputData.h"
#include <iostream>
#include <iomanip>


void OutputDataWriteStreamINT::writeOutputData(const OutputData<double> &data, std::ostream &output_stream)
{
    output_stream << "# BornAgain Intensity Data" << std::endl;

    for(size_t i=0; i<data.getRank(); ++i) {
        const IAxis *axis = data.getAxis(i);
        output_stream << std::endl;
        output_stream << "# axis-" << i << std::endl;
        output_stream << (*axis) << std::endl;
    }

    output_stream << std::endl;
    output_stream << "# data" << std::endl;
    OutputData<double>::const_iterator it = data.begin();
    int ncol(0);
    const int ncol_max(10);
    while(it != data.end()) {
        ncol++;
        double z_value = *it++;
        output_stream << std::scientific << std::setprecision(m_precision) << z_value << "    ";
        if(ncol == ncol_max) {
            output_stream << std::endl;
            ncol = 0;
        }
    }
    output_stream << std::endl;

}


