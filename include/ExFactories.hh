//
// Created by apbus_amp_k on 05.07.23.
//

#ifndef COLA_MIN_EXAMPLE_EXFACTORIES_HH
#define COLA_MIN_EXAMPLE_EXFACTORIES_HH

#include <string>

#include "ExFilters.hh"
#include "COLA.hh"

class ExGFactory final: public cola::VFactory {
public:
    cola::VFilter* create(const std::map<std::string, std::string>&) final;

};

class ExCFactory final: public cola::VFactory {
public:
    cola::VFilter* create(const std::map<std::string, std::string>&) final;

};

class ExWFactory final: public cola::VFactory {
public:
    cola::VFilter* create(const std::map<std::string, std::string>&) final;

};

#endif //COLA_MIN_EXAMPLE_EXFACTORIES_HH
