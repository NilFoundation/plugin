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

#ifndef DBMS_PLUGIN_OPERATOR_HPP
#define DBMS_PLUGIN_OPERATOR_HPP

#include <nil/dbms/plugin/container.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            template<typename PluginType, typename PluginContainer>
            struct BOOST_SYMBOL_VISIBLE processor {
                typedef PluginType plugin_type;
                typedef PluginContainer container_type;

                typedef typename container_type::value_type descriptor_type;

                explicit processor(container_type &p) : p(p) {
                }

                virtual ~processor() {
                }

            protected:
                container_type &p;
            };
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_SCANNER_HPP
