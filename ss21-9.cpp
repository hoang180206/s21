#include <stdio.h>
#include <string.h>

struct Book {
	char author[100];
    float price;
    char category[100];
    char book_id[100];
    char title[100];
    
};

void enterBooks(struct Book *books, int *num_books);
void saveBooks(struct Book *books, int num_books);
void loadBooks(struct Book *books, int *num_books);
void displayBooks(struct Book *books, int num_books);

int main() {
    struct Book books[100]; // 100 là so phan tu toi ða
    int num_books = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Luu thong tin sach vao file.\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                enterBooks(books, &num_books);
                break;
            case 2:
                saveBooks(books, num_books);
                break;
            case 3:
                loadBooks(books, &num_books);
                break;
            case 4:
                displayBooks(books, num_books);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default :
                printf("Lua chon khong hop le.\n");
        }
    }while(choice != 5);

    return 0;
}

void enterBooks(struct Book *books, int *num_books){
    printf("\nNhap so luong sach: ");
    scanf("%d", num_books);
    getchar();
    for(int i = 0; i < *num_books; i++){
        printf("\nNhap thong tin sach %d\n", i + 1);
        printf("Book ID: ");
        fgets(books[i].book_id, sizeof(books[i].book_id), stdin);
        books[i].book_id[strcspn(books[i].book_id, "\n")] = '\0';
        
      printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        
        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';


        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar();

        printf("Category: ");
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = '\0';
    }
}

void saveBooks(struct Book *books, int num_books){
    FILE *file = fopen("books.bin", "wb");
    if(file != NULL){
        fwrite(books, sizeof(struct Book), num_books, file);
        fclose(file);
        printf("\nLuu thong tin thanh cong.\n");
    }else{
        printf("\nKhong the mo file.\n");
        return;
    }
}

void loadBooks(struct Book *books, int *num_books){
    FILE *file = fopen("books.bin", "rb");
    if(file != NULL){
        *num_books = fread(books, sizeof(struct Book), 100, file);
        fclose(file);
        printf("Da cap nhat thong tin sach.\n");
    }else{
        printf("Khong the mo tep.\n");
    }
    
}

void displayBooks(struct Book *books, int num_books){
    printf("Thong tin sach:\n");
    for(int i = 0; i < num_books; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].book_id);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia sach: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
        printf("\n");
    }
}
