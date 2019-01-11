#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

queue<P> movePoint;
queue<P> answerPoint;
int map[21][21] = { 0 };
int mapSize = 0;
int fish[7] = { 0 };
int answer = 0;
int nowLevel = 1;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
bool checkmap[21][21] = { true };

struct Shark {

    int size = 2;
    int eat = 0;
    int x;
    int y;

};

Shark babaShark;

void setting(int tmp, int y, int x) {
    if (tmp == 9) {
        map[y][x] = 0;
        babaShark.x = x;
        babaShark.y = y;
        movePoint.push({ babaShark.y,babaShark.x });
    }
    else if (tmp == 1) {
        fish[1]++;
    }
    else if (tmp == 2) {
        fish[2]++;
    }
    else if (tmp == 3) {
        fish[3]++;
    }
    else if (tmp == 4) {
        fish[4]++;
    }
    else if (tmp == 5) {
        fish[5]++;
    }
    else if (tmp == 6) {
        fish[6]++;
    }
}

void input() {
    cin >> mapSize;
    for (int i = 0; i< mapSize; i++) {
        for (int j = 0; j<mapSize; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
            setting(tmp, i, j);
        }
    }

}

void clearQueue() {
    while (movePoint.size()>0) {
        movePoint.pop();
    }
}


void answerCheck() {
    int x = mapSize;
    int y = mapSize;

    while (answerPoint.size() > 0) {
        P tmp = answerPoint.front();
        answerPoint.pop();
        if (tmp.first < y) {
            y = tmp.first;
            x = tmp.second;
        }
        else if (tmp.first == y) {
            if (tmp.second < x) {
                y = tmp.first;
                x = tmp.second;
            }
        }
    }

    map[y][x] = 0;
    fish[nowLevel]--;
    clearQueue();
    movePoint.push({ y,x });
    babaShark.eat++;
    if (babaShark.eat == babaShark.size) {
        babaShark.size++;
        babaShark.eat = 0;
    }


}


void check(int y, int x) {

    if (map[y][x]<babaShark.size & map[y][x] != 0) {
        answerPoint.push({ y,x });
    }
    else if (map[y][x] == babaShark.size || map[y][x] == 0) {
        movePoint.push({ y,x });
    }


}


int findOne() {
    bool find = true;
    int count = 0;
    int size = movePoint.size();
    while (find & size>0) {
        count++;
        for (int k = 0; k < size; k++) {
            P tmp = movePoint.front();
            movePoint.pop();
            if (checkmap[tmp.first][tmp.second]) {
                checkmap[tmp.first][tmp.second] = false;
                for (int i = 0; i < 4; i++) {
                    if (tmp.first + dy[i] >= 0 & tmp.second + dx[i] >= 0 & tmp.first + dy[i]<mapSize & tmp.second + dx[i]<mapSize) {
                        check(tmp.first + dy[i], tmp.second + dx[i]);
                    }
                }
            }
        }
        if (answerPoint.size()>0) {
            answerCheck();
            return count;
        }
        size = movePoint.size();
    }
    return 0;
}

void refreshCheckMap() {
    for (int i = 0; i<mapSize; i++) {
        for (int j = 0; j<mapSize; j++) {
            checkmap[i][j] = true;
        }
    }
}

/*
void print() {
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
*/

void levelfind() {
    while (fish[nowLevel]>0 & movePoint.size()>0) {
        refreshCheckMap();
        answer = answer + findOne();
        //print();
    }
    nowLevel++;
}

int main() {

    input();

    while (nowLevel < babaShark.size) {
        levelfind();
    }
    cout << answer;

}