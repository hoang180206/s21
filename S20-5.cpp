#include <stdio.h>

int main (){
    FILE *fptr;
    int n, i;
    char Line[100];
    fptr=fopen("bt05.txt", "w");
    if(fptr==NULL){
        printf("Khong the tao file\n");
        return 1;
    }
    printf("Nhap so dong can ghi vao file: ");
    scanf("%d", &n);
    getchar();
    for(i=1; i<=n; i++){
        printf("Nhap dong %d: ", i);
        fgets(Line, sizeof(Line), stdin);
        fprintf(fptr, "%s", Line);
    }
    fclose(fptr);
    fptr=fopen("bt05.txt", "r");
    if(fptr==NULL){
        printf("Khong the mo file de doc\n");
        return 1;
    }
    fclose(fptr);

    return 0;
}
