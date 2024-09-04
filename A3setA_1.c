#include <stdio.h>

void findavgTime(int bt[], int n) {
    int wt = 0, tat = 0, total_wt = 0, total_tat = 0;
    printf("Processes Burst time Waiting time Turn around time\n");
    for (int i = 0; i < n; i++) {
        printf(" %d %d %d %d\n", i+1, bt[i], wt, wt + bt[i]);
        total_wt += wt;
        total_tat += (wt += bt[i]);
    }
    printf("Average waiting time = %.2f\nAverage turn around time = %.2f\n",
           (float)total_wt / n, (float)total_tat / n);
}

void main() {
    int burst_time[] = {10, 5, 8};
    findavgTime(burst_time, sizeof burst_time / sizeof burst_time[0]);
   
}
