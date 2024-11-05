#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <instruction.h>
#include <string>

namespace ctp {

enum scheduling_strategy {
  greedy,
  optimal,
};

class scheduler {
private:
  scheduling_strategy _strategy;

  int _num_modules;
  int _num_instructions;

  std::vector<bool> _module_used;
  std::vector<instruction> _instructions;
  std::vector<std::pair<int, int>> _schedule;

  void greedy_schedule_instructions();

  void optimal_schedule_instructions();
  //maybe not the best architectural solution
  void dfs(int index, std::vector<std::pair<int, int>> &cur_schedule, std::vector<std::pair<int, int>> &best_schedule);

public:
  scheduler();

  void load_data(const std::string& filename);

  void schedule_instructions();

  void set_scheduling_strategy(const scheduling_strategy& strategy);

  [[nodiscard]] std::vector<std::pair<int, int>> get_schedule() const;

  void print_schedule() const;
};

}



#endif //SCHEDULER_H
