#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *p;
void clearAll();
void header(char headerName[10]);
int addNewRecord(char recordType[10]);

// Record
void recordStudent();
void recordBook();
void recordRental();

// Get all records
void getAllStudents();
void getAllBooks();
void getAllRentals();

// dispaly
int displayAllStudents();
int displayAllBooks();
int displayAllRentals();
// show details
int studentDetails();
int bookDetails();

// Remove
int deleteStudent();
int deleteBook();
int deleteRental();

// Check exist
int isExits(int type, int sId);

int numberOfStudents;
int numberOfBooks;
int numberOfRentals;
struct student
{
  int id;
  char fname[50];
  char lname[50];
  char faculty[50];
}st, newSt, allStudents[100];
struct book
{
  int id;
  char title[50];
  char author[50];
}bk, newBk, allBooks[100];
struct rental
{
  int id;
  int studentId;
  int bookId;
  char date[50];
}rt, newRt, allRentals[100];

int main() {
    int choice;
    int choice_st;
    int choice_bk;
    int choice_rt;
    
    home: 
      clearAll();
      header("Home");
      printf("1: Students\n");
      printf("2: Books\n");
      printf("3: Rentals\n");
      printf("4: Exit\n\n");
      printf("Please Enter your choice: ");
      scanf("%d", &choice);
      switch(choice){
        case 1: {
          student:
            clearAll();
            header("Students 🧑‍🎓");
            printf("1: List all students\n");
            printf("2: Student details\n");
            printf("3: Create new student\n");
            printf("4: Remove student\n");
            printf("5: Go To Home\n");
            printf("6: Exit\n\n");
            printf("Please Enter your choice: ");
            scanf("%d", &choice_st);
            switch(choice_st){
              case 1: {
                clearAll();
                header("All students 📉");
                getAllStudents();
                if(displayAllStudents() != 1) {
                  return 0;
                }
                goto student;
                break;
              }
              case 2: {
                clearAll();
                header("Student details ℹ️");
                if(studentDetails() != 1) {
                  return 0;
                }
                goto student;
                break;
              }
              case 3: {
                clearAll();
                header("New student 🆕");
                recordStudent();
                goto student;
                break;
              }
              case 4: {
                clearAll();
                header("Delete student ❗");
                getAllStudents();
                if(deleteStudent() != 1) {
                  return 0;
                }
                goto student;
                break;
              }
              case 5: {
                goto home;
                break;
              }
              case 6: {
                return 0;
              }
              default: 
                printf("Wrong choice, please choose again \t");
            }
          break;
        }
        case 2: {
          book:
            clearAll();
            header("Books 🧑‍🎓");
            printf("1: List all books\n");
            printf("2: Book details\n");
            printf("3: Create new book\n");
            printf("4: Remove book\n");
            printf("5: Go To Home\n");
            printf("6: Exit\n\n");
            printf("Please Enter your choice: ");
            scanf("%d", &choice_bk);
            switch(choice_bk){
              case 1: {
                clearAll();
                header("All Books 📉");
                getAllBooks();
                if(displayAllBooks() != 1) {
                  return 0;
                }
                goto book;
                break;
              }
              case 2: {
                clearAll();
                header("Book details ℹ️");
                if(bookDetails() != 1) {
                  return 0;
                }
                goto book;
                break;
              }
              case 3: {
                clearAll();
                header("New Book 🆕");
                recordBook();
                goto book;
                break;
              }
              case 4: {
                clearAll();
                header("Delete book ❗");
                getAllBooks();
                if(deleteBook() != 1) {
                  return 0;
                }
                goto book;
                break;
              }
              case 5: {
                goto home;
                break;
              }
              case 6: {
                return 0;
              }
              default: 
                printf("Wrong choice, please choose again \t");
            }
          break;
        }
        case 3: {
          rental:
            clearAll();
            header("Rentals 🧑‍🎓");
            printf("1: List rentals\n");
            printf("2: Create new rental\n");
            printf("3: Remove rental\n");
            printf("4: Go To Home\n");
            printf("5: Exit\n\n");
            printf("Please Enter your choice: ");
            scanf("%d", &choice_rt);
            switch(choice_rt){
              case 1: {
                clearAll();
                header("Rentals 📉");
                getAllRentals();
                if(displayAllRentals() != 1) {
                  return 0;
                }
                goto rental;
                break;
              }
              case 2: {
                clearAll();
                header("New Rental 🆕");
                recordRental();
                goto rental;
                break;
              }
              case 3: {
                clearAll();
                header("Delete rental ❗");
                getAllRentals();
                if(deleteRental() != 1) {
                  return 0;
                }
                goto rental;
                break;
              }
              case 4: {
                goto home;
                break;
              }
              case 5: {
                return 0;
              }
              default: 
                printf("Wrong choice, please choose again \t");
            }
          break;
        }
        case 4: {
          return 0;
          break;
        }
        default: 
          printf("Wrong choice, please choose again \t");
      }

  return 0;  
}

