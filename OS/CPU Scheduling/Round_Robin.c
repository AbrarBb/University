#include <stdio.h>
int main() 
{
    int n, tq, a, t=0;
    printf("Processes: ");
    scanf("%d", &n);
    printf("Time quantum: ");
    scanf("%d", &tq);
    int bt[n], rt[n], wt[n]={0}, tat[n];
    printf("Burst times:\n");
    for(a=0; a<n; a++) {
        scanf("%d", &bt[a]);
        rt[a] = bt[a];
    }

    int done;
    do {
        done = 1;
        for(a=0; a<n; a++) {
            if(rt[a] > 0) {
                done = 0;
                if(rt[a] > tq) {
                    t += tq;
                    rt[a] -= tq;
                } else {
                    t += rt[a];
                    wt[a] = t - bt[a];
                    rt[a] = 0;
                }
            }
        }
    } while(!done);

    for(a=0; a<n; a++)
        tat[a] = wt[a] + bt[a];

    printf("P\tBT\tWT\tTAT\n");
    for(a=0; a<n; a++)
        printf("P%d\t%d\t%d\t%d\n", a+1, bt[a], wt[a], tat[a]);
}
