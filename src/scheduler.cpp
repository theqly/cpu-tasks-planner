#include "scheduler.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

namespace ctp {

scheduler::scheduler() : _strategy(greedy), _num_modules(0), _num_instructions(0) {}

void scheduler::load_data(const std::string &filename) {
  std::ifstream in(filename);
  if(!in) throw std::runtime_error("failed to open file  " + filename);

  in >> _num_modules >> _num_instructions;

  in.ignore(100, '\n');

  _module_used.reserve(_num_modules);
  _instructions.reserve(_num_instructions);
  _schedule.reserve(_num_instructions);

  for(int i = 0; i != _num_instructions; ++i) {
    std::vector<int> allowed_modules;
    std::string line;

    if (std::getline(in, line)) {
      std::istringstream ss(line);
      int module;

      while (ss >> module) {
        allowed_modules.push_back(module);
      }
    }

    _instructions.emplace_back(i, std::move(allowed_modules));
  }
}

void scheduler::schedule_instructions() {
  if(_strategy == greedy) {
    greedy_schedule_instructions();
  } else {
    optimal_schedule_instructions();
  }
}

void scheduler::greedy_schedule_instructions() {

  std::fill(_module_used.begin(), _module_used.end(), false);
  _schedule.clear();

  std::sort(_instructions.begin(), _instructions.end(), [](const instruction& lhs, const instruction& rhs) {
    return lhs.get_num_allowed_modules() < rhs.get_num_allowed_modules();
  });

  for ( const auto& instr : _instructions ) {
    for(int module : instr.get_allowed_modules()) {
      if(!_module_used[module]) {
        _module_used[module] = true;
        _schedule.emplace_back(instr.get_id(), module);
        break;
      }
    }
  }

}

void scheduler::optimal_schedule_instructions() {
  //bebebe
}


void scheduler::set_scheduling_strategy(const scheduling_strategy& strategy) { _strategy = strategy; }

std::vector<std::pair<int, int>> scheduler::get_schedule() const { return _schedule; }

void scheduler::print_schedule() const {
  for (const auto &[fst, snd] : _schedule) {
    std::cout << fst << " - " << snd << std::endl;
  }
}


}






