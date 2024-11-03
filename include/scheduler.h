#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <instruction.h>
#include <string>

class scheduler {
private:
    int _num_modules;
    int _num_instructions;

    std::vector<bool> _module_used;
    std::vector<instruction> _instructions;
    std::vector<std::pair<int, int>> _schedule;

public:
    scheduler();

    void load_data(const std::string& filename);

    void schedule_instructions();

    std::vector<std::pair<int, int>> get_schedule();
};

#endif //SCHEDULER_H
