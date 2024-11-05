#include "scheduler.h"
#include <iostream>

int main() {
    ctp::scheduler sched;

    sched.load_data("file.txt");

    sched.set_scheduling_strategy(ctp::optimal);

    sched.schedule_instructions();

    sched.print_schedule();

    return 0;
}
