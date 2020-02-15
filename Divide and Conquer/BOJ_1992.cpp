#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> papers;

int map[65][65];
int n = 0;

void divide(int y, int x, int size) {

    bool same = true;
    int my = map[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (map[i][j] != my) {
                same = false;
                break;
            }
        }
        if (!same) {
            break;
        }
    }

    if (same) {
        cout << my;
        return;
    }
    cout << '(';

    for (int i = y; i < y + size; i = i + (size / 2)) {
        for (int j = x; j < x + size; j = j + (size / 2)) {
            divide(i, j, size / 2);
        }
    }

    cout << ')';
}

int main() {

    cin >> n;

    char tmp;
    scanf("%1c", &tmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1c", &tmp);
            if (tmp == '1') {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
        scanf("%1c", &tmp);
    }

//    for(int i = 0; i<n;i++){
//        for(int j = 0; j<n;j++){
//            cout << map[i][j];
//        }
//        cout << endl;
//    }
//    cin >> n;

    divide(0, 0, n);


    return 0;
}