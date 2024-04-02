#include <stdio.h>

// Structure to represent a process
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
} Process;

// Function to calculate completion times for each process using FCFS algorithm
void calculateCompletionTimes(Process processes[], int n) {
    int current_time = 0; // Initialize current time to 0

    for (int i = 0; i < n; i++) {
        // Set completion time as current time + burst time for each process
        processes[i].completion_time = current_time + processes[i].burst_time;

        // Update current time to the completion time of the current process
        current_time = processes[i].completion_time;
    }
}

// Function to display the completion times for each process
void displayCompletionTimes(Process processes[], int n) {
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n]; // Array to store processes

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
    }

    // Calculate completion times using FCFS algorithm
    calculateCompletionTimes(processes, n);

    // Display completion times for each process
    displayCompletionTimes(processes, n);

    return 0;
}
