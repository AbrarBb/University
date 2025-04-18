#include <stdio.h>
int main() 
{
    int n, a, b, temp;
    printf("Processes: ");
    scanf("%d", &n);
    int bt[n], pr[n], wt[n]={0}, tat[n];
    printf("Burst times:\n");
    for(a=0; a<n; a++) scanf("%d", &bt[a]);
    printf("Priorities:\n");
    for(a=0; a<n; a++) scanf("%d", &pr[a]);

    for(a=0; a<n-1; a++)
        for(b=0; b<n-1-a; b++)
            if(pr[b] > pr[b+1]) {
                temp = pr[b]; pr[b] = pr[b+1]; pr[b+1] = temp;
                temp = bt[b]; bt[b] = bt[b+1]; bt[b+1] = temp;
            }

    for(a=1; a<n; a++)
        wt[a] = wt[a-1] + bt[a-1];

    for(a=0; a<n; a++)
        tat[a] = wt[a] + bt[a];

    printf("P\tBT\tPR\tWT\tTAT\n");
    for(a=0; a<n; a++)
        printf("P%d\t%d\t%d\t%d\t%d\n", a+1, bt[a], pr[a], wt[a], tat[a]);
}
