#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> P;

char farm[10][10];
int checkFarm[10][10];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int startY = 0;
int startX = 0;
int answer = 0;

queue<P> point;

void checkPoint(P p){
    if(farm[p.first][p.second]=='L'){
        cout << answer-1;
        exit(0);
    }
    for(int i = 0; i<4;i++){
        int tmpY = p.first+dy[i];
        int tmpX = p.second+dx[i];
        if(tmpY>=0&&tmpX>=0&&tmpY<10&&tmpX<10){
            if(checkFarm[tmpY][tmpX]==0){
                checkFarm[tmpY][tmpX] = 1;
                point.push(make_pair(tmpY,tmpX));
            }
        }
    }
}

int main() {

    for(int i = 0; i<10;i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j <10; j++){
            farm[i][j] = tmp[j];
            if(tmp[j]=='B'){
                point.push(make_pair(i,j));
            }
            if(tmp[j]=='R'){
                checkFarm[i][j] = 1;
            }
        }
    }

    int size = point.size();
    while(size>0){
        for(int i = 0; i<size;i++){
            checkPoint(point.front());
            point.pop();
        }
        answer++;
        size = point.size();
    }


    return 0;
}