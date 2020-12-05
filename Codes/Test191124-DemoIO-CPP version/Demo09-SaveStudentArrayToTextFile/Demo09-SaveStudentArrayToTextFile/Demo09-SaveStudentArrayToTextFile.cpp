//
//  Demo07-SaveStudentArrayToTextFile.cpp
//  Demo07-SaveStudentArrayToTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Student{
    int id;
    char name[101];
    int age;
    char address[101];
};

void inputStudent(Student &st);
void inputStudentArray(Student a[], int &n);
void saveStudent(ofstream &f, Student st);
void saveStudentArray(ofstream &f, Student a[], int n);

int main(int argc, const char * argv[]) {
    Student a[100];
    int n = 0;
    ofstream f;
    
    cout << "Students in your class: " << endl;
    inputStudentArray(a, n);
    
    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo09-SaveStudentArrayToTextFile/Demo09-SaveStudentArrayToTextFile/studentarray-output.txt");
    if(!f.is_open()){
        cout << "Can not create file" << endl;
    }
    else{
        saveStudentArray(f, a, n);
        f.close();
    }
    return 0;
}

void inputStudent(Student &st){
    cout << "ID: ";
    cin >> st.id;
    cout << "Name: ";
    cin.getline(st.name, 101);
    cin.getline(st.name, 101);
    cout << "Age: ";
    cin >> st.age;
    cout << "Address: ";
    cin.getline(st.address, 101);
    cin.getline(st.address, 101);
}
void inputStudentArray(Student a[], int &n){
    cout << "Number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: " << endl;
        inputStudent(a[i]);
    }
}
void saveStudent(ofstream &f, Student st){
    f << st.id << endl;
    f << st.name << endl;
    f << st.age << endl;
    f << st.address << endl;
}
void saveStudentArray(ofstream &f, Student a[], int n){
    f << n << endl;
    for(int i = 0; i < n; i++){
        saveStudent(f, a[i]);
    }
}
