#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int a;
int b;
int c;

int main() {

    cin >> a >> b >> c;

    int boonki = c - b;

    if (boonki <= 0) {
        cout << -1;
        return 0;
    }

    cout << a/boonki+1;

    return 0;
}