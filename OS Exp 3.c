#include <stdio.h>

int main() {
    int A[100][4];  // A[i][0]: Process ID, A[i][1]: Burst Time, A[i][2]: Waiting Time, A[i][3]: Turnaround Time
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    // Input: Number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input: Burst time of each process
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;  // Storing Process ID
    }

    // Sorting the processes by Burst Time (SJF - Shortest Job First)
    for (i = 0; i < n - 1; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1]) {
                index = j;
            }
        }
        // Swap burst time
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        // Swap process ID
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    // Calculate Waiting Time
    A[0][2] = 0; // First process has 0 waiting time
    total = 0;   // Reset total for waiting time calculation

    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++) {
            A[i][2] += A[j][1];
        }
        total += A[i][2];
    }

    avg_wt = (float)total / n;  // Average Waiting Time

    // Calculate Turnaround Time
    total = 0; // Reset total for turnaround time calculation
    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2]; // Turnaround Time = Burst Time + Waiting Time
        total += A[i][3];
        printf("P%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }

    avg_tat = (float)total / n;  // Average Turnaround Time

    // Print Averages
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

