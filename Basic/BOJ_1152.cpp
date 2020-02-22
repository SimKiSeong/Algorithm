#include<iostream>
#include<stdio.h>
using namespace std;

int main() {

    char a[1000001];
    int space = 0;

    for (int i = 0; i < 1000001; i++) {
        a[i] = 0;
    }

    cin.getline(a,1000001);

    int i = 0;
    if(a[0]==' '){
        i++;
    }

    for (;a[i] != 0; i++) {
        if (a[i] == ' ') {
            space++;
        }
        else if (a[i + 1] == 0& a[i] != ' ') {
            space++;
        }
    }

    cout << space;

    return 0;
}