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

#include <nil/module/configurable.hpp>
#include <nil/module/initializable.hpp>
#include <nil/module/identifiable.hpp>
#include <nil/module/nameable.hpp>

#include <nil/dbms/plugin/options_description.hpp>
#include <nil/dbms/plugin/variables_map.hpp>

namespace nil {
    namespace dbms {
        namespace plugin {
            /*!
             * @brief
             */
            class BOOST_SYMBOL_VISIBLE basic
                : public module::configurable<variables_map, cli_options_description, cfg_options_description>,
                  public module::initializable,
                  public module::nameable<const char *>,
                  public module::identifiable<uint32_t> {
                typedef module::configurable<variables_map, cli_options_description, cfg_options_description>
                    policy_type;

            public:
                typedef typename module::identifiable<uint32_t>::id_type id_type;
                typedef typename module::nameable<const char *>::name_type name_type;

                typedef typename policy_type::options_types options_type;
                typedef typename policy_type::configuration_type configuration_type;

                typedef typename std::tuple_element<0, options_type>::type cli_options_type;
                typedef typename std::tuple_element<1, options_type>::type cfg_options_type;

                virtual ~basic() {
                }
                virtual state_type state() const override = 0;
                virtual id_type id() const override = 0;
                virtual name_type name() const override = 0;

                virtual void set_options(cli_options_type &cli) const override = 0;
                virtual void set_options(cfg_options_type &cfg) const override = 0;
                virtual void initialize(configuration_type &options) override = 0;

                virtual void handle_sighup() override = 0;
                virtual void startup() override = 0;
                virtual void shutdown() override = 0;
            };
        }    // namespace plugin

    }    // namespace dbms
}    // namespace nil

#endif    // DBMS_PLUGIN_HPP
