#include <stdio.h>
int main() 
{
    int n, a, t=0, done=0, min, pos;
    printf("Processes: ");
    scanf("%d", &n);
    int rt[n], wt[n], tat[n];
    
    int at[]={0,1,2,4};
    int bt[]={5,3,4,1};
    
    for(a=0; a<n; a++) 
    {
        rt[a] = bt[a];
    }

    while(done < n) 
  {
        min = 999;
        pos = -1;
        for(a=0; a<n; a++)
        {
            if(at[a] <= t && rt[a] > 0 && rt[a] < min) 
            {
                min = rt[a];
                pos = a;
            }
        }

        if(pos == -1) 
        { 
            t++; 
            continue;
        }

        rt[pos]--;
        t++;
        if(rt[pos] == 0) 
        {
            done++;
            tat[pos] = t - at[pos];
            wt[pos] = tat[pos] - bt[pos];
        }
  }

    printf("P\tAT\tBT\tWT\tTAT\n");
    for(a=0; a<n; a++)
        printf("P%d\t%d\t%d\t%d\t%d\n", a+1, at[a], bt[a], wt[a], tat[a]);
}
