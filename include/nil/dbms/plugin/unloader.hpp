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

#ifndef DBMS_PLUGIN_UNLOADER_HPP
#define DBMS_PLUGIN_UNLOADER_HPP

#include <nil/dbms/plugin/processor.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            template<typename PluginType, typename PluginContainer>
            class BOOST_SYMBOL_VISIBLE unloader : public processor<PluginType, PluginContainer> {
                typedef processor<PluginType, PluginContainer> policy_type;

            public:
                typedef typename policy_type::plugin_type plugin_type;
                typedef typename policy_type::container_type container_type;

                typedef typename container_type::value_type descriptor_type;

                unloader(container_type &p) : processor(p) {
                }

                inline virtual typename container_type::iterator unload(const boost::filesystem::path &path) {

                }

                template<typename InputIterator>
                inline typename container_type::iterator unload(InputIterator first, InputIterator last) {
                    typename container_type::iterator result = this->p.end();
                    while (first != last) {
                        result = unload(*first);
                        ++first;
                    }
                    return result;
                }

                template<typename SinglePassRange>
                inline typename container_type::iterator unload(const SinglePassRange &r) {
                    return unload(r.begin(), r.end());
                }
            };
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_SCANNER_HPP
