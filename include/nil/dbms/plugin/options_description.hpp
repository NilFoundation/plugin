//---------------------------------------------------------------------------//
// Copyright (c) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Server Side Public License, version 1,
// as published by the author.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Server Side Public License for more details.
//
// You should have received a copy of the Server Side Public License
// along with this program. If not, see
// <https://github.com/NilFoundation/dbms/blob/master/LICENSE_1_0.txt>.
//---------------------------------------------------------------------------//

#ifndef DBMS_OPTIONS_DESCRIPTIONS_HPP
#define DBMS_OPTIONS_DESCRIPTIONS_HPP

#include <boost/program_options/options_description.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            struct cli_options_description : public boost::program_options::options_description {
                /** Creates the instance. */
                cli_options_description(unsigned line_length = m_default_line_length,
                                        unsigned min_description_length = m_default_line_length / 2) :
                    options_description(line_length, min_description_length) {
                }
                /** Creates the instance. The 'caption' parameter gives the name of
                    this 'options_description' instance. Primarily useful for output.
                    The 'description_length' specifies the number of columns that
                    should be reserved for the description text; if the option text
                    encroaches into this, then the description will start on the next
                    line.
                */
                cli_options_description(const std::string &caption,
                                        unsigned line_length = m_default_line_length,
                                        unsigned min_description_length = m_default_line_length / 2) :
                    options_description(caption, line_length, min_description_length),
                    c(caption) {
                }

                virtual ~cli_options_description() = default;

                const std::string &caption() const {
                    return c;
                }

            protected:
                std::string c;
            };

            struct cfg_options_description : public boost::program_options::options_description {
                /** Creates the instance. */
                cfg_options_description(unsigned line_length = m_default_line_length,
                                        unsigned min_description_length = m_default_line_length / 2) :
                    options_description(line_length, min_description_length) {
                }
                /** Creates the instance. The 'caption' parameter gives the name of
                    this 'options_description' instance. Primarily useful for output.
                    The 'description_length' specifies the number of columns that
                    should be reserved for the description text; if the option text
                    encroaches into this, then the description will start on the next
                    line.
                */
                cfg_options_description(const std::string &caption,
                                        unsigned line_length = m_default_line_length,
                                        unsigned min_description_length = m_default_line_length / 2) :
                    options_description(caption, line_length, min_description_length),
                    c(caption) {
                }

                virtual ~cfg_options_description() = default;

                const std::string &caption() const {
                    return c;
                }

            protected:
                std::string c;
            };
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_DBMSD_HPP
