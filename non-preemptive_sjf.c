#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Burst time P%d: ", i+1);
        scanf("%d",&bt[i]);
    }

    // Sorting
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(bt[i]>bt[j]){
                int temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }

    wt[0]=0;
    for(int i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(int i=0;i<n;i++)
        tat[i]=wt[i]+bt[i];

    printf("\nWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\n",wt[i],tat[i]);

    return 0;
}
