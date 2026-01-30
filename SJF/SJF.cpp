#include "SJF.h"

#include <vector>
#include <limits>

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

bool Processes::scheduleSJF() {
    if (processesList.empty())
        return false;

    // Reset all processes (in case we are re-scheduling)
    for (int i = 0; i < processesList.size(); i++) {
        processesList[i].completed = false;
        processesList[i].completionTime = 0;
        processesList[i].waitingTime = 0;
        processesList[i].turnaroundTime = 0;
    }

    int currentTime = 0;
    int completedCount = 0;
    int n = processesList.size();

    while (completedCount < n) {
        int shortestIndex = -1;
        int minBurst = std::numeric_limits<int>::max();

        // Find process with shortest burst among those that have arrived and not completed
        for (int i = 0; i < n; i++) {
            if (!processesList[i].completed && processesList[i].arrivalTime <= currentTime) {
                if (processesList[i].burstTime < minBurst) {
                    minBurst = processesList[i].burstTime;
                    shortestIndex = i;
                }
                // If burst time is same, pick the one with earlier arrival (optional tie-breaker)
                else if (processesList[i].burstTime == minBurst) {
                    if (processesList[i].arrivalTime < processesList[shortestIndex].arrivalTime)
                        shortestIndex = i;
                }
            }
        }

        if (shortestIndex == -1) {
            // No process has arrived yet, advance time to the next arriving process
            int nextArrival = std::numeric_limits<int>::max();
            for (int i = 0; i < n; i++) {
                if (!processesList[i].completed && processesList[i].arrivalTime < nextArrival) {
                    nextArrival = processesList[i].arrivalTime;
                }
            }
            currentTime = nextArrival;
            continue;
        }

        // Schedule the selected process
        Process &p = processesList[shortestIndex];
        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
        p.completed = true;

        // Move current time forward
        currentTime = p.completionTime;
        completedCount++;
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