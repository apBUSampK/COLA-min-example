#include <iostream>
#include <memory>

#include "ExModule.hh"

int main() {
    // Create MetaProcessor and register needed filters (dependency injection)
    cola::MetaProcessor metaProcessor;
    metaProcessor.reg(std::unique_ptr<cola::VFactory>(new ExGFactory), "example_gen", cola::FilterType::generator);
    metaProcessor.reg(std::unique_ptr<cola::VFactory>(new ExCFactory), "example_converter", cola::FilterType::converter);
    metaProcessor.reg(std::unique_ptr<cola::VFactory>(new ExWFactory), "example_writer", cola::FilterType::writer);

    // Assemble manager and run
    cola::ColaRunManager manager(metaProcessor.parse("../data/config.xml"));
    manager.run();
    return 0;
}
