#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {

        int x, y;
        cin >> x >> y;
        int dis = y - x;
        int now = 1;

        while (now*2 <= dis) {
            dis -= now*2;
            now++;
        }


        if (dis == 0) {
            cout << (now - 1) * 2<<endl;
        }else if (now >= dis) {
            cout << (now - 1) * 2 + 1 << endl;
        }
        else{
            cout << (now - 1) * 2 + 2 << endl;
        }

    }

    return 0;
}