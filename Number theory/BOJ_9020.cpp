#include <iostream>
#include <algorithm>
using namespace std;

int sosu[10002] = {0};

int main()
{

    sosu[0] = 0;
    sosu[1] = 1;

    for (int i = 2; i < 10002; i++){
        if (sosu[i] == 0){
            for (int j = i+i; j < 10002; j = j + i){
                sosu[j] = 1;
            }
        }
    }



    int t;
    cin >> t;

    for (int z = 0; z < t; z++){
        int n;
        cin >> n;

        int tem1 = n / 2;
        int tem2 = n / 2;

        while (sosu[tem1] == 1 || sosu[tem2] == 1){
            tem1--;
            tem2++;
        }
        cout << tem1 <<" "<< tem2 << endl;
    }



    return 0;
}