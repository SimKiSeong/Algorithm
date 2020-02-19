#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int a;
int b;
int v;

int main() {

    cin >> a >> b >> v;

    v = v - a;

    if(v%(a-b)==0) {
        cout << v / (a - b) + 1;
    }
    else{
        cout << v / (a - b) + 2;
    }

    return 0;
}