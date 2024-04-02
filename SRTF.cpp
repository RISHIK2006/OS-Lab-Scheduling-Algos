#include<stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_arrival_time(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int find_shortest_remaining_time(struct Process processes[], int n, int current_time) {
    int shortest_index = -1;
    int shortest_time = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time) {
            shortest_index = i;
            shortest_time = processes[i].remaining_time;
        }
    }
    return shortest_index;
}

void srtf(struct Process processes[], int n) {
    int completed = 0;
    int current_time = 0;
    sort_by_arrival_time(processes, n);

    while (completed != n) {
        int shortest_index = find_shortest_remaining_time(processes, n, current_time);
        if (shortest_index == -1) {
            printf("No process available at time %d.\n", current_time);
            current_time++;
            continue;
        }

        processes[shortest_index].remaining_time--;
        current_time++;

        if (processes[shortest_index].remaining_time == 0) {
            completed++;
            processes[shortest_index].completion_time = current_time;
        }
    }

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    srtf(processes, n);

    return 0;
}
