#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k = 0;
int cont = 0;
vector<int> sosu;
bool chae[10000000];

int main()
{
    cin >> k;

    for (int i = 2; i < 10000000; i++) {
        if (!chae[i]) {
            sosu.push_back(i);
            for (int j = 0; i*j < 10000000; j++) {
                chae[i*j] = true;
            }
        }
    }

    cout << sosu[k-1];



    return 0;
}