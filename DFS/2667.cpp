#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> danzi;
int apt[27][27] = {0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int num = 0;
int dNum = -1;

void search(int a,int b) {

    if (apt[a][b] == 0) {
        return;
    }
    danzi[dNum]++;
    apt[a][b] = 0;
    for (int i = 0; i < 4; i++) {
        if (a + dx[i] < num && b + dy[i] < num && a + dx[i] > -1 && b + dy[i] > -1) {
            search(a + dx[i], b + dy[i]);
        }
    }
}

int main() {
    cin >> num;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%1d", &apt[i][j]);
        }
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (apt[i][j] == 1) {
                dNum++;
                danzi.push_back(0);
                search(i, j);
            }
        }
    }

    sort(danzi.begin(), danzi.end());

    cout << ++dNum <<endl;
    for (int i = 0; i < danzi.size(); i++) {
        cout << danzi[i] << endl;
    }


    return 0;
}