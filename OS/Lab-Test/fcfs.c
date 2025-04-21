#include<stdio.h>
int main()
{
    int n;
    printf("Process:");
    scanf("%d",&n);
    int tat[n],wt[n];
    int bt[]={24,8,5};
    int at[]={0,0,0};
    
    int t=0;
    for(int a=0;a<n;a++)
    {
        if(t<at[a])
        {
            t=at[a];
        }
        t+=bt[a];
        tat[a]=t-at[a];
        wt[a]=t-at[a]-bt[a];
        
        
    }
    
    printf("\n \tBT\tWT\tTAT\n");
    for (int a = 0; a < n; a++)
      {
       printf("P%d\t%d\t%d\t%d\n", a+1, bt[a], wt[a], tat[a]);
      }
       

}
