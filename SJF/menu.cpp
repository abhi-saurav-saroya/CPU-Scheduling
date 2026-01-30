#include "menu.h"

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

void Dashboard::menu() {
    while(true) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        std::cout << std::endl;
        std::cout << "\t1. Add Process." << std::endl;
        std::cout << "\t2. Delete Process." << std::endl;
        std::cout << "\t3. List Input Processes." << std::endl;
        std::cout << "\t4. Clear All Processes." << std::endl;
        std::cout << "\t5. Display Scheduling Chart." << std::endl;
        std::cout << "\t6. Show Average Waiting Time." << std::endl;
        std::cout << "\t7. Exit." << std::endl;
        std::cout << "CHOOSE THE OPTION: ";
    
        int menuChoice;
    
        while(true) {
            std::cin >> menuChoice;
    
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again." << std::endl;
                continue;
            }
    
            if(menuChoice < 1 || menuChoice > 7) {
                std::cout << "Enter a valid option in range [1,7]: ";
                continue;
            }
    
            break;
        }
    
        switch(menuChoice) {
            case 1:
                addProcess();
                break;
            case 2:
                deleteProcess();
                break;
            case 3: 
                listInputProcesses();
                break;
            case 4:
                clearAllProcesses();
                break;
            case 5:
                displaySchdeulingChart();
                break;
            case 6:
                showAverageWaitingTime();
                break;
            case 7:
                return;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

void Dashboard::addProcess() {
    std::cout << "ENTER THE DETAILS OF PROCESSES TO ADD:" << std::endl;
    std::string processID;
    int arrivalTime, burstTime;

    std::cout << "Enter the Process ID: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, processID);


    std::cout << "Enter the arrival time: ";
    while(true) {
        std::cin >> arrivalTime;

        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }

        if (arrivalTime < 0) {
            std::cout << "Arrival time must be non-negative.\n";
            continue;
        }

        break;
    }

    std::cout << "Enter the burst time: ";
    while(true) {
        std::cin >> burstTime;

        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }

        if (burstTime <= 0) {
            std::cout << "Burst time must be greater than 0.\n";
            continue;
        }

        break;
    }

    if(scheduler.addProcess({processID, arrivalTime, burstTime}))
        std::cout << "The process added successfully." <<std::endl;
    else
        std::cout << "An error occurred while adding the process." << std::endl;
}

void Dashboard::deleteProcess() {
    std::string processID;

    std::cout << "Enter the Process ID: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, processID);
    
    if(scheduler.deleteProcess(processID))
        std::cout << "Process '" << processID << "' deleted successfully.\n";
    else
        std::cout << "Process '" << processID << "' not found.\n";
}

void Dashboard::listInputProcesses() {
    const auto& processes = scheduler.getProcesses();

    if (processes.empty()) {
        std::cout << "No processes have been added yet." << std::endl;
        return;
    }

    std::cout << std::endl << "Current Input Processes:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "ID\tArrival\tBurst" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    for (const auto& p : processes) {
        std::cout << p.processID << "\t" << p.arrivalTime << "\t" << p.burstTime << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;
}

void Dashboard::clearAllProcesses() {
    if(scheduler.clearAllProcesses())
        std::cout << "All processes cleared successfully." << std::endl;
    else
        std::cout << "An error occurred while clearing all processes." << std::endl;
}

void Dashboard::showAverageWaitingTime() {
    const auto& processes = scheduler.getProcesses();

    if (processes.empty()) {
        std::cout << "No processes have been added yet." << std::endl;
        return;
    }

    bool isScheduled = false;
    for (const auto& p : processes) {
        if (p.completed) {
            isScheduled = true;
            break;
        }
    }

    if (!isScheduled) {
        std::cout << "Please schedule the processes first using option 5." << std::endl;
        return;
    }

    std::cout << "Average Waiting Time: " << scheduler.computeAverageWaitingTime() << " units." << std::endl;
}

void Dashboard::displaySchdeulingChart() {
    auto& processes = scheduler.getProcesses();

    if (processes.empty()) {
        std::cout << "No processes have been added yet." << std::endl;
        return;
    }

    if (!scheduler.scheduleSJF()) {
        std::cout << "Error scheduling processes." << std::endl;
        return;
    }

    std::cout << std::endl << "Schdeuling Chart:" << std::endl;

    std::cout << std::endl << "Process Details:" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "ID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    for (const auto& p : processes) {
        std::cout << p.processID << "\t"
                  << p.arrivalTime << "\t"
                  << p.burstTime << "\t"
                  << p.completionTime << "\t"
                  << p.waitingTime << "\t"
                  << p.turnaroundTime << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;
}
