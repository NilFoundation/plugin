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

#ifndef DBMS_PLUGIN_LOADER_HPP
#define DBMS_PLUGIN_LOADER_HPP

#include <nil/dbms/plugin/abstract.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            struct BOOST_SYMBOL_VISIBLE loader {
                typedef boost::shared_ptr<boost::dll::shared_library> result_type;

                inline result_type operator()(const boost::filesystem::path &p) const {
                    boost::shared_ptr<boost::dll::shared_library> lib =
                        boost::make_shared<boost::dll::shared_library>(p, boost::dll::load_mode::append_decorations);

                    if (lib->has("create_plugin")) {
                        return lib;
                    } else {
                        return boost::make_shared<boost::dll::shared_library>();
                    }
                }
            };
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_SCANNER_HPP
