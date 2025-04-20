#include <stdio.h>
int main() 
{
  int n, a, at[10], bt[10], rt[10], wt[10], tat[10], done=0, t=0;
  printf("Processes: ");
  scanf("%d", &n);
  for(a = 0; a < n; a++) 
  {
     printf("P%d: ", a+1);
    scanf("%d %d", &at[a], &bt[a]);
    rt[a] = bt[a];
  }

  while(done < n) 
  {
    int min = 9999, p = -1;
    for(a = 0; a < n; a++)
      if(at[a] <= t && rt[a] > 0 && rt[a] < min)
        min = rt[a], p = a;
    if(p == -1) { t++; continue; }

    rt[p]--;
    if(rt[p] == 0) {
      wt[p] = t + 1 - at[p] - bt[p];
      tat[p] = wt[p] + bt[p];
      done++;
    }
    t++;
  }

  printf("\nP   AT BT WT TAT\n");
  for(a = 0; a < n; a++)
    printf("P%d %2d %2d %2d %3d\n", a+1, at[a], bt[a], wt[a], tat[a]);
}
