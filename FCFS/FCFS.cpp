#include "FCFS.h"

#include <vector>
#include <limits>
#include <algorithm>

bool Processes::addProcess(Process p) {
    if(processIDExists(p.processID))
        return false;
    
    processesList.push_back(p);
    return true;
}

bool Processes::deleteProcess(const std::string& processID) {
    for (int i = 0; i < processesList.size(); i++) {
        if (processesList[i].processID == processID) {
            processesList.erase(processesList.begin() + i);
            return true;
        }
    }
    
    return false;
}

bool Processes::clearAllProcesses() {
    if (processesList.empty())
        return false;

    processesList.clear();
    return true;
}

bool Processes::scheduleFCFS() {
    if (processesList.empty())
        return false;

    // Sort processes by arrival time
    sort(processesList.begin(), processesList.end(),
         [](const Process& a, const Process& b) {
             return a.arrivalTime < b.arrivalTime;
         });

    int currentTime = 0;

    for (int i = 0; i < processesList.size(); i++) {
        Process& p = processesList[i];

        // CPU idle time handling
        if (currentTime < p.arrivalTime)
            currentTime = p.arrivalTime;

        p.waitingTime = currentTime - p.arrivalTime;
        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.completed = true;

        currentTime = p.completionTime;
    }

    return true;
}

float Processes::computeAverageWaitingTime() {
    if (processesList.empty())
        return 0.0f;

    int totalWaitingTime = 0;
    int count = 0;

    for (int i = 0; i < processesList.size(); i++) {
        // Only include processes that have been scheduled
        if (processesList[i].completed) {
            totalWaitingTime += processesList[i].waitingTime;
            count++;
        }
    }

    if (count == 0)
        return 0.0f;

    return static_cast<float> (totalWaitingTime) / count;
}


// HELPERS
const std::vector<Process>& Processes::getProcesses() const {
    return processesList;
}

bool Processes::processIDExists(const std::string& processID) const {
    for (int i = 0; i < processesList.size(); i++) {
        if (processesList[i].processID == processID) {
            return true;
        }
    }
    return false;
}