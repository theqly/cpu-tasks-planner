#include "scheduler.h"

#include <fstream>

scheduler::scheduler() : _num_modules(0), _num_instructions(0) {}

void scheduler::load_data(const std::string &filename) {
    std::ifstream in(filename);
    if(!in) throw std::runtime_error("failed to open file  " + filename);

    in >> _num_modules >> _num_instructions;

    _module_used.reserve(_num_modules);
    _instructions.reserve(_num_instructions);
    _schedule.reserve(_num_instructions);

    for(int i = 0; i != _num_instructions; ++i) {
        int module;
        std::vector<int> allowed_modules;

        while(in >> module) {
            allowed_modules.push_back(module);
            if(in.peek() == '\n') break;
        }
        _instructions.emplace_back(i, allowed_modules);
    }

}




