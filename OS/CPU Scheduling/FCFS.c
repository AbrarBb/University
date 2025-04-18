#include <stdio.h>
int main() 
{
    int n, a;
    printf("No. of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n];
    printf("Burst times:\n");
    for(a=0; a<n; a++) scanf("%d", &bt[a]);

    wt[0] = 0;
    for(a=1; a<n; a++)
        wt[a] = wt[a-1] + bt[a-1];

    for(a=0; a<n; a++)
        tat[a] = bt[a] + wt[a];

    printf("P\tBT\tWT\tTAT\n");
    for(a=0; a<n; a++)
        printf("P%d\t%d\t%d\t%d\n", a+1, bt[a], wt[a], tat[a]);
}
