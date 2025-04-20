#include <stdio.h>
int main() 
{
  int n, tq, a, at[10], bt[10], rt[10], wt[10]={0}, tat[10], done=0, t=0;
  printf("Processes and time quantum: ");
  scanf("%d%d", &n, &tq);
  for(a = 0; a < n; a++) 
  {
    printf("AT & BT of P%d: ", a+1);
    scanf("%d%d", &at[a], &bt[a]);
    rt[a] = bt[a];
  }

  while(done < n) 
  {
    int found = 0;
    for(a = 0; a < n; a++) 
    {
      if(at[a] <= t && rt[a] > 0) 
      {
        found = 1;
        int use = (rt[a] > tq) ? tq : rt[a];
        t += use; rt[a] -= use;
        if(rt[a] == 0) 
        {
          wt[a] = t - at[a] - bt[a];
          tat[a] = wt[a] + bt[a];
          done++;
        }
      }
    }
    if(!found) t++;
  }

  printf("P AT BT WT TAT\n");
  for(a = 0; a < n; a++)
    printf("P%d %2d %2d %2d %3d\n", a+1, at[a], bt[a], wt[a], tat[a]);
}
