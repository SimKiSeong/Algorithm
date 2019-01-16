#include <iostream>
using namespace std;


int chess[15][15] = { 0 };
int n;
int can = 0;
int dx[4] = { -1, -1 ,1,1};
int dy[4] = { -1, 1 ,1,-1};


bool check(int a, int b){

    for (int i = 0; i < n; i++){
        if (chess[i][b] == 1){
            return false;
        }
    }

    // 4가지의 대각선 방향
    for (int i = 0; i < 4; i++){
        int tem1 = a+dy[i];
        int tem2 = b+dx[i];

        while (tem1>-1&&tem2>-1&&tem1<n&&tem2<n){
            if (chess[tem1][tem2] == 1){
                return false;
            }
            tem1 = tem1 + dy[i];
            tem2 = tem2 + dx[i];
        }
    }

    return true;

}

void lay(int now){
    if (now == n){
        can++;
        return;
    }
    else{
        for (int i = 0; i < n; i++){

            if (check(now,i)){
                chess[now][i] = 1;
                lay(now + 1);
                chess[now][i] = 0;
            }

        }
    }
}


int main() {

    cin >> n;

    lay(0);

    cout << can;

    return 0;
}