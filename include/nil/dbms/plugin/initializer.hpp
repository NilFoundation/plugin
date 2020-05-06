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

#ifndef DBMS_PLUGIN_INITIALIZER_HPP
#define DBMS_PLUGIN_INITIALIZER_HPP

#include <nil/dbms/plugin/abstract.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            struct BOOST_SYMBOL_VISIBLE initializer {
                template<typename DescRange, typename OutputIterator>
                inline static OutputIterator process(const DescRange &r, OutputIterator out) {
                    return process(r.begin(), r.end(), out);
                }

                template<typename DescIterator, typename OutputIterator>
                inline static OutputIterator process(DescIterator first, DescIterator last, OutputIterator out) {
                    while (first != last) {
                        *out++ = boost::dll::import<abstract>(*first, "plugin");
                        ++first;
                    }

                    return out;
                }
            };
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_LOADER_HPP
