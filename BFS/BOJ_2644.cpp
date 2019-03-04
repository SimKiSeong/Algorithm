#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int gazok[101][101];
int check[101];

queue<int> chon;
int a;

int start;
int finish;

int num;

void find() {


    int size = chon.size();
    if (size == 0) {
        num = -1;
        return;
    }
    else {
        num++;
        for (int i = 0; i < size; i++) {
            int find = chon.front();
            chon.pop();
            for (int j = 0; j < a+1; j++) {
                if (gazok[find][j] == 1 && check[j] == 0) {
                    chon.push(j);
                    check[j] = 1;

                    if (j == finish) {
                        return;
                    }

                }
            }
        }

    }

    find();

}



int main(){
    num = 0;
    cin >> a;

    for (int i = 0; i < a+1; i++) {
        check[i] = 0;
        for (int j = 0; j < a+1; j++) {
            gazok[i][j] = 0;
        }
    }


    cin >> start >> finish;

    int b;
    cin >> b;
    for (int i = 0; i < b; i++) {
        int tem1;
        int tem2;
        cin >> tem1>> tem2;
        gazok[tem1][tem2] = 1;
        gazok[tem2][tem1] = 1;
    }

    chon.push(start);
    check[start] = 0;

    find();

    cout << num;
}