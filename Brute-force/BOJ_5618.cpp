#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> soo;

int main() {

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        soo.push_back(tmp);
    }

    sort(soo.begin(), soo.end());

    if (n == 2) {
        for (int i = 1; i <= soo[0]; i++) {
            if (soo[0] % i == 0 && soo[1] % i == 0) {
                cout << i <<"\n";
            }
        }
    }
    else {
        for (int i = 1; i <= soo[0]; i++) {
            if (soo[0] % i == 0 && soo[1] % i == 0 && soo[2] % i == 0) {
                cout << i << "\n";
            }
        }

    }


    return 0;
}