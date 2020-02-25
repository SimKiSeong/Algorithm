#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

// 땅의 크기 n n
int n;

// 나무의 개수
int m;

// k년이 지난후 나무의 개수
int k;

int s2d2[11][11];
int soil[11][11];
int kill[11][11];
deque<int> map[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void sortTree(){
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            sort(map[i][j].begin(),map[i][j].end());
        }
    }
}

void checkSpring(deque<int> tree, int x, int y) {
    kill[y][x] = -1;
    for (int i = 0; i < tree.size(); i++) {
        if (tree[i] <= soil[y][x]) {
            soil[y][x] = soil[y][x] - tree[i];
            map[y][x][i]++;
        } else {
            kill[y][x] = i;
            break;
        }
    }
}

void spring() {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            checkSpring(map[i][j],j,i);
        }
    }
}

void checkSummer(deque<int> tree, int x, int y) {
    if(kill[y][x]>=0) {
        for (int i = tree.size()-1; i >= kill[y][x]; i--) {
            int nSoil = tree[i]/2;
            soil[y][x] = soil[y][x] + nSoil;
            map[y][x].pop_back();
        }
    }
}


void summer(){
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            checkSummer(map[i][j],j,i);
        }
    }
}

void spread(int x, int y) {
    for (int i = 0; i < 8; i++) {
        if(y + dy[i]>0&&y + dy[i]<n+1&x + dx[i]>0&x + dx[i]<n+1) {
            map[y + dy[i]][x + dx[i]].push_back(1);
        }
    }
}

void checkFall(deque<int> seed, int x, int y) {
    for (int i = 0; i < seed.size(); i++) {
        if (seed[i] % 5 == 0) {
            spread(x, y);
        }
    }
}

void fall() {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            checkFall(map[i][j], j, i);
        }
    }
}

void winter() {
    sortTree();
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            soil[i][j] = soil[i][j] + s2d2[i][j];
        }
    }

}

int countAnswer(){
    int answer = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            answer = answer + map[i][j].size();
        }
    }
    return answer;
}

int main() {

    // 처음에는 모든 땅에 양분이 5씩 있다
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            soil[i][j] = 5;
        }
    }

    // 입력을 받는다.
    cin >> n >> m >> k;

    // 기계가 양분을 주는 설정?을 한다
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cin >> s2d2[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y].push_back(z);
    }

    sortTree();

    for(int i = 0; i<k;i++){
        spring();
        summer();
        fall();
        winter();
    }

    cout << countAnswer();

    return 0;
}