#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n;

// 와이
int r;
// 엑스
int c;

vector<int> two;

void zForce(int startY, int startX, int size, int startNum) {

    int sMeaon = 0;
    int point = (size * size) / 4;

    //x 판별
    if (c < (startX + (size / 2))) {
        sMeaon = 0;
    } else {
        sMeaon = 1;
    }

    //y 판별
    if (r < (startY + (size / 2))) {

    } else {
        sMeaon = sMeaon + 2;
    }

    // 정답 찾기
    if (size == 2) {
        cout << (startNum + sMeaon);
        return;
    }
        // 사분면 나누기
    else {

        // 1사분면
        if (sMeaon == 0) {
            zForce(startY, startX, size / 2, startNum);
        }
        // 2사분면
        if (sMeaon == 1) {
            zForce(startY, startX + (size / 2), size / 2, startNum + point);
        }

        // 3사분면
        if (sMeaon == 2) {
            zForce(startY + (size / 2), startX, size / 2, startNum + (point * 2));
        }
        // 4사분면
        if (sMeaon == 3) {
            zForce(startY + (size / 2), startX + (size / 2), size / 2, startNum + (point * 3));
        }


    }


}


int main() {

    cin >> n >> r >> c;

    int size = 1;

    for (int i = 0; i < n; i++) {
        size = size * 2;
    }

    zForce(0, 0, size, 0);

    return 0;
}