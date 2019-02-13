#include<iostream>
#include<algorithm>
using namespace std;

int dot[1001];
int n;
int ans;

bool find(int low,int high,int number) {
    if (low > high) {
        return false;
    }
    else {
        int mid = (low + high) / 2;
        if (dot[mid] == number) {
            return true;
        }else if(dot[mid]<number){
            return find(mid + 1, high, number);
        }
        else {
            return find(low, mid-1, number);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> dot[i];
        }
        sort(dot, dot + n);
        for (int i = 0; i < n-2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (find(j+1,n-1,2*dot[j]-dot[i])) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}