#include "instruction.h"

#include <algorithm>

namespace ctp {

instruction::instruction(const int id, std::vector<int> &&allowed_modules)
    : _id(id), _allowed_modules(std::move(allowed_modules)) {}

 instruction::instruction(instruction &&other) noexcept : _id(other._id), _allowed_modules(std::move(other._allowed_modules)) {}


instruction &instruction::operator=(instruction &&other) noexcept {
  if (this != &other) {
    _id = other._id;
    _allowed_modules = std::move(other._allowed_modules);
  }
  return *this;
}

bool instruction::is_runnable_on_module(const int module) {
  return std::find(_allowed_modules.begin(), _allowed_modules.end(), module) !=
         _allowed_modules.end();
}

int instruction::get_id() const { return _id; }

int instruction::get_num_allowed_modules() const {
  return static_cast<int>(_allowed_modules.size());
}

std::vector<int> instruction::get_allowed_modules() const {
  return _allowed_modules;
}

} // namespace ctp