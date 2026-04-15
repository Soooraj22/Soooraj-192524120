#include <stdio.h>

int main() {
    int users, files;
    char user[10][20], file[10][10][20];

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(int i=0;i<users;i++){
        printf("Enter user name: ");
        scanf("%s", user[i]);

        printf("Enter number of files: ");
        scanf("%d", &files);

        for(int j=0;j<files;j++){
            printf("Enter file name: ");
            scanf("%s", file[i][j]);
        }
    }

    printf("\nDirectory Structure:\n");
    for(int i=0;i<users;i++){
        printf("User: %s\n", user[i]);
        for(int j=0;j<files;j++)
            printf("  %s\n", file[i][j]);
    }

    return 0;
}
