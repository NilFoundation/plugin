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
#include <nil/dbms/plugin/descriptor.hpp>

namespace nil::dbms::plugin {
    namespace detail {
        template<typename>
        struct is_tuple : std::false_type { };

        template<typename... T>
        struct is_tuple<std::tuple<T...>> : std::true_type { };

    }    // namespace detail
    struct BOOST_SYMBOL_VISIBLE initializer {
        template<typename DescRange, typename OutputIterator>
        inline static void process(const DescRange &r, OutputIterator out) {
            return process(r.begin(), r.end(), out);
        }

        template<typename DescIterator, typename OutputIterator>
        inline static void process(
            DescIterator first, DescIterator last,
            typename std::enable_if<!detail::is_tuple<typename std::iterator_traits<OutputIterator>::value_type>::value,
                                    OutputIterator>::type out) {
            typedef boost::shared_ptr<abstract>(pluginapi_create_t)();

            while (first != last) {
                *out = boost::dll::import_alias<pluginapi_create_t>(first->lib, "create_plugin")();
                ++first;
            }
        }

        template<typename DescIterator, typename OutputIterator>
        inline static void process(
            DescIterator first, DescIterator last,
            typename std::enable_if<detail::is_tuple<typename std::iterator_traits<OutputIterator>::value_type>::value,
                                    OutputIterator>::type out) {
            typedef boost::shared_ptr<abstract>(pluginapi_create_t)();

            while (first != last) {
                *out = std::make_pair(std::move(*first),
                                      boost::dll::import_alias<pluginapi_create_t>(first->lib, "create_plugin")());
                ++first;
            }
        }
    };
}    // namespace nil::dbms::plugin

#endif    // DBMS_LOADER_HPP
