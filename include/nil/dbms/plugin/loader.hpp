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
#include <nil/dbms/plugin/descriptor.hpp>

namespace nil::dbms::plugin {
    struct BOOST_SYMBOL_VISIBLE loader {
        template<typename DirectoryRange, typename OutputIterator>
        inline static OutputIterator process(const DirectoryRange &r, OutputIterator out) {
            return process(r.begin(), r.end(), out);
        }

        template<typename DirectoryIterator, typename OutputIterator>
        inline static OutputIterator process(DirectoryIterator first, DirectoryIterator last, OutputIterator out) {
            while (first != last) {
                boost::dll::shared_library lib(first->string(), boost::dll::load_mode::append_decorations);

                lib.has("create_plugin") ? out++ = {*first++, lib} : ++first;
            }

            return out;
        }
    };
}    // namespace nil::dbms::plugin

#endif    // DBMS_SCANNER_HPP
