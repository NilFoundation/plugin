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

#ifndef DBMS_PLUGIN_DETAIL_EXTRACTORS_HPP
#define DBMS_PLUGIN_DETAIL_EXTRACTORS_HPP

namespace nil {
    namespace dbms {
        namespace plugin {
            namespace detail {
                template<typename DescriptorType>
                struct id_extractor {
                    typedef DescriptorType descriptor_type;
                    typedef typename descriptor_type::id_type id_type;

                    typedef id_type result_type;

                    const result_type &operator()(const descriptor_type &e) const {
                        return e.plugin->id();
                    }
                };

                template<typename DescriptorType>
                struct name_extractor {
                    typedef DescriptorType descriptor_type;
                    typedef typename descriptor_type::name_type name_type;

                    typedef name_type result_type;

                    const result_type &operator()(const descriptor_type &e) const {
                        return e.plugin->name();
                    }
                };

                template<typename DescriptorType>
                struct path_extractor {
                    typedef DescriptorType descriptor_type;
                    typedef typename descriptor_type::name_type name_type;

                    typedef typename std::result_of<decltype (&descriptor_type::library_type::location)(
                        typename descriptor_type::library_type)>::type result_type;

                    const result_type &operator()(const descriptor_type &e) const {
                        return e.plugin->lib->path();
                    }
                };
            }    // namespace detail
        }        // namespace plugin
    }            // namespace dbms
}    // namespace nil

#endif    // DBMS_PATH_HPP
