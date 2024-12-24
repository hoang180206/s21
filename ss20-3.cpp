#include <stdio.h>

int main (){
    FILE *fptr;
    char userInput[100];
    fptr = fopen("bt01.txt","a");
    if(fptr==NULL){
        printf("Khong the nao mo file\n");
        return 1;
    }
    printf("Nhap chuoi de ghi vao file: ");
    fgets(userInput, sizeof(userInput), stdin);
    fprintf(fptr, "%s", userInput);
    fclose(fptr);
    
    return 0;
}
