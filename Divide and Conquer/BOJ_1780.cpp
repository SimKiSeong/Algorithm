#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> papers;

int map[2200][2200];
int n = 0;

void checker(int y, int x, int size) {

    int my = map[y][x];
    bool pass = true;

    //색종이가 같은지 확인
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if( my != map[i][j] ){
                pass = false;
                break;
            }
        }
        if(!pass){
            break;
        }
    }

    if(pass){
        papers.push_back(my);
        return;
    }

    for(int i = y; i<y+size; i = i + size/3){
        for(int j = x; j<x+size; j = j + size/3){
            checker(i,j,size/3);
        }
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    checker(0,0,n);

    int minus = 0;
    int zero = 0;
    int plus = 0;
    for(int i = 0; i<papers.size();i++){
        if(papers[i]<0){
            minus++;
        }else if(papers[i]>0){
            plus++;
        }
        else{
            zero++;
        }
    }

    cout << minus << endl;
    cout << zero << endl;
    cout << plus << endl;

    return 0;
}