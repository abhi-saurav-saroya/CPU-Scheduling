<h1 align="center">
  <img 
    src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&pause=1000&color=ffffff&center=true&vCenter=true&width=650&lines=Non-Preemptive+FCFS+CPU+Scheduling"
    alt="First Come First Serve (FCFS) CPU Scheduling"
  />
</h1>

> A console-based simulation of the **Non-Preemptive First Come First Serve (FCFS)** CPU scheduling algorithm, written in modern **C++**, with a clean separation between UI (Dashboard) and Scheduling Logic.

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/CPU_Scheduling-FCFS-0ea5e9?style=for-the-badge" alt="FCFS"/>
</p>
<p align="center">
  <img src="https://img.shields.io/badge/Type-Non--Preemptive-22c55e?style=for-the-badge" alt="Non Preemptive"/>
  <img src="https://img.shields.io/badge/Domain-Operating_Systems-f97316?style=for-the-badge" alt="OS"/>
</p>
<p align="center">
  <img src="https://img.shields.io/badge/License-MIT-success?style=for-the-badge" alt="License"/>
</p>

## What This Project Does
- Accepts multiple processes with arrival time and burst time
- Schedules them using **Non-Preemptive FCFS**
- Displays a readable **Gantt Chart**
- Computes:
    - Completion Time
    - Waiting Time
    - Turnaround Time
    - Average Waiting Time
- Fully menu-driven and interactive

## FCFS Directory Structure
```bash
FCFS/
  │
  ├── main.cpp              → Program entry point
  ├── menu.h / menu.cpp     → Dashboard (UI + user interaction)
  ├── FCFS.h / FCFS.cpp     → Core scheduling logic
```


## Design Philosophy

<h3 align="center"> Separation of Concerns </h3>

- **Dashboard** handles all input/output
- **Processes** handles scheduling & metrics
- No I/O inside scheduling logic

<h3 align="center">Implicit Scheduling</h3>
The scheduler is not run explicitly by the user. Scheduling is triggered internally when:

- Gantt Chart is displayed
- Average Waiting Time is requested

## Sample Input

```
ID    Arrival   Burst
001   0         20
002   2         5
003   6         2
```

## Sample Output
```
Gantt Chart:
| 001 | 002 | 003 |
0     20    25    27


Process Execution Details:
ID    Arrival Burst Start Completion Waiting Turnaround
001   0       20    0     20          0       20
002   2       5     20    25          18      23
003   6       2     25    27          19      21
```

## Compilation & Execution
```
g++ *.cpp -o FCFS
.\FCFS
```
> NOTE: Compile from the directory containing all .cpp  files.

## Features Implemented

- CRUD operations on processes
- Non-preemptive FCFS scheduling
- Gantt chart visualization
- Average waiting time calculation
- Clean formatting & validation

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer" alt="Footer"/>

<i>Built as a learning project for Operating Systems and C++ fundamentals. Designed with modularity and clarity in mind.</i>


---

**© 2026 Open Source Project | FCFS Scheduling Simulation | MIT License**