#ifndef MENU_H
#define MENU_H

#include "SJF.h"

class Dashboard {
    public:
        void menu();
    private:
        Processes scheduler;
        void addProcess();
        void deleteProcess();
        void listInputProcesses();
        void clearAllProcesses();
        void displaySchdeulingChart();
        void showAverageWaitingTime();
};

#endif