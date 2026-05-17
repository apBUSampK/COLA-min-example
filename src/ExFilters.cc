//
// Created by apbus_amp_k on 05.07.23.
//

#include "ExFilters.hh"

#include <memory>

std::ostream& operator<<(std::ostream& out, const cola::Particle& data) {
  return out << data.position.e << ", " << data.position.x << ", " << data.position.y << ", " << data.position.z << '\n'
             << data.momentum.e << ", " << data.momentum.x << ", " << data.momentum.y << ", " << data.momentum.z
             << '\n';
}

std::unique_ptr<cola::EventData> ExGenerator::operator()() {
  return std::make_unique<cola::EventData>(cola::EventData{
      .iniState =
          cola::EventIniState{
              .pdgCodeA = 2212,
              .pdgCodeB = 2212,
              .pZA = 10.0,
              .pZB = -10.0,
              .energy = 2000.0,
              .sectNN = 34.5F,
              .b = 0.1F,
              .nColl = 1,
              .nCollPP = 1,
              .nCollPN = 0,
              .nCollNN = 0,
              .nPart = 0,
              .nPartA = 1,
              .nPartB = 0,
              .phiRotA = 1.0F,
              .thetaRotA = 0.0F,
              .phiRotB = 1.0F,
              .thetaRotB = 0.0F,
              .iniStateParticles = {},
          },
      .particles =
          cola::EventParticles{
              cola::Particle{
                  .position = cola::LorentzVector{.e = 0.0, .x = 0.0, .y = 0.0, .z = 0.0},
                  .momentum = cola::LorentzVector{.e = 0.0, .x = 1.0, .y = 1.0, .z = 1.0},
                  .pdgCode = 0,
                  .pClass = cola::ParticleClass::kProduced,
              },
          },
  });
}

std::unique_ptr<cola::EventData> ExConverter::operator()(std::unique_ptr<cola::EventData>&& data) {
  return std::move(data);
}

void ExWriter::operator()(std::unique_ptr<cola::EventData>&& data) { std::cout << data->particles[0]; }
