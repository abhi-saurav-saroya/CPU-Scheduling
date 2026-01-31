#ifndef FCFS_H
#define FCFS_H

#include <string>
#include <vector>

struct Process {
    std::string processID;
    int arrivalTime;
    int burstTime;

    int completionTime = 0;
    int waitingTime = 0;
    int turnaroundTime = 0;

    bool completed = false;
};


class Processes {
    private:
        std::vector<Process> processesList;
    public:
        // core
        bool addProcess(Process process);
        bool deleteProcess(const std::string& processID);
        bool clearAllProcesses();
        bool scheduleFCFS();
        float computeAverageWaitingTime();

        // helpers
        const std::vector<Process>& getProcesses() const;
        bool processIDExists(const std::string& processID) const;
};

#endif