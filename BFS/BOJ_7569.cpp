#include <iostream>
#include <utility>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
    int z;
};

int box[102][102][102] = {-1};
int leftTomato = 0;
queue<point> checkPoint;
int m, n, h;
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
bool findAnswer = false;
bool isChanged = false;
int answer = 0;

// 입력을 받는 메소드
void getInput() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int tmp;
                cin >> tmp;
                box[i][j][k] = tmp;

                // 남은 토마토의 개수를 새는 곳
                if (tmp == 0) {
                    leftTomato++;
                }

                // 익은 토마토의 좌표를 넣는 곳
                if (tmp == 1) {
                    point p;
                    p.x = k;
                    p.y = j;
                    p.z = i;
                    checkPoint.push(p);
                }

            }
        }
    }
}

void firstCheck() {
    if (leftTomato == 0) {
        findAnswer = true;
    }
}

void checkAnswer() {
    if (leftTomato == 0) {
        findAnswer = true;
    } else {
        if (!isChanged) {
            findAnswer = true;
            answer = -1;
        } else {
           isChanged = false;
        }
    }
}

void checkPush(point newP) {
    if (newP.x >= 0 & newP.y >= 0 & newP.z >= 0 & newP.x < m & newP.y < n & newP.z < h) {
        if (box[newP.z][newP.y][newP.x] == 0) {
            box[newP.z][newP.y][newP.x] = 1;
            checkPoint.push(newP);
            leftTomato--;
            isChanged = true;
        }
    }
}

void ripe(point p) {
    for (int i = 0; i < 6; i++) {
        point newP;
        newP.x = p.x + dx[i];
        newP.y = p.y + dy[i];
        newP.z = p.z + dz[i];
        checkPush(newP);
    }
}


void runTomato() {
    int size = checkPoint.size();
    firstCheck();
    while (size > 0 & !findAnswer) {
        for (int i = 0; i < size; i++) {
            point p = checkPoint.front();
            checkPoint.pop();
            ripe(p);
        }
        answer++;
        checkAnswer();
        size = checkPoint.size();
    }
}


int main() {

    cin >> m >> n >> h;
    getInput();
    runTomato();
    cout << answer;
    return 0;
}