void clearAll() {
  printf("\e[1;1H\e[2J");
}
void header(char headerName[10]) {
  printf("======================================\n");
  printf("🌟 LIBRARY MANAGEMENT SYSTEM 🌟\n");
  printf("======================================\n");
  printf("> %s\n", headerName);
  printf("======================================\n");
}
int addNewRecord(char recordType[10]) {
  int choice;
  printf("Would you like to add a new %s?  if 'Yes', enter 1 or any other number for No.\n", recordType);
  scanf("%d", &choice);
  if(choice == 1) {
    return 1;
  } else {
    return 0;
  }
}

void setStudentProperty(char title[50], int *intValue, char strValue[20], int dataType, int type){
  int invalid = 1;
  while(invalid == 1){
    if(dataType == 1) {
      printf("%s \n", title);
      scanf("%d", intValue);
      if(isExits(type, newSt.id) == 1) {
        printf("\nRecord with ID: %d Already exist! ⚠️. Please, use a different Id).\n\n", newSt.id);
        invalid = 1;
      } else {
        invalid = 0;
      }
    } else {
      printf("%s (Please, spaces are not allowed! ⚠️)\n", title);
      scanf("%s",strValue);
      invalid = 0;
    }
  }
}
void setBookProperty(char title[50], int *intValue, char strValue[20], int dataType, int type){
  int invalid = 1;
  while(invalid == 1){
    if(dataType == 1) {
      printf("%s \n", title);
      scanf("%d", intValue);
      if(isExits(type, newBk.id) == 1) {
        printf("\nRecord with ID: %d Already exist! ⚠️. Please, use a different Id).\n\n", newBk.id);
        invalid = 1;
      } else {
        invalid = 0;
      }
    } else {
      printf("%s (Please, spaces are not allowed! instead, user (- or _ )⚠️)\n", title);
      scanf("%s",strValue);
      invalid = 0;
    }
  }
}
void setRentalProperty(char title[50], int *intValue, char strValue[20], int dataType, int type){
  int invalid = 1;
  while(invalid == 1){
    if(dataType == 1 && type == 1) {
      printf("%s \n", title);
      scanf("%d", intValue);
      if(isExits(3, newRt.id) == 1) {
        printf("\nRecord with ID: %d Already exist! ⚠️. Please, use a different Id).\n\n", newRt.id);
        invalid = 1;
      } else {
        invalid = 0;
      }
    } else if(dataType == 1 && type == 2) {
      printf("%s \n", title);
      scanf("%d", intValue);
      if(isExits(1, newRt.studentId) == 0) {
        printf("\nStudent with ID: %d Does not exist! ⚠️).\n\n", newRt.studentId);
        invalid = 1;
      } else {
        invalid = 0;
      }
    } else if(dataType == 1 && type == 3) {
      printf("%s \n", title);
      scanf("%d", intValue);
      if(isExits(2, newRt.bookId) == 0) {
        printf("\nBook with ID: %d Does not exist! ⚠️).\n\n", newRt.bookId);
        invalid = 1;
      } else {
        invalid = 0;
      }
    }
    else {
      printf("%s (Please, spaces are not allowed! instead, user (- or _ )⚠️)\n", title);
      scanf("%s",strValue);
      invalid = 0;
    }
  }
}


