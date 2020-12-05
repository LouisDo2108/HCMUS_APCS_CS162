//
//  Demo01-SaveIntArrayToTextFile.cpp
//  Demo01-SaveIntArrayToTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void inputIntArray(int a[], int &n);
void saveIntArray(ofstream &f, int a[], int n);

int main(int argc, const char * argv[]) {
    int a[100];
    int n = 0;
    
    inputIntArray(a, n);
    
    ofstream f;

    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo01-SaveIntArrayToTextFile/Demo01-SaveIntArrayToTextFile/intarray-output.txt");
    if(!f.is_open()){
        cout << "Can not create file intarray-output.txt" << endl;
    }
    else{
        saveIntArray(f, a, n);
        f.close();
    }
    
    return 0;
}

void inputIntArray(int a[], int &n){
    cout << "Number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}

void saveIntArray(ofstream &f, int a[], int n){
    f << n << endl;
    for(int i = 0; i < n; i++){
        f << a[i] << " ";
    }
}
