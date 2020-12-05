//
//  main.cpp
//  Demo07-SaveFractionArrayToTextFile
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

void inputFraction(Fraction &p);
void saveFraction(ofstream &f, Fraction p);

void inputFractionArray(Fraction a[], int &n);
void saveFractionArray(ofstream &f, Fraction a[], int n);

int main(int argc, const char * argv[]) {
    Fraction a[100];
    int n = 0;
    ofstream f;
    
    inputFractionArray(a, n);
    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo07-SaveFractionArrayToTextFile/Demo07-SaveFractionArrayToTextFile/fractionarray-output.txt");
    if(!f.is_open()){
        cout << "Can not create file" << endl;
    }
    else{
        saveFractionArray(f, a, n);
        f.close();
    }
    return 0;
}

void inputFraction(Fraction &p){
    cout << "Numerator: ";
    cin >> p.num;
    cout << "Denominator: ";
    cin >> p.denom;
}
void saveFraction(ofstream &f, Fraction p){
    f << p.num << " " << p.denom << endl;
}
void inputFractionArray(Fraction a[], int &n){
    cout << "Number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: " << endl;
        inputFraction(a[i]);
    }
}
void saveFractionArray(ofstream &f, Fraction a[], int n){
    f << n << endl;
    for(int i = 0; i < n; i++){
        saveFraction(f, a[i]);
    }
}
