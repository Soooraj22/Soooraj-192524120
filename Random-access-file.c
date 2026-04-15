#include <stdio.h>

struct emp {
    int id;
    char name[20];
};

int main() {
    FILE *fp;
    struct emp e;

    fp = fopen("emp.dat", "wb");

    for(int i=0;i<2;i++){
        printf("Enter ID and Name: ");
        scanf("%d %s", &e.id, e.name);
        fwrite(&e, sizeof(e), 1, fp);
    }

    fclose(fp);

    fp = fopen("emp.dat", "rb");

    printf("\nEmployee Details:\n");
    while(fread(&e, sizeof(e), 1, fp)){
        printf("%d %s\n", e.id, e.name);
    }

    fclose(fp);
    return 0;
}
