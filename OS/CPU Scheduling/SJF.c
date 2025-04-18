#include <stdio.h>
int main() 
{
    int n, a, b, temp;
    printf("Processes: ");
    scanf("%d", &n);
    int bt[n], wt[n]={0}, tat[n];
    printf("Burst times:\n");
    for(a=0; a<n; a++) scanf("%d", &bt[a]);

    for(a=0; a<n; a++) // sort burst times
        for(b=0; b<n-1; b++)
            if(bt[b] > bt[b+1]) 
            {
                temp = bt[b];
                bt[b] = bt[b+1];
                bt[b+1] = temp;
            }

    for(a=1; a<n; a++)
        wt[a] = wt[a-1] + bt[a-1];

    for(a=0; a<n; a++)
        tat[a] = bt[a] + wt[a];

    printf("P\tBT\tWT\tTAT\n");
    for(a=0; a<n; a++)
        printf("P%d\t%d\t%d\t%d\n", a+1, bt[a], wt[a], tat[a]);
}
