#include <stdio.h>

int main(){
    FILE *fptr;
    char chudautien;

    fptr=fopen("bt01.txt","r");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    chudautien=fgetc(fptr);
    printf("Ky tu dau tien trong file la: %c\n", chudautien);
    fclose(fptr);
    
    return 0;
}