void recordStudent() {
  int newStudent = 1;
  do
  {
    setStudentProperty("Student's Id", &newSt.id, 0, 1, 1);
    setStudentProperty("Student's First Name", 0, newSt.fname, 0, 1);
    setStudentProperty("Student's Last Name", 0, newSt.lname, 0, 1);
    setStudentProperty("Student's faculty", 0, newSt.faculty, 0, 1);
    p=fopen("storage/Students.txt", "a+");
    fprintf(p,"%d\t%s\t%s\t%s \n", newSt.id, newSt.fname, newSt.lname, newSt.faculty);
    fclose(p);
    newStudent = addNewRecord("Student");
  } while (newStudent == 1);
}
void recordBook() {
  int newBook = 1;
  do
  {
    setBookProperty("Book's Id", &newBk.id, 0, 1, 2);
    setBookProperty("Book's Title", 0, newBk.title, 0, 2);
    setBookProperty("Book's Author", 0, newBk.author, 0, 2);
    p=fopen("storage/Books.txt", "a+");
    fprintf(p,"%d\t%s\t%s \n", newBk.id, newBk.title, newBk.author);
    fclose(p);
    newBook = addNewRecord("Book");
  } while (newBook == 1);
}
void recordRental() {
  int newRental = 1;
  do
  {
    setRentalProperty("Rental Id", &newRt.id, 0, 1, 1);
    setRentalProperty("Student Id",  &newRt.studentId, 0, 1,  2);
    setRentalProperty("Book Id",  &newRt.bookId, 0, 1,  3);
    setRentalProperty("Date ", 0, newRt.date, 0, 4);
    p=fopen("storage/Rentals.txt", "a+");
    fprintf(p,"%d\t%d\t%d\t%s \n", newRt.id, newRt.studentId, newRt.bookId, newRt.date);
    fclose(p);
    newRental = addNewRecord("Rental");
  } while (newRental == 1);
}

// data sorting
void sortStudents() {
  // Sort the List by Insertion sort
  int j;
  for(int a = 1; a < numberOfStudents; a++) {
    struct student temp = allStudents[a];
    j = a - 1;
    while(j >= 0 && temp.id < allStudents[j].id) {
      allStudents[j + 1] = allStudents[j];
      j-= 1;
    }
    allStudents[j + 1] = temp;
  }
}
void sortBooks() {
  // Sort the List by Insertion sort
  int j;
  for(int a = 1; a < numberOfBooks; a++) {
    struct book temp = allBooks[a];
    j = a - 1;
    while(j >= 0 && temp.id < allBooks[j].id) {
      allBooks[j + 1] = allBooks[j];
      j-= 1;
    }
    allBooks[j + 1] = temp;
  }
}
void sortRentals() {
  // Sort the List by Insertion sort
  int j;
  for(int a = 1; a < numberOfRentals; a++) {
    struct rental temp = allRentals[a];
    j = a - 1;
    while(j >= 0 && temp.id < allRentals[j].id) {
      allRentals[j + 1] = allRentals[j];
      j-= 1;
    }
    allRentals[j + 1] = temp;
  }
}

// Get all records
void getAllStudents() {
  numberOfStudents=0;
  p=fopen("storage/Students.txt", "r");
  int i = 0;
  while(!feof(p)) {
    fscanf(p, "%d\t%s\t%s\t%s \n", &st.id, st.fname, st.lname, st.faculty);
    allStudents[i].id = st.id;
    strcpy(allStudents[i].fname, st.fname);
    strcpy(allStudents[i].lname, st.lname);
    strcpy(allStudents[i].faculty, st.faculty);
    i++;
    numberOfStudents++;
  }
  fclose(p);
  sortStudents();
}
void getAllBooks() {
  numberOfBooks=0;
  p=fopen("storage/Books.txt", "r");
  int i = 0;
  while(!feof(p)) {
    fscanf(p, "%d\t%s\t%s \n", &bk.id, bk.title, bk.author);
    allBooks[i].id = bk.id;
    strcpy(allBooks[i].title, bk.title);
    strcpy(allBooks[i].author, bk.author);
    i++;
    numberOfBooks++;
  }
  fclose(p);
  sortBooks();
}
void getAllRentals() {
  numberOfRentals=0;
  p=fopen("storage/Rentals.txt", "r");
  int i = 0;
  while(!feof(p)) {
    fscanf(p, "%d\t%d\t%d\t%s \n", &rt.id, &rt.studentId, &rt.bookId, rt.date);
    allRentals[i].id = rt.id;
    allRentals[i].studentId = rt.studentId;
    allRentals[i].bookId = rt.bookId;
    strcpy(allRentals[i].date, rt.date);
    i++;
    numberOfRentals++;
  }
  fclose(p);
  sortRentals();
}

