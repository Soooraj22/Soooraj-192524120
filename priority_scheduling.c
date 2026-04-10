#include <stdio.h>

int main() {
    int n, bt[10], pr[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Burst time & Priority P%d: ",i+1);
        scanf("%d %d",&bt[i],&pr[i]);
    }

    // Sorting by priority
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(pr[i]>pr[j]){
                int temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }

    printf("\nExecution Order:\n");
    for(int i=0;i<n;i++)
        printf("P%d ",i+1);

    return 0;
}
