//
//  Demo10-LoadStudentArrayFromTextFile.cpp
//  Demo10-LoadStudentArrayFromTextFile
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

void loadStudent(FILE *f, Student &st);
void loadStudentArray(FILE *f, Student a[], int &n);
void printStudent(Student st);
void printStudentArray(Student a[], int n);

int main(int argc, const char * argv[]) {
    Student a[100];
    int n = 0;
    FILE *f;
    
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo10-LoadStudentArrayFromTextFile/Demo10-LoadStudentArrayFromTextFile/studentarray-input.txt", "rt");
    
    if(f == NULL){
        printf("Can not open file\n");
    }
    else{
        loadStudentArray(f, a, n);
        printStudentArray(a, n);
        fclose(f);
    }
    return 0;
}

void loadStudent(FILE *f, Student &st){
    fscanf(f, "%d", &st.id);
    fgets(st.name, 101, f);
    fgets(st.name, 101, f);
    st.name[strlen(st.name) - 1] = '\0';
    fscanf(f, "%d", &st.age);
    fgets(st.address, 101, f);
    fgets(st.address, 101, f);
    st.address[strlen(st.address) - 1] = '\0';
}
void loadStudentArray(FILE *f, Student a[], int &n){
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++){
        loadStudent(f, a[i]);
    }
}
void printStudent(Student st){
    printf("ID: %d\n", st.id);
    printf("Name: %s\n", st.name);
    printf("Age: %d\n", st.age);
    printf("Address: %s\n", st.address);
}
void printStudentArray(Student a[], int n){
    printf("Number of elements: %d\n", n);
    for(int i = 0; i < n; i++){
        printf("a[%d]: \n", i);
        printStudent(a[i]);
    }
}
