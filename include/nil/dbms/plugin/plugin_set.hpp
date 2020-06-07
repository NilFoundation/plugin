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

#ifndef DBMS_PLUGIN_CONTAINER_HPP
#define DBMS_PLUGIN_CONTAINER_HPP

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/composite_key.hpp>

#include <nil/dbms/plugin/descriptor.hpp>

#include <nil/dbms/plugin/detail/extractors.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            template<typename PluginType>
            using plugin_set = boost::multi_index::multi_index_container<
                descriptor<PluginType>,
                boost::multi_index::indexed_by<
                    boost::multi_index::ordered_unique<detail::id_extractor<descriptor<PluginType>>>,
                    boost::multi_index::ordered_non_unique<detail::name_extractor<descriptor<PluginType>>>>>;
        }    // namespace plugin
    }        // namespace dbms
}    // namespace nil

#endif    // DBMS_SCANNER_HPP
