#include <COLA.hh>
#include <ExModule.hh>
#include <gtest/gtest.h>

#include <sstream>
#include <string>

TEST(ExModuleTest, ModuleExposesNamedFactories) {
  cola::ExampleModule module;
  cola::FactoryMap factories = module.GetModuleFilters();

  ASSERT_TRUE(factories.contains("example_generator"));
  ASSERT_TRUE(factories.contains("example_converter"));
  ASSERT_TRUE(factories.contains("example_writer"));
}

TEST(ExModuleTest, ParseAndRunMinimalPipeline) {
  const std::string xml = R"(<?xml version="1.0"?>
<program>
    <generator name="example_generator"/>
    <converter name="example_converter"/>
    <writer name="example_writer"/>
</program>
)";

  cola::ExampleModule module;
  cola::MetaProcessor processor(module.GetModuleFilters());
  std::istringstream stream(xml);
  cola::FilterEnsemble ensemble = processor.Parse(stream);
  cola::ColaRunManager manager(std::move(ensemble));
  manager.Run(1);
}

TEST(ExModuleTest, GeneratorProducesParticle) {
  cola::ExampleModule module;
  cola::MetaProcessor processor(module.GetModuleFilters());
  std::istringstream stream(R"(<?xml version="1.0"?>
<program>
    <generator name="example_generator"/>
    <converter name="example_converter"/>
    <writer name="example_writer"/>
</program>
)");
  cola::FilterEnsemble ensemble = processor.Parse(stream);
  ASSERT_NE(ensemble.generator, nullptr);
  auto event = (*ensemble.generator)();
  ASSERT_NE(event, nullptr);
  ASSERT_EQ(event->particles.size(), 1u);
}
