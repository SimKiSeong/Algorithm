#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

char map[51][51];
int n;
int answer = 0;

int big(int a,int b) {
    if (a < b) {
        return b;
    }
    return a;
}

void swap(char &a,char& b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int seroCounter(int x) {
    int num = 1;
    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (map[i][x] == map[i-1][x]) {
            num++;
        }
        else {
            if (ans < num) {
                ans = num;
            }
            num = 1;
        }
    }
    if (ans < num) {
        ans = num;
    }
    return ans;
}


int garoCounter(int y) {
    int num = 1;
    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (map[y][i] == map[y][i - 1]) {
            num++;
        }
        else {
            if (ans < num) {
                ans = num;
            }
            num = 1;
        }
    }
    if (ans < num) {
        ans = num;
    }
    return ans;
}

int counter() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = big(seroCounter(i),garoCounter(i));
        if (ans < tmp) {
            ans = tmp;
        }
    }
    return ans;
}

int seroChecker() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (map[i][j + 1] == map[i][j]) {
                continue;
            }
            swap(map[i][j+1], map[i][j]);
            int tmp = counter();
            if (tmp > ans) {
                ans = tmp;
            }
            swap(map[i][j+1], map[i][j]);
        }
    }
    return ans;
}

int garoChecker() {
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i+1][j] == map[i][j]) {
                continue;
            }

            swap(map[i + 1][j], map[i][j]);
            int tmp = counter();
            if (tmp > ans) {
                ans = tmp;
            }
            swap(map[i + 1][j], map[i][j]);
        }
    }
    return ans;
}


int main() {

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);


    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j];
        }
    }


    cout << big(seroChecker(),garoChecker());

    return 0;
}