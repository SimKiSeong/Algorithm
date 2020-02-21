#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> ganseon;
vector<int> parent;
int n;

void findParent(int now){
    if(ganseon[now].size()==0){
        return;
    }
    for(int i = 0;i<ganseon[now].size();i++){
        if(parent[ganseon[now][i]]==0) {
            parent[ganseon[now][i]] = now;
            findParent(ganseon[now][i]);
        }
    }
}

int main() {
    cin >> n;
    ganseon.resize(n+1);
    parent.resize(n+1);

    parent[1] = -1;

    for(int i = 0; i<n-1;i++){
        int tmp1;
        int tmp2;
        cin >> tmp1;
        cin >> tmp2;
        ganseon[tmp1].push_back(tmp2);
        ganseon[tmp2].push_back(tmp1);
    }

    findParent(1);

    for(int i = 2; i<=n;i++){
        cout << parent[i] << "\n";
    }


    return 0;
}