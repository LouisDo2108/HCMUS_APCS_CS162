//
//  Demo07-SaveStudentArrayToTextFile.cpp
//  Demo07-SaveStudentArrayToTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct Student{
    int id;
    char name[101];
    int age;
    char address[101];
};

void inputStudent(Student &st);
void inputStudentArray(Student a[], int &n);
void saveStudent(FILE *f, Student st);
void saveStudentArray(FILE *f, Student a[], int n);

int main(int argc, const char * argv[]) {
    Student a[100];
    int n = 0;
    FILE *f;
    
    printf("Students in your class: \n");
    inputStudentArray(a, n);
    
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo09-SaveStudentArrayToTextFile/Demo09-SaveStudentArrayToTextFile/studentarray-output.txt", "wt");
    if(f == NULL){
        printf("Can not create file\n");
    }
    else{
        saveStudentArray(f, a, n);
        fclose(f);
    }
    return 0;
}

void inputStudent(Student &st){
    printf("ID: ");
    scanf("%d", &st.id);
    printf("Name: ");
    fgets(st.name, 101, stdin);
    fgets(st.name, 101, stdin);
    st.name[strlen(st.name) - 1] = '\0';
    printf("Age: ");
    scanf("%d", &st.age);
    printf("Address: ");
    fgets(st.address, 101, stdin);
    fgets(st.address, 101, stdin);
    st.address[strlen(st.address) - 1] = '\0';
}
void inputStudentArray(Student a[], int &n){
    printf("Number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("a[%d]: \n", i);
        inputStudent(a[i]);
    }
}
void saveStudent(FILE *f, Student st){
    fprintf(f, "%d\n", st.id);
    fprintf(f, "%s\n", st.name);
    fprintf(f, "%d\n", st.age);
    fprintf(f, "%s\n", st.address);
}
void saveStudentArray(FILE *f, Student a[], int n){
    fprintf(f, "%d\n", n);
    for(int i = 0; i < n; i++){
        saveStudent(f, a[i]);
    }
}
