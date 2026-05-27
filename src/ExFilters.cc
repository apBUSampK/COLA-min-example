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
      .ini_state =
          cola::EventIniState{
              .pdg_code_a = 2212,
              .pdg_code_b = 2212,
              .pz_a = 10.0,
              .pz_b = -10.0,
              .energy = 2000.0,
              .sect_nn = 34.5F,
              .b = 0.1F,
              .num_coll = 1,
              .num_coll_pp = 1,
              .num_coll_pn = 0,
              .num_coll_nn = 0,
              .num_part = 0,
              .num_part_a = 1,
              .num_part_b = 0,
              .phi_rot_a = 1.0F,
              .theta_rot_a = 0.0F,
              .phi_rot_b = 1.0F,
              .theta_rot_b = 0.0F,
              .ini_state_particles = {},
          },
      .particles =
          cola::EventParticles{
              cola::Particle{
                  .position = cola::LorentzVector{.e = 0.0, .x = 0.0, .y = 0.0, .z = 0.0},
                  .momentum = cola::LorentzVector{.e = 0.0, .x = 1.0, .y = 1.0, .z = 1.0},
                  .pdg_code = 0,
                  .p_class = cola::ParticleClass::kProduced,
              },
          },
  });
}

std::unique_ptr<cola::EventData> ExConverter::operator()(std::unique_ptr<cola::EventData>&& data) {
  return std::move(data);
}

void ExWriter::operator()(std::unique_ptr<cola::EventData>&& data) { std::cout << data->particles[0]; }
