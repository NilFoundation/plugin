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

#ifndef DBMS_PLUGIN_DESCRIPTOR_HPP
#define DBMS_PLUGIN_DESCRIPTOR_HPP

#include <boost/config.hpp>
#include <boost/dll.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            template<typename PluginType>
            struct BOOST_SYMBOL_VISIBLE descriptor {
                typedef PluginType plugin_type;
                typedef typename plugin_type::id_type id_type;
                typedef typename plugin_type::name_type name_type;

                typedef boost::dll::shared_library library_type;

                boost::shared_ptr<library_type> lib;
                boost::shared_ptr<plugin_type> plugin;
            };
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_PLUGIN_HPP
