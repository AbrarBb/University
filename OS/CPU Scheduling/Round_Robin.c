#include <stdio.h>
int main() 
{
    int n, tq;
    printf("Processes: ");
    scanf("%d", &n);
    printf("Time quantum: ");
    scanf("%d", &tq);
    int bt[n], rt[n], wt[n]={0}, tat[n], i, t=0;
    printf("Burst times:\n");
    for(i=0;i<n;i++) { scanf("%d", &bt[i]); rt[i] = bt[i]; }

    int done;
    do {
        done = 1;
        for(i=0; i<n; i++) {
            if(rt[i] > 0) {
                done = 0;
                if(rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(i=0;i<n;i++) tat[i] = wt[i] + bt[i];

    printf("P\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}
