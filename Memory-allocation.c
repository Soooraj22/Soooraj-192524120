#include <stdio.h>

int main() {
    int blockSize[5] = {100, 500, 200, 300, 600};
    int processSize[4] = {212, 417, 112, 426};

    int allocation[4] = {-1, -1, -1, -1};

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("Process No\tBlock No\n");
    for(int i=0;i<4;i++)
        printf("%d\t\t%d\n", i+1, allocation[i]+1);

    return 0;
}
