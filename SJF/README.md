<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" href="README.css">
</head>
<body>

<h1 style="text-align: center;">
  <img 
    src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&pause=1000&color=ffffff&center=true&vCenter=true&width=650&lines=Non-Preemptive+SJF+CPU+Scheduling"
    alt="Shortest Job First (SJF) CPU Scheduling"
  />
</h1>

<p>
A console-based simulation of the <strong>Non-Preemptive Shortest Job First (SJF)</strong>
CPU scheduling algorithm, written in modern <strong>C++</strong>, with a clean separation
between <strong>UI (Dashboard)</strong> and <strong>Scheduling Logic</strong>.
</p>

<p style="text-align: center;">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/CPU_Scheduling-SJF-0ea5e9?style=for-the-badge" alt="SJF"/>
  <img src="https://img.shields.io/badge/Type-Non--Preemptive-22c55e?style=for-the-badge" alt="Non Preemptive"/>
  <img src="https://img.shields.io/badge/Domain-Operating_Systems-f97316?style=for-the-badge" alt="OS"/>
  <img src="https://img.shields.io/badge/License-MIT-success?style=for-the-badge" alt="License"/>
</p>

<h2>What This Project Does</h2>

<ul>
    <li>Accepts multiple processes with arrival time and burst time</li>
    <li>Schedules them using <strong>Non-Preemptive SJF</strong></li>
    <li>Displays a readable <strong>Gantt Chart</strong></li>
    <li>Computes:
        <ul>
            <li>Completion Time</li>
            <li>Waiting Time</li>
            <li>Turnaround Time</li>
            <li>Average Waiting Time</li>
        </ul>
    </li>
    <li>Fully menu-driven and interactive</li>
</ul>

<h2>Project Structure</h2>

<pre>
SJF/
│
├── main.cpp              → Program entry point
├── menu.h / menu.cpp     → Dashboard (UI + user interaction)
├── SJF.h / SJF.cpp       → Core scheduling logic
</pre>

<h2>Design Philosophy</h2>

<div class="card">
    <h3>Separation of Concerns</h3>
    <ul>
        <li><strong>Dashboard</strong> handles all input/output</li>
        <li><strong>Processes</strong> handles scheduling & metrics</li>
        <li>No I/O inside scheduling logic</li>
    </ul>
</div>

<div class="card">
    <h3>Implicit Scheduling</h3>
    <p>
        The scheduler is not run explicitly by the user.
        Scheduling is triggered internally when:
    </p>
    <ul>
        <li>Gantt Chart is displayed</li>
        <li>Average Waiting Time is requested</li>
    </ul>
</div>

<h2>Sample Input</h2>

<pre>
ID    Arrival   Burst
001   0         20
002   2         5
003   6         2
</pre>

<h2>Sample Output</h2>

<pre>
Gantt Chart:
| 001 | 003 | 002 |
0     20    22    27

Process Execution Details:
ID    Arrival Burst Start Completion Waiting Turnaround
001   0       20    0     20          0       20
003   6       2     20    22          14      16
002   2       5     22    27          20      25
</pre>

<h2>Compilation & Execution</h2>

<pre>
g++ *.cpp -o sjf
./sjf
</pre>

<p>
Compile from the directory containing all .cpp  files.
</p>

<h2>Features Implemented</h2>

<ul>
    <li>CRUD operations on processes</li>
    <li>Non-preemptive SJF scheduling</li>
    <li>Gantt chart visualization</li>
    <li>Average waiting time calculation</li>
    <li>Clean formatting & validation</li>
</ul>

<footer>
    <p>
        Built as a learning project for Operating Systems and C++ fundamentals.<br>
        Designed with modularity and clarity in mind.
    </p>
</footer>

</body>
</html>
