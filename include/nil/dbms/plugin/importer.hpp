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

#ifndef DBMS_PLUGIN_IMPORTER_HPP
#define DBMS_PLUGIN_IMPORTER_HPP

#include <nil/dbms/plugin/abstract.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            struct BOOST_SYMBOL_VISIBLE importer {
                typedef boost::shared_ptr<abstract> result_type;

                inline result_type operator()(boost::shared_ptr<boost::dll::shared_library> p) const {
                    return boost::dll::import<abstract>(*p, "plugin");
                }
            };
            // namespace plugin
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_LOADER_HPP
