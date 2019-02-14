#include<iostream>
#include<algorithm>
using namespace std;

int time[1002];
int a;
int sum = 0;

bool compare(int b,int c) {

    return b > c;
}

int main() {

    cin >> a;

    for (int i = 0; i < a; i++) {
        cin >> time[i];

    }

    sort(time, time + a,compare);

    for (int i = 0; i < a; i++) {
        sum = sum + time[i] * (i + 1);
    }
    cout << sum;
    return 0;

}