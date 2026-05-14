/**
 * Copyright (c) 2024-2025 Alexandr Svetlichnyi, Savva Savenkov, Artemii Novikov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <COLA.hh>
#include <ExModule.hh>

#include <iostream>
#include <string>

#ifndef EXMODULE_DEFAULT_CONFIG
#define EXMODULE_DEFAULT_CONFIG ""
#endif

int main(int argc, char** argv) {
  std::string config_path = EXMODULE_DEFAULT_CONFIG;
  if (argc > 1) {
    config_path = argv[1];
  }

  if (config_path.empty()) {
    throw std::runtime_error("usage: " + std::string(argv[0]) + " <config.xml>");
  }

  cola::ExampleModule module;
  cola::MetaProcessor processor(module.GetModuleFilters());
  cola::ColaRunManager manager(processor.Parse(config_path));

  manager.Run();
}
