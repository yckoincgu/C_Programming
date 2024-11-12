#include <stdio.h>

struct Student {
  char name[10];
  char id[10];
};

int main(){

char p[10]={"test"};    //  the first way to assign value to C array
printf("p = %s",p);


struct Student s1={"john","001"}, s2={"Mary","002"}, s3;
printf("Enter name for s3: ");
    scanf("%s", s3.name);   // //  the second way to assign value to C array
printf("Enter id for s3: ");
    scanf("\n %s", s3.id);    

struct Student students[3] = {s1, s2, s3};

int i=sizeof(students[0]), j=sizeof(students), studentsLength=j/i;
printf(" the number of students is %d \n", studentsLength);

for(i=0; i< studentsLength; i++)
    printf(" student[%d] name is %s \n", i+1,students[i].name);    


}