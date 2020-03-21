#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long tri[101];

int main() {

    tri[1] = 1;
    tri[2] = 1;
    tri[3] = 1;
    tri[4] = 2;
    tri[5] = 2;
    tri[6] = 3;
    tri[7] = 4;
    tri[8] = 5;
    tri[9] = 7;
    tri[10] = 9;

    for (int i = 9; i < 101; i++) {
        tri[i] = tri[i - 1] + tri[i - 5];
    }

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int tmp;
        cin >> tmp;
        cout << tri[tmp]<<'\n';
    }

    return 0;
}