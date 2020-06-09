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

#ifndef DBMS_INITIALIZABLE_HPP
#define DBMS_INITIALIZABLE_HPP

namespace nil {
    namespace dbms {
        struct BOOST_SYMBOL_VISIBLE initializable {
            enum state_type {
                registered,     ///< the plugin is constructed but doesn't do anything
                initialized,    ///< the plugin has initialized any state required but is idle
                started,        ///< the plugin is actively running
                stopped         ///< the plugin is no longer running
            };

            virtual state_type get_state() const = 0;

            virtual void handle_sighup() = 0;

            virtual void startup() = 0;
            virtual void shutdown() = 0;
        };
    }    // namespace dbms
}    // namespace nil

#endif    // DBMS_INITIALIZABLE_HPP
