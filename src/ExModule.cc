#include "ExModule.hh"

extern "C" cola::VModule* LoadCOLAModule() { return new cola::ExampleModule(); }
