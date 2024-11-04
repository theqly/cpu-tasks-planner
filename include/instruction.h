#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <vector>

class instruction {
private:
    const int _id;
    const int _num_allowed_modules;
    std::vector<int> _allowed_modules;
public:
    instruction(int id, const std::vector<int>& allowed_modules);

    bool is_runnable_on_module(int module);

    int get_id();
    int get_num_allowed_modules();
    std::vector<int> get_allowed_modules();

};

#endif //INSTRUCTION_H
