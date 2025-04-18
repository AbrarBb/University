#include <stdio.h>
int main() 
{
    int n;
    printf("Processes: ");
    scanf("%d", &n);
    int bt[n], pr[n], wt[n]={0}, tat[n], i, j, t;
    printf("Burst times:\n");
    for(i=0;i<n;i++) scanf("%d", &bt[i]);
    printf("Priorities:\n");
    for(i=0;i<n;i++) scanf("%d", &pr[i]);

    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(pr[j] > pr[j+1]) {
                t=pr[j]; pr[j]=pr[j+1]; pr[j+1]=t;
                t=bt[j]; bt[j]=bt[j+1]; bt[j+1]=t;
            }

    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("P\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
}