// Get Details
int studentDetails(){
   int sId;
   int found = 0;
   printf("Enter student's ID \n");
   scanf("%d", &sId);
   p=fopen("storage/Students.txt", "r");
   while(!feof(p)) {
    fscanf(p, "%d\t%s\t%s\t%s", &st.id, st.fname, st.lname, st.faculty);
    if(st.id == sId){
      found ++;
      break;
    }
   }
   fclose(p);
   if(found == 0) {
     printf("Student record with ID: %d, was not found! 😔\n", sId);
   } else {
     // we found the student
      printf("ID\tF-NAME\tL-NAME\tFACULTY\n");
      printf("======================================\n");
      printf("%d \t %s \t %s \t %s \n", st.id, st.fname, st.lname,st.faculty);
   }

    int choice;
    printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
    scanf("%d", &choice);
    if(choice == 1) {
      return 1;
    } else {
      return 0;
    }
}
int bookDetails(){
   int bId;
   int found = 0;
   printf("Enter book's ID \n");
   scanf("%d", &bId);
   p=fopen("storage/Books.txt", "r");
   while(!feof(p)) {
    fscanf(p, "%d\t%s\t%s", &bk.id, bk.title, bk.author);
    if(bk.id == bId){
      found ++;
      break;
    }
   }
   fclose(p);
   if(found == 0) {
     printf("Book record with ID: %d, was not found! 😔\n", bId);
   } else {
     // we found the student
      printf("ID\t\tTitle\t\tAUTHOR\n");
      printf("======================================\n");
      printf("%d \t %s \t %s \n", bk.id, bk.title, bk.author);
   }

    int choice;
    printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
    scanf("%d", &choice);
    if(choice == 1) {
      return 1;
    } else {
      return 0;
    }
}
int rentalDetails(){
   int rId;
   int found = 0;
   printf("Enter rental's id to see the Details \n");
   scanf("%d", &rId);
   p=fopen("storage/Rentals.txt", "r");
   while(!feof(p)) {
    fscanf(p, "%d\t%d\t%d\t%s", &rt.id, &rt.studentId, &rt.bookId, rt.date);
    if(rt.id == rId){
      found ++;
      break;
    }
   }
   fclose(p);
   if(found == 0) {
     printf("Rental record with ID: %d, was not found! 😔\n", rId);
   } else {
      printf("\n======================================\n");
      printf("Rental Details information\n");
      printf("======================================\n");
      printf("Date: %s \n", rt.date);
     // we found the rental, so lets fin student and book details of a corresponding rent
      int sFound = 0;
      p=fopen("storage/Students.txt", "r");
      while(!feof(p)) {
        fscanf(p, "%d\t%s\t%s\t%s", &st.id, st.fname, st.lname, st.faculty);
        if(st.id == rt.studentId){
          sFound ++;
          break;
        }
      }
      fclose(p);
      printf("\nStudent Information\n");
      printf("=========================\n");
      if(sFound == 0) {
        printf("--Student information of a selected rental was not found. This might be because it was deleted.-- \n");
      } else {
        // we found the student
        printf("Student Id: %d \n", st.id);
        printf("Student First name: %s \n", st.fname);
        printf("Student Last Name: %s \n", st.lname);
        printf("Student Faculty: %s \n", st.faculty);
      }
      int bfound = 0;
      p=fopen("storage/Books.txt", "r");
      while(!feof(p)) {
        fscanf(p, "%d\t%s\t%s", &bk.id, bk.title, bk.author);
        if(bk.id == rt.bookId){
          bfound ++;
          break;
        }
      }
      fclose(p);
      printf("\nBook Information\n");
      printf("======================\n");
      if(bfound == 0) {
        printf("--Book information of a selected rental was not found. This might be because it was deleted.-- \n");
      } else {
        // we found the student
        printf("Book Id: %d \n", st.id);
        printf("Book title: %s \n", bk.title);
        printf("Book author: %s \n\n", bk.author);
      }
    }

    int choice;
    printf("\nWould you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
    scanf("%d", &choice);
    if(choice == 1) {
      return 1;
    } else {
      return 0;
    }
}

// Delete records
int deleteStudent() {
  getAllStudents();
  int sId;
  int found = 0;
  int foundPos;
  printf("Enter student's ID \n");
  scanf("%d", &sId);
  for(int i = 0; i < numberOfStudents; i++) {
    if(allStudents[i].id == sId){
      found++;
      foundPos = i;
    }
  }

  if(found == 0) {
     printf("Student record with ID: %d, was not found! 😔\n", sId);
   } else {
     // we found the student, then we must delete him/her
      for(int i = foundPos; i < numberOfStudents; i++) {
        allStudents[i] = allStudents[i + 1];
      }
      printf("Record deleted successfully ✅\n", sId);
      numberOfStudents--;
      p = fopen("storage/Students.txt", "w");
      for(int i = 0; i < numberOfStudents; i++) {
       fprintf(p, "%d\t%s\t%s\t%s \n", allStudents[i].id, allStudents[i].fname, allStudents[i].lname, allStudents[i].faculty);  
      }
      fclose(p);
   }
  
  int choice;
  printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
  scanf("%d", &choice);
  if(choice == 1) {
    return 1;
  } else {
    return 0;
  }
}
int deleteBook() {
  getAllBooks();
  int bId;
  int found = 0;
  int foundPos;
  printf("Enter Book's ID \n");
  scanf("%d", &bId);
  for(int i = 0; i < numberOfBooks; i++) {
    if(allBooks[i].id == bId){
      found++;
      foundPos = i;
    }
  }

  if(found == 0) {
     printf("Book record with ID: %d, was not found! 😔\n", bId);
   } else {
     // we found the student, then we must delete him/her
      for(int i = foundPos; i < numberOfBooks; i++) {
        allBooks[i] = allBooks[i + 1];
      }
      printf("Record deleted successfully ✅\n", bId);
      numberOfBooks--;
      p = fopen("storage/Students.txt", "w");
      for(int i = 0; i < numberOfBooks; i++) {
       fprintf(p, "%d\t%s\t%s \n", allBooks[i].id, allBooks[i].title, allBooks[i].author);  
      }
      fclose(p);
   }
  
  int choice;
  printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
  scanf("%d", &choice);
  if(choice == 1) {
    return 1;
  } else {
    return 0;
  }
}
int deleteRental() {
  getAllRentals();
  int rId;
  int found = 0;
  int foundPos;
  printf("Enter Rental's ID \n");
  scanf("%d", &rId);
  for(int i = 0; i < numberOfRentals; i++) {
    if(allRentals[i].id == rId){
      found++;
      foundPos = i;
    }
  }

  if(found == 0) {
     printf("Rental record with ID: %d, was not found! 😔\n", rId);
   } else {
      for(int i = foundPos; i < numberOfBooks; i++) {
        allRentals[i] = allRentals[i + 1];
      }
      printf("Record deleted successfully ✅\n", rId);
      numberOfRentals--;
      p = fopen("storage/Rentals.txt", "w");
      for(int i = 0; i < numberOfRentals; i++) {
       fprintf(p, "%d\t%d\t%d\t%s \n", allRentals[i].id, allRentals[i].studentId, allRentals[i].bookId, allRentals[i].date);  
      }
      fclose(p);
   }
  
  int choice;
  printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
  scanf("%d", &choice);
  if(choice == 1) {
    return 1;
  } else {
    return 0;
  }
}


// Check record exist
int isExits(int type, int id) {
  switch (type)
  {
  // Check Students exit
  case 1: 
    {
    getAllStudents();
    int found = 0;
    for(int i = 0; i < numberOfStudents; i++) {
      if(allStudents[i].id == id){
        found++;
      }
    }
    return found > 0 ? 1 : 0;
    }
  // Check Book exit  
  case 2: 
    {
    getAllBooks();
    int found = 0;
    for(int i = 0; i < numberOfBooks; i++) {
      if(allBooks[i].id == id){
        found++;
      }
    }
    return found > 0 ? 1 : 0;
    return 0;
    }
  // Check Rental exit
  case 3:
    {
      getAllRentals();
      int found = 0;
      for(int i = 0; i < numberOfRentals; i++) {
        if(allRentals[i].id == id){
          found++;
        }
      }
      return found > 0 ? 1 : 0;
      return 0;
    }   
  default:
    return 0;
  }
}

// Display data
int displayAllStudents() {
  printf("ID\tF-NAME\tL-NAME\tFACULTY\n");
  printf("======================================\n");
  int i = 0;
  while(i < numberOfStudents) {
    printf("%d \t %s \t %s \t %s \n", allStudents[i].id, allStudents[i].fname, allStudents[i].lname, allStudents[i].faculty);
    i++;
  }
  int choice;
  printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
  scanf("%d", &choice);
  if(choice == 1) {
    return 1;
  } else {
    return 0;
  }
}
int displayAllBooks() {
  printf("ID\t\tTitle\t\tAUTHOR\n");
  printf("======================================\n");
  int i = 0;
  while(i < numberOfBooks) {
    printf("%d \t %s \t %s \n", allBooks[i].id, allBooks[i].title, allBooks[i].author);
    i++;
  }
  int choice;
  printf("Would you like to Go back or Exit, enter 1 to Go Back or any other number to Exit.\n");
  scanf("%d", &choice);
  if(choice == 1) {
    return 1;
  } else {
    return 0;
  }
}
int displayAllRentals() {
  printf("Id\t\SId\t\Book Id\tDate\n");
  printf("======================================\n");
  int i = 0;
  while(i < numberOfRentals) {
    printf("%d\t%d\t%d\t%s \n", allRentals[i].id, allRentals[i].studentId, allRentals[i].bookId, allRentals[i].date);
    i++;
  }
  return rentalDetails();
}

