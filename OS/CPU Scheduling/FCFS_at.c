#include <stdio.h>
int main() 
{
  int n, a;
  printf("Processes: ");
  scanf("%d", &n);
  int at[n], bt[n], wt[n], tat[n], ct[n];
   
  printf("   AT BT\n");
  for(a=0; a<n; a++) 
  {
    printf("P%d: ", a+1);
    scanf("%d %d", &at[a], &bt[a]);
    
  }

  int time = 0;
  for(a=0; a<n; a++) 
  {
    if(time < at[a]) 
    {
        time = at[a];
    }
    wt[a] = time - at[a];
    time =time+ bt[a];
    tat[a] = wt[a] + bt[a];
  }


printf("\n    WT\tTAT\n");
  for(a=0; a<n; a++)
  {
      printf("P%d\t%d\t %d\n", a+1, wt[a], tat[a]);
  }
    
}
