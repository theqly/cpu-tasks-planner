#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <vector>

class instruction {
private:
    const int _id;
    std::vector<int> _allowed_modules;
public:
    instruction(int id, const std::vector<int>& allowed_modules);

    bool is_runnable_on_module(int module);

    int get_id();

    std::vector<int> get_allowed_modules();

};

#endif //INSTRUCTION_H
