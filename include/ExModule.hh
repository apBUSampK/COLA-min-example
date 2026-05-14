#ifndef COLA_MIN_EXAMPLE_EXMODULE_HH
#define COLA_MIN_EXAMPLE_EXMODULE_HH

#include "ExFilters.hh"

#include <COLA.hh>

namespace cola {

  using ExGeneratorFactory = GenericFactory<ExGenerator>;
  using ExConverterFactory = GenericFactory<ExConverter>;
  using ExWriterFactory = GenericFactory<ExWriter>;

  using ExampleModule = GenericModule<ExGeneratorFactory, ExConverterFactory, ExWriterFactory>;

}  // namespace cola

#endif  // COLA_MIN_EXAMPLE_EXMODULE_HH
