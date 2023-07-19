//
// Created by apbus_amp_k on 05.07.23.
//

#ifndef COLA_MIN_EXAMPLE_EXFILTERS_HH
#define COLA_MIN_EXAMPLE_EXFILTERS_HH

#include <iostream>
#include <memory>

#include "COLA.hh"

std::ostream& operator<<(std::ostream& out, const cola::Particle& data);

class ExGenerator final: public cola::VGenerator {
public:
    std::unique_ptr<cola::EventData> operator()() final;

};

class ExConverter final: public cola::VConverter {
public:
    std::unique_ptr<cola::EventData> operator()(std::unique_ptr<cola::EventData> data) final;

};

class ExWriter final: public cola::VWriter {
public:
    void operator()(std::unique_ptr<cola::EventData> data) final;

};

#endif //COLA_MIN_EXAMPLE_EXFILTERS_HH
