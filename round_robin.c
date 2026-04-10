#include <stdio.h>

int main() {
    int n, bt[10], rem[10], tq;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d",&tq);

    int done;
    do {
        done = 1;
        for(int i=0;i<n;i++){
            if(rem[i]>0){
                done = 0;
                if(rem[i]>tq){
                    rem[i]-=tq;
                } else {
                    printf("P%d finished\n",i+1);
                    rem[i]=0;
                }
            }
        }
    } while(!done);

    return 0;
}
