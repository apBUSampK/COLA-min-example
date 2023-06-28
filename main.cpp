#include <iostream>
#include "COLA.hh"

std::ostream& operator<<(std::ostream& out, const cola::Particle& data){
    return out << data.x << ", " << data.y << ", " << data.z << '\n'
               << data.pX << ", " << data.pY << ", " << data.pZ << std::endl;
}

class ExGenerator final: public cola::VGenerator {

    cola::EventData operator()() final {
        return cola::EventData{
            cola::EventIniState{
                2212, 2212,
                10, -10, 2000,
                34.5, .1,
                1, 1, 0, 0, 0, 0,
                0, 1, 0, 1
            },
            cola::EventParticles {
                cola::Particle{
                    0, 0, 0,
                    1, 1, 1
                }
            }
        };
    }

};

class ExConverter final: public cola::VConverter {

    cola::EventData operator()(cola::EventData data) final {
        return data;
    }

};

class ExWriter final: public cola::VWriter {

    void operator()(cola::EventData data) final {
        std::cout << data.particles[0];
    }

};

class ExGFactory final: public cola::VFactory {

    cola::VFilter* create() final {
        return new ExGenerator;
    }

};

class ExCFactory final: public cola::VFactory {

    cola::VFilter* create() final {
        return new ExConverter;
    }

};

class ExWFactory final: public cola::VFactory {

    cola::VFilter* create() final {
        return new ExWriter;
    }

};

int main() {
    cola::MetaProcessor metaProcessor;
    metaProcessor.reg(std::shared_ptr<cola::VFactory>(new ExGFactory), "example_gen", "generator");
    metaProcessor.reg(std::shared_ptr<cola::VFactory>(new ExCFactory), "example_converter", "converter");
    metaProcessor.reg(std::shared_ptr<cola::VFactory>(new ExWFactory), "example_writer", "writer");
    cola::ColaRunManager manager(metaProcessor.parse(cola::MetaData{"example_gen",
                                                                    "example_converter",
                                                                    "example_writer"}));
    manager.run();
    return 0;
}
