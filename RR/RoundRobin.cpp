#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;

    Process(int id, int a, int b) {
        pid = id;
        arrivalTime = a;
        burstTime = b;
        remainingTime = b;
        completionTime = 0;
    }
};

int main() {
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    Process* p[n];

    cout << "\nEnter Arrival Time and Burst Time:\n";
    for (int i = 0; i < n; i++) {
        int at, bt;
        cout << "P" << i + 1 << ": ";
        cin >> at >> bt;
        p[i] = new Process(i + 1, at, bt);
    }

    cout << "\nEnter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    vector<int> ganttPID;
    vector<int> ganttTime;

    int time = 0, completed = 0;
    bool inQueue[n] = {false};

    time = p[0]->arrivalTime;
    q.push(0);
    inQueue[0] = true;
    ganttTime.push_back(time);

    while (completed < n) {
        if (q.empty()) {
            time++;
            ganttTime.push_back(time);
            ganttPID.push_back(-1); // CPU Idle
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] &&
                    p[i]->arrivalTime <= time &&
                    p[i]->remainingTime > 0) {
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
            continue;
        }

        int idx = q.front();
        q.pop();

        ganttPID.push_back(p[idx]->pid);

        int exec = min(p[idx]->remainingTime, tq);
        p[idx]->remainingTime -= exec;
        time += exec;
        ganttTime.push_back(time);

        for (int i = 0; i < n; i++) {
            if (!inQueue[i] &&
                p[i]->arrivalTime <= time &&
                p[i]->remainingTime > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p[idx]->remainingTime > 0) {
            q.push(idx);
        } else {
            p[idx]->completionTime = time;
            completed++;
        }
    }

    cout << "\nGantt Chart:\n|";
    for (int i = 0; i < ganttPID.size(); i++) {
        if (ganttPID[i] == -1)
            cout << " IDLE |";
        else
            cout << " P" << ganttPID[i] << " |";
    }

    cout << "\n";
    for (int i = 0; i < ganttTime.size(); i++) {
        cout << ganttTime[i] << "    ";
    }
    cout << "\n";

    // ---------- TABLE ----------
    cout << "\nProcess ID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        int turnaroundTime = p[i]->completionTime - p[i]->arrivalTime;
        int waitingTime = turnaroundTime - p[i]->burstTime;

        cout << "P" << p[i]->pid << "\t\t"
             << p[i]->arrivalTime << "\t"
             << p[i]->burstTime << "\t"
             << p[i]->completionTime << "\t\t"
             << turnaroundTime << "\t\t"
             << waitingTime << endl;
    }

    return 0;
}
