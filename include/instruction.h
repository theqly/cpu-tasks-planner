#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <vector>

namespace ctp {

class instruction {
private:
  int _id;
  std::vector<int> _allowed_modules;
public:
  instruction(int id, std::vector<int>&& allowed_modules);
  instruction(instruction&& other) noexcept;

  instruction& operator=(instruction&& other) noexcept;

  bool is_runnable_on_module(int module);

  [[nodiscard]] int get_id() const;
  [[nodiscard]] int get_num_allowed_modules() const;
  [[nodiscard]] std::vector<int> get_allowed_modules() const;

};

}



#endif //INSTRUCTION_H
