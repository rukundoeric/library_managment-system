#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *p;
void clearAll();
void header(char headerName[10]);
int addNewRecord(char recordType[10]);
void recordStudent();
void getAllStudents();
int displayAllStudents();
int studentDetails();
int deleteStudent();
int isExits(int type, int sId);

int numberOfStudents;
struct student
{
  int id;
  char fname[50];
  char lname[50];
  char faculty[50];
}st, newSt, allStudents[100];

int main() {
    int choice;
    int choice_st;
    
    home: 
      // clearAll();
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
            header("Students");
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
                header("All students");
                getAllStudents();
                if(displayAllStudents() != 1) {
                  return 0;
                }
                goto student;
                break;
              }
              case 2: {
                clearAll();
                header("Student details");
                if(studentDetails() != 1) {
                  return 0;
                }
                goto student;
                break;
              }
              case 3: {
                clearAll();
                header("New student");
                recordStudent();
                goto student;
                break;
              }
              case 4: {
                clearAll();
                header("Delete student");
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
          clearAll();
          header("Books");
          printf("Books\n");
          break;
        }
        case 3: {
          clearAll();
          header("Rentals");
          printf("Rentals\n");
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
  printf("LIBRARY MANAGEMENT SYSTEM\n");
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
      printf("NEW ID IS %d ", newSt.id);
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

void recordStudent() {
  int newStudent = 1;
  do
  {
    setStudentProperty("Student's Id", &newSt.id, 0, 1, 1);
    setStudentProperty("Student's First Name", 0, newSt.fname, 0, 1);
    setStudentProperty("Student's Last Name", 0, newSt.lname, 0, 1);
    setStudentProperty("Student's faculty", 0, newSt.faculty, 0, 1);
    printf("ID IS %d ", newSt.id);
    p=fopen("storage/Students.txt", "a+");
    fprintf(p,"%d\t%s\t%s\t%s \n", newSt.id, newSt.fname, newSt.lname, newSt.faculty);
    fclose(p);
    newStudent = addNewRecord("Student");
  } while (newStudent == 1);
}
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
        // if(i==numberOfStudents - 1){
        //   allStudents[i] = NULL;
        // } else {
           
        // }
      }
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
int isExits(int type, int sId) {
  switch (type)
  {
  // Check Students exit
  case 1: 
    getAllStudents();
    int found = 0;
    for(int i = 0; i < numberOfStudents; i++) {
      if(allStudents[i].id == sId){
        found++;
      }
    }
    return found > 0 ? 1 : 0;
  // Check Book exit  
  case 2:   
    return 0;
  // Check Rental exit
  case 3:
    return 0;   
  default:
    return 0;
  }
}
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

