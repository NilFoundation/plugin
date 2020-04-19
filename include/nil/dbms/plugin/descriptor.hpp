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

#ifndef DBMS_PLUGIN_DESCRIPTION_HPP
#define DBMS_PLUGIN_DESCRIPTION_HPP

#include <string>

#include <boost/dll.hpp>
#include <boost/filesystem.hpp>

namespace nil::dbms::plugin {
    struct descriptor {
        boost::filesystem::path path;
        boost::dll::shared_library lib;
    };
}    // namespace nil::dbms::plugin

#endif    // DBMS_DESCRIPTION_HPP
