#include<iostream>
using namespace std;

int home[1000][3];
int cost[1000][3];

int small(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}


void findCost(int a, int b){
    if (b == 0){
        cost[a][0] = small(cost[a - 1][1], cost[a - 1][2]) + home[a][0];
    }
    else if (b == 1){
        cost[a][1] = small(cost[a - 1][0], cost[a - 1][2]) + home[a][1];
    }
    else{
        cost[a][2] = small(cost[a - 1][1], cost[a - 1][0]) + home[a][2];
    }

}

int main(){

    int a = 0;
    cin >> a;

    for (int i = 0; i < a; i++){
        for (int j = 0; j < 3; j++){
            cin >> home[i][j];
        }
    }

    cost[0][0] = home[0][0];
    cost[0][1] = home[0][1];
    cost[0][2] = home[0][2];

    for (int i = 1; i < a; i++){
        for (int j = 0; j < 3; j++){
            findCost(i, j);
        }
    }

    cout << small(cost[a - 1][0], small(cost[a - 1][1], cost[a - 1][2]));

    return 0;
}

