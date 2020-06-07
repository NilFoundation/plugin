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

#ifndef DBMS_ABSTRACT_PLUGIN_HPP
#define DBMS_ABSTRACT_PLUGIN_HPP

#include <boost/config.hpp>
#include <boost/application.hpp>
#include <boost/dll.hpp>
#include <boost/program_options.hpp>

#include <nil/dbms/plugin/configurable.hpp>
#include <nil/dbms/plugin/initializable.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            /*!
             * @brief
             */
            struct BOOST_SYMBOL_VISIBLE plugin : public configurable<boost::program_options::options_description,
                                                                     boost::program_options::variables_map>,
                                                 public initializable {
                typedef uint32_t id_type;
                typedef const char *name_type;

                typedef configurable<boost::program_options::options_description, boost::program_options::variables_map>
                    policy_type;

                typedef typename policy_type::options_type options_type;
                typedef typename policy_type::configuration_type configuration_type;

                virtual ~plugin() {
                }
                virtual state get_state() const override = 0;
                virtual id_type id() const = 0;
                virtual name_type name() const = 0;

                virtual void set_options(options_type &cli, options_type &cfg) const override = 0;
                virtual void initialize(configuration_type &options) override = 0;

                virtual void handle_sighup() override = 0;
                virtual void startup() override = 0;
                virtual void shutdown() override = 0;
            };
        }    // namespace plugin

    }    // namespace dbms
}    // namespace nil

#endif    // DBMS_PLUGIN_HPP
