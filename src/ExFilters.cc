//
// Created by apbus_amp_k on 05.07.23.
//

#include "ExFilters.hh"

std::ostream& operator<<(std::ostream& out, const cola::Particle& data){
    return out << data.x << ", " << data.y << ", " << data.z << '\n'
               << data.pX << ", " << data.pY << ", " << data.pZ << std::endl;
}

cola::EventData ExGenerator::operator()() {
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

cola::EventData ExConverter::operator()(cola::EventData data) {
    return data;
}

void ExWriter::operator()(cola::EventData data) {
    std::cout << data.particles[0];
}