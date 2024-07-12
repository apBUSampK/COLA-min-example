//
// Created by apbus_amp_k on 05.07.23.
//

#include "ExFilters.hh"

std::ostream& operator<<(std::ostream& out, const cola::Particle& data){
    return out << data.x << ", " << data.y << ", " << data.z << '\n'
               << data.pX << ", " << data.pY << ", " << data.pZ << std::endl;
}

std::unique_ptr<cola::EventData> ExGenerator::operator()() {
    return std::unique_ptr<cola::EventData>( new cola::EventData{
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
    } );
}

std::unique_ptr<cola::EventData> ExConverter::operator()(std::unique_ptr<cola::EventData>&& data) {
    return std::move(data);
}

void ExWriter::operator()(std::unique_ptr<cola::EventData>&& data) {
    std::cout << data->particles[0];
}