#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int cCheck[102];
int net[102][102];
int n;
queue<int> now;

void spread() {
    int size = now.size();
    if (size == 0) {
        return;
    }
    for (int j = 0; j < size; j++) {
        int tem = now.front();
        now.pop();
        for (int i = 1; i < n + 1; i++) {
            if (net[tem][i] == 1) {
                if (cCheck[i] == 0) {
                    cCheck[i] = 1;
                    now.push(i);
                }
            }
        }
    }
    spread();
}


int main() {
    cin >> n;

    for (int i = 0; i < n+1; i++) {
        cCheck[i] = 0;
    }

    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int tem1;
        int tem2;
        cin >> tem1 >> tem2;
        net[tem1][tem2] = 1;
        net[tem2][tem1] = 1;
    }

    cCheck[1] = 1;
    now.push(1);
    spread();

    int count = 0;
    for (int i = 2; i < n + 1; i++) {
        if (cCheck[i] == 1) {
            count++;
        }
    }
    cout << count;

}