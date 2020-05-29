//----------------------------------------------------------------------------
// Copyright (C) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
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
// <https://github.com/NilFoundation/plugin/blob/master/LICENSE_1_0.txt>.
//----------------------------------------------------------------------------

#ifndef DBMS_CONFIGURABLE_HPP
#define DBMS_CONFIGURABLE_HPP

#include <boost/program_options.hpp>

namespace nil {
    namespace dbms {
        struct BOOST_SYMBOL_VISIBLE configurable {
            virtual void set_program_options(boost::program_options::options_description &cli,
                                             boost::program_options::options_description &cfg) = 0;
            virtual void initialize(boost::application::global_context_ptr ctx,
                                    const boost::program_options::variables_map &options) = 0;
        };
    }    // namespace dbms
}    // namespace nil

#endif    // DBMS_CONFIGURABLE_HPP
