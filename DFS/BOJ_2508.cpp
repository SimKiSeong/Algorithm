#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int sudo2[9][9]; // 도화지 같은 수도쿠
typedef pair<int, int> P;
queue <P> point;
bool stop;

bool check(P p) {
    int a = p.first;
    int b = p.second;
    bool chek = true;
    int tem = sudo2[a][b];

    //가로줄 확인
    for (int i = b + 1; i < 9; i++) {
        if (tem == sudo2[a][i]) {
            chek = false;
        }
    }

    //세로줄 확인
    for (int i = 0; i < 9; i++) {
        if ((a != i)&(tem == sudo2[i][b])) {
            chek = false;
        }
    }

    // 3바이 3확인
    for (int i = a / 3 * 3; i < (a / 3 + 1) * 3; i++) {
        for (int j = b / 3 * 3; j < (b / 3 + 1) * 3; j++) {
            if ((!((a == i) & (b == j)))&(tem == sudo2[i][j])) {
                chek = false;
            }
        }
    }

    return chek;
}

void loop(queue<P> a) {


    if (a.empty()) {
        stop = true;
        return;
    }

    queue<P> tmp = a;
    P now = tmp.front();
    tmp.pop();

    for (int i = 1; i < 10; i++) {

        sudo2[now.first][now.second] = i;
        bool go = false;
        for (int j = 0; j < now.second; j++) {
            if (i == sudo2[now.first][j]) {
                go = true;
            }
        }
        if (go) {

        }
        else if (check(now)) {
            loop(tmp);
        }
        if (stop) {
            return;
        }
    }
    sudo2[now.first][now.second] = 0;

}

int main() {


    // 숫자 입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin>>sudo2[i][j];
            if (sudo2[i][j] == 0) {
                P tem = make_pair(i, j);
                point.push(tem);
            }

        }

    }


    loop(point);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudo2[i][j]);
        }
        printf("\n");
    }

}