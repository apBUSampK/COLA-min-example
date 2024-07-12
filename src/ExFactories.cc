//
// Created by apbus_amp_k on 05.07.23.
//

#include "ExFactories.hh"

cola::VFilter* ExGFactory::create(const std::map<std::string, std::string>&) {
    return new ExGenerator;
}

cola::VFilter* ExCFactory::create(const std::map<std::string, std::string>&) {
    return new ExConverter;
}

cola::VFilter* ExWFactory::create(const std::map<std::string, std::string>&) {
    return new ExWriter;
}