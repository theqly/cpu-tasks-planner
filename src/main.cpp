#include "scheduler.h"
#include <iostream>

int main(int argc, char** argv) {

    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <path to file>" << std::endl;
        return -1;
    }

    ctp::scheduler sched;

    sched.load_data(argv[1]);

    sched.set_scheduling_strategy(ctp::optimal);

    sched.schedule_instructions();

    sched.print_schedule();

    return 0;
}
