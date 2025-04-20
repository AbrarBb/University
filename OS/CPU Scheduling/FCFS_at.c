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
  
    //Average 
    int tat_s=0,wt_s=0;
    for(int a=0;a<n;a++)
    {
        tat_s=tat[a]+tat_s;
        wt_s=wt_wt[a];
    }
    printf("\n AvgWT:%.2f\tAvg.TAT:%.2f",(float)wt_s/n,(float)tat_s/n);
}
