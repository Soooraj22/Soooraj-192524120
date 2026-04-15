#include <stdio.h>

int main() {
    int n;
    char files[10][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter file name: ");
        scanf("%s", files[i]);
    }

    printf("\nFiles in directory:\n");
    for(int i=0;i<n;i++)
        printf("%s\n", files[i]);

    return 0;
}
