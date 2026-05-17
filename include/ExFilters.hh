//
// Created by apbus_amp_k on 05.07.23.
//

#ifndef COLA_MIN_EXAMPLE_EXFILTERS_HH
#define COLA_MIN_EXAMPLE_EXFILTERS_HH

#include <COLA.hh>

#include <iostream>
#include <memory>
#include <string>

std::ostream& operator<<(std::ostream& out, const cola::Particle& data);

class ExGenerator final : public cola::VGenerator {
 public:
  static inline const std::string kName = "example_gen";

  std::unique_ptr<cola::EventData> operator()() override;
};

class ExConverter final : public cola::VConverter {
 public:
  static inline const std::string kName = "example_converter";

  std::unique_ptr<cola::EventData> operator()(std::unique_ptr<cola::EventData>&& data) override;
};

class ExWriter final : public cola::VWriter {
 public:
  static inline const std::string kName = "example_writer";

  void operator()(std::unique_ptr<cola::EventData>&& data) override;
};

#endif  // COLA_MIN_EXAMPLE_EXFILTERS_HH
