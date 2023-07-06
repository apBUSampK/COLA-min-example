//
// Created by apbus_amp_k on 05.07.23.
//

#ifndef COLA_MIN_EXAMPLE_EXFILTERS_HH
#define COLA_MIN_EXAMPLE_EXFILTERS_HH

#include <iostream>

#include "COLA.hh"

std::ostream& operator<<(std::ostream& out, const cola::Particle& data);

class ExGenerator final: public cola::VGenerator {
public:
    cola::EventData operator()() final;

};

class ExConverter final: public cola::VConverter {
public:
    cola::EventData operator()(cola::EventData data) final;

};

class ExWriter final: public cola::VWriter {
public:
    void operator()(cola::EventData data) final;

};

#endif //COLA_MIN_EXAMPLE_EXFILTERS_HH
