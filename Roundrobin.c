//Round Robin implementation in C

#include <stdio.h>

#define NUM_PROCESSES 3
#define TIME_SLICE 2

int main() {
    int processes[NUM_PROCESSES] = {1, 2, 3};
    int burst_times[NUM_PROCESSES] = {5, 3, 2};
    int current_time = 0;
    int i, j;

    printf("Process\tBurst Time\tTurnaround Time\n");

    for (i = 0; i < NUM_PROCESSES; i++) {
        int turnaround_time = 0;
        for (j = 0; j < NUM_PROCESSES; j++) {
            if (burst_times[j] > 0) {
                int time_slice = (burst_times[j] < TIME_SLICE) ? burst_times[j] : TIME_SLICE;
                burst_times[j] -= time_slice;
                current_time += time_slice;
                turnaround_time += time_slice;
            }
        }
        printf("P%d\t%d\t%d\n", processes[i], burst_times[i], turnaround_time);
    }

    return 0;
}
