#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int at[100], bt[100], ct[100], tat[100], wt[100];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int tmp;
                tmp = at[j]; at[j] = at[j + 1]; at[j + 1] = tmp;
                tmp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = tmp;
            }
        }
    }

    int currentTime = 0;

    for (i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];
        }
        ct[i] = currentTime + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        currentTime = ct[i];
    }

    for (i = 0; i < n; i++) {
        printf("%d %d %d %d %d\n", at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}