//
//  Demo08-LoadFractionArrayFromTextFile.cpp
//  Demo08-LoadFractionArrayFromTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void loadFraction(ifstream &f, Fraction &p);
void printFraction(Fraction p);
void loadFractionArray(ifstream &f, Fraction a[], int &n);
void printFractionArray(Fraction a[], int n);

int main(int argc, const char * argv[]) {
    Fraction a[100];
    int n = 0;
    ifstream f;
    
    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo08-LoadFractionArrayFromTextFile/Demo08-LoadFractionArrayFromTextFile/fractionarray-input.txt");
    
    if(!f.is_open()){
        cout << "Can not open file" << endl;
    }
    else{
        loadFractionArray(f, a, n);
        printFractionArray(a, n);
        f.close();
    }
    return 0;
}

void loadFraction(ifstream &f, Fraction &p){
    f >> p.num;
    f >> p.denom;
}
void printFraction(Fraction p){
    cout << p.num << "/" << p.denom << endl;
}
void loadFractionArray(ifstream &f, Fraction a[], int &n){
    f >> n;
    for(int i = 0; i < n; i++){
        loadFraction(f, a[i]);
    }
}
void printFractionArray(Fraction a[], int n){
    cout << "Number of elements: " << n << endl;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        printFraction(a[i]);
    }
}
