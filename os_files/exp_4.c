#include <stdio.h>

int main()
{
    int c,j,n,t,r,flag=0,t_q;
    int t_t=0,w_t=0,at[10],bt[10],rt[10];
    float avg_wt,avg_tt;
    printf("Enter Total Proces:\t");
    scanf("%d",&n);
    r=n;
    for(c=0;c<n;c++)
    {
        printf("Enter Arrival Time and Burst Time for Process Number %d : ",c+1);
        scanf("%d",&at[c]);
        scanf("%d",&bt[c]);
        rt[c] = bt[c];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d",&t_q);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(t=0,c=0;r!=0;)
    {
        if(rt[c]<=t_q&&rt[c]>0)
        {
            t+=rt[c];
            rt[c]=0;
            flag=1;
        }
        else
        if(rt[c]>0)
        {
            rt[c]=rt[c]-t_q;
            t+=t_q;
        }
        if(rt[c]==0&&flag==1)
        {
            r--;
            printf("P[%d]\t|\t%d\t|\t%d\n",c+1,t-at[c],t-at[c]-bt[c]);
            w_t+=t-at[c]-bt[c];
            t_t+=t-at[c];
            flag=0; 
        }
        if(c==n-1)
        c=0;
        else
        if(at[c+1]<=t)
        c++;
        else 
        c=0;

    }
    avg_wt=w_t*1.0/n;
    avg_tt=t_t*1.0/n;
    printf("\nAverage Waiting Time= %f\n",avg_wt);
    printf("Avg Turnaround Time= %f",avg_tt);
    return 0;
}


