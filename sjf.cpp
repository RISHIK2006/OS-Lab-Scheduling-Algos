#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid; // Process ID
    int burstTime; // Burst time
};

// Function to sort processes by burst time
void sortProcesses(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burstTime > proc[j + 1].burstTime) {
                // Swap the processes
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process proc[], int n) {
    int waitingTime[n];
    int turnaroundTime[n];

    waitingTime[0] = 0; // First process has no waiting time
    turnaroundTime[0] = proc[0].burstTime;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + proc[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + proc[i].burstTime;
    }

    // Display results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for P%d: ", proc[i].pid);
        scanf("%d", &proc[i].burstTime);
    }

    // Sort processes by burst time
    sortProcesses(proc, n);

    // Calculate waiting time and turnaround time
    calculateTimes(proc, n);

    return 0;
}

