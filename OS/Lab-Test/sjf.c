#include <stdio.h>
int main() 
{
    int n, a, b, temp;
    printf("Processes: ");
    scanf("%d", &n);
    int wt[n], tat[n];
    
    int bt[]={3,4,2,4};


    // Sort burst times (SJF)
    for(a = 0; a < n; a++) 
    {
        for(b = 0; b < n - 1; b++)
        {
            if(bt[b] > bt[b + 1]) 
            {
                temp = bt[b];
                bt[b] = bt[b + 1];
                bt[b + 1] = temp;
            }   
        }       
    }
   
    wt[0] = 0; 
    for(a = 1; a < n; a++)
        wt[a] = wt[a - 1] + bt[a - 1];

    for(a = 0; a < n; a++)
        tat[a] = bt[a] + wt[a];

    printf("P\tBT\tWT\tTAT\n");
    for(a = 0; a < n; a++)
        printf("P%d\t%d\t%d\t%d\n", a + 1, bt[a], wt[a], tat[a]);
}
