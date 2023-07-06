#include <iostream>

#include "ExModule.hh"

int main() {
    // Create MetaProcessor and register needed filters (dependency injection)
    cola::MetaProcessor metaProcessor;
    metaProcessor.reg(std::shared_ptr<cola::VFactory>(new ExGFactory), "example_gen", "generator");
    metaProcessor.reg(std::shared_ptr<cola::VFactory>(new ExCFactory), "example_converter", "converter");
    metaProcessor.reg(std::shared_ptr<cola::VFactory>(new ExWFactory), "example_writer", "writer");

    // Assemble manager and run
    cola::ColaRunManager manager(metaProcessor.parse(cola::MetaData{"example_gen",
                                                                    "example_converter",
                                                                    "example_writer"}));
    manager.run();
    return 0;
}
