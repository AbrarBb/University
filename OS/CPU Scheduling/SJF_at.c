#include <stdio.h>
int main() 
{
  int n, a, done = 0, t = 0;

  printf("Processes: ");
  scanf("%d", &n);
  
  int at[n], bt[n], wt[n], tat[n],f[10] = {0};
  
  printf("   AT BT\n");
  for(a = 0; a < n; a++) 
  {
    printf("P%d: ", a + 1);
    scanf("%d %d", &at[a], &bt[a]);
  }

  while(done < n) 
  {
    int min = 9999, p = -1;
    for(a = 0; a < n; a++)
      if(!f[a] && at[a] <= t && bt[a] < min) 
      {
        min = bt[a]; 
        p = a;
      }

    if(p == -1) 
    { 
      t++; 
      continue; 
    }

    wt[p] = t - at[p];
    if(wt[p] < 0) wt[p] = 0;
    
    t += bt[p];
    tat[p] = wt[p] + bt[p];
    f[p] = 1; 
    done++;
  }

  printf("\nP   AT BT WT TAT\n");
  for(a = 0; a < n; a++)
    printf("P%d %2d %2d %2d %3d\n", a + 1, at[a], bt[a], wt[a], tat[a]);

  return 0;
}
