#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int apt[15][15];

int main() {

    for (int i = 1; i < 15; i++) {
        apt[0][i] = i;
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            int tmp = 0;
            for (int k = 1; k <= j; k++) {
                tmp = tmp + apt[i - 1][k];
            }
            apt[i][j] = tmp;
        }
    }

    int z;
    cin >> z;
    for (int i = 0;  i < z; i++) {
        int a,b;
        cin >> a >> b;
        cout << apt[a][b] << endl;
    }


}