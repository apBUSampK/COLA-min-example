//
// Created by apbus_amp_k on 05.07.23.
//

#include <memory>

#include "ExFilters.hh"

std::ostream& operator<<(std::ostream& out, const cola::Particle& data){
    return out << data.position.x << ", " << data.position.y << ", " << data.position.z << '\n'
               << data.position.x << ", " << data.position.y << ", " << data.position.z << std::endl;
}

std::unique_ptr<cola::EventData> ExGenerator::operator()() {
    return std::make_unique<cola::EventData>( cola::EventData{
            cola::EventIniState{
                    2212, 2212,
                    10, -10, 2000,
                    34.5, .1,
                    1, 1, 0, 0, 0, 0,
                    0, 1, 0, 1
            },
            cola::EventParticles {
                    cola::Particle{
                            0, 0, 0, 0,
                            0, 1, 1, 1
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