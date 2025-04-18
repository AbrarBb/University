#include <stdio.h>
#define INF 9999
int main() 
{
    int n, a, t=0, done=0, min, pos;
    printf("Processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], wt[n], tat[n];
    printf("Arrival times:\n");
    for(a=0; a<n; a++) scanf("%d", &at[a]);
    
    printf("Burst times:\n");
    for(a=0; a<n; a++) 
    {
        scanf("%d", &bt[a]);
        rt[a] = bt[a];
    }

    while(done < n) 
  {
        min = INF;
        pos = -1;
        for(a=0; a<n; a++)
            if(at[a] <= t && rt[a] > 0 && rt[a] < min) {
                min = rt[a];
                pos = a;
            }

        if(pos == -1) { t++; continue; }

        rt[pos]--;
        t++;
        if(rt[pos] == 0) {
            done++;
            tat[pos] = t - at[pos];
            wt[pos] = tat[pos] - bt[pos];
        }
    }

    printf("P\tAT\tBT\tWT\tTAT\n");
    for(a=0; a<n; a++)
        printf("P%d\t%d\t%d\t%d\t%d\n", a+1, at[a], bt[a], wt[a], tat[a]);
}
