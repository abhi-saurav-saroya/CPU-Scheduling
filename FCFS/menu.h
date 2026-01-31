#ifndef MENU_H
#define MENU_H

#include "FCFS.h"

class Dashboard {
    public:
        void menu();
    private:
        Processes scheduler;
        void addProcess();
        void deleteProcess();
        void listInputProcesses();
        void clearAllProcesses();
        void displaySchedulingChart();
        void showAverageWaitingTime();
};

#endif