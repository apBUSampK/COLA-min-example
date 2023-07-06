//
// Created by apbus_amp_k on 05.07.23.
//

#include "ExFactories.hh"

cola::VFilter* ExGFactory::create() {
    return new ExGenerator;
}

cola::VFilter* ExCFactory::create() {
    return new ExConverter;
}

cola::VFilter* ExWFactory::create() {
    return new ExWriter;
}