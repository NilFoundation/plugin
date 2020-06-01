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
        template<typename OptionsType, typename ConfigurationType>
        struct BOOST_SYMBOL_VISIBLE configurable {
            typedef OptionsType options_type;
            typedef ConfigurationType configuration_type;

            virtual void set_options(options_type &cli, options_type &cfg) const = 0;
            virtual void initialize(configuration_type &options) = 0;
        };
    }    // namespace dbms
}    // namespace nil

#endif    // DBMS_CONFIGURABLE_HPP
