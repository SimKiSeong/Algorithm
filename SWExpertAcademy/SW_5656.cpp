#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;
int n, w, h;
int nowBrick[13][15];
int nowDeleted = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void downBrick() {

    for (int j = 0; j < w; j++) {
        for (int i = h-1; i >= 0; i--) {
            if (nowBrick[i][j] != 0) {
                int now = i;
                while (now < h-1) {
                    if (nowBrick[now+1][j] != 0) {
                        break;
                    }
                    now++;
                }
                if (now != i) {
                    nowBrick[now][j] = nowBrick[i][j];
                    nowBrick[i][j] = 0;
                }
            }
        }
    }

}


void deleteBrick(int sero,int garo) {
    if (nowBrick[sero][garo] != 0) {
        int rotate = nowBrick[sero][garo];
        nowBrick[sero][garo] = 0;
        nowDeleted++;
        for (int i = 1; i < rotate; i++) {
            for (int j = 0; j < 4; j++) {
                deleteBrick(sero+(dy[j]*i),garo+(dx[j]*i));
            }
        }
    }
}

void shoot(int now,int deleted,int brick[13][15]) {
    if (now == 0) {
        if (deleted > answer) {
            answer = deleted;
        }
    }
    else {
        for (int k = 0; k < w; k++) {

            int top = 0;
            nowDeleted = deleted;

            // 지금 쓸거 복사
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 15; j++) {
                    nowBrick[i][j] = brick[i][j];
                }
            }

            while (nowBrick[top][k] == 0) {
                top++;
            }

            deleteBrick(top, k);



            downBrick();


            shoot(now - 1, nowDeleted, nowBrick);

        }
    }

}

int main() {

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        // 변수 생성
        int brick[13][15];

        answer = 0;

        //변수 입력
        cin >> n >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> brick[i][j];
            }
        }

        shoot(n,0,brick);

        cout << "#" << z + 1 << " " << answer << endl;

    }


}