#include<iostream>
using namespace std;

int chek(int a){
    if (a == 2){
        return 1;
    }
    if (a % 2 == 0 | a == 1){
        return 0;
    }
    else{
        for (int i = 1; 2*( 2 * i + 1) < a; i++){
            if (a % (2 * i + 1) == 0){
                return 0;
            }
        }
    }
    return 1;
}


int main(){

    int a;
    int sosu[100];
    int num = 0;

    cin >> a;

    for (int i = 0; i < a; i++){
        cin >> sosu[i];
        num = num + chek(sosu[i]);
    }

    cout << num;

    return 0;

}

