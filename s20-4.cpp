#include <stdio.h>

int main (){
    FILE *fptr;
    char Line[100];
    fptr=fopen("bt01.txt", "r");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    if(fgets(Line, sizeof(Line), fptr) != NULL){
        printf("Dong dau tien trong file la: %s", Line);
    }else{
        printf("File rong\n");
    }
    fclose(fptr);

    return 0;
}
