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

#ifndef DBMS_PLUGIN_VARIABLES_MAP_HPP
#define DBMS_PLUGIN_VARIABLES_MAP_HPP

#include <boost/program_options/variables_map.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            struct variables_map : public boost::program_options::variables_map {
                variables_map() : boost::program_options::variables_map() {
                }
                variables_map(const abstract_variables_map *next) : boost::program_options::variables_map(next) {
                }
            };
        }
    }    // namespace dbms
}    // namespace nil

#endif    // DBMS_DBMSD_HPP
