#include<stdio.h>
struct Student
{
  int id;
  char name[50];
  char faculty[50];
  char department[50];
}st;

int main() {
    int choice;
    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n");
    printf("1: Students\n");
    printf("2: Books\n");
    printf("3: Rentals\n");
    printf("4: Exit\n\n");
    printf("Please Enter your choice: ");
    scanf("%d", &choice);

  return 0;  
}
// cd "/Users/erice/Documents/c-c++/library_managment-system/" && g
// cc index.c -o index && "/Users/erice/Documents/c-c++/library_managm
// ent-system/"index

