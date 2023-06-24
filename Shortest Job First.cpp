#include <iostream>
#include <algorithm>
#include <vector>

struct Process {
    int id;
    int burst_time;
};

bool compare(Process p1, Process p2) {
    return p1.burst_time < p2.burst_time;
}

void sjf(std::vector<Process>& processes) {
    int n = processes.size();
    
    // Sort the processes based on burst time
    std::sort(processes.begin(), processes.end(), compare);

    // Initialize waiting time and turnaround time arrays
    std::vector<int> waiting_time(n, 0);
    std::vector<int> turnaround_time(n, 0);

    // Calculate waiting time and turnaround time for each process
    for (int i = 1; i < n; i++) {
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1];
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    // Calculate average waiting time and average turnaround time
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    double avg_waiting_time = total_waiting_time / n;
    double avg_turnaround_time = total_turnaround_time / n;

    // Print the result
    std::cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        std::cout << processes[i].id << "\t" << processes[i].burst_time << "\t\t"
                  << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
    }
    std::cout << "Average Waiting Time: " << avg_waiting_time << "\n";
    std::cout << "Average Turnaround Time: " << avg_turnaround_time << "\n";
}

int main() {
    std::vector<Process> processes;
    processes.push_back({1, 6});
    processes.push_back({2, 8});
    processes.push_back({3, 7});
    processes.push_back({4, 3});

    sjf(processes);

    return 0;
} 

