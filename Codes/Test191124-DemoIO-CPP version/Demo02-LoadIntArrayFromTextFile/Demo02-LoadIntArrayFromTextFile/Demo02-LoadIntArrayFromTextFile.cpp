//
//  Demo02-LoadIntArrayFromTextFile.cpp
//  Demo02-LoadIntArrayFromTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void loadIntArray(ifstream &f, int a[], int &n);
void printIntArray(int a[], int n);

int main(int argc, const char * argv[]) {
    ifstream f;
    int a[100];
    int n = 0;
    
    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo02-LoadIntArrayFromTextFile/Demo02-LoadIntArrayFromTextFile/intarray-input.txt");
    if(!f.is_open()){
        cout << "File does not exist" << endl;
    }
    else{
        loadIntArray(f, a, n);
        printIntArray(a, n);
        f.close();
    }
    return 0;
}

void loadIntArray(ifstream &f, int a[], int &n){
    f >> n;
    for(int i = 0; i < n; i++){
        f >> a[i];
    }
}

void printIntArray(int a[], int n){
    if(n == 0){
        cout << "Empty array" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
