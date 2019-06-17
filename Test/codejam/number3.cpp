#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int q;

int map[106][106];

class Person{

public:
    int x;
    int y;
    char dir;

public:
    Person(int x1, int y1, char dir1){
        x = x1;
        y = y1;
        dir = dir1;
    }
};

vector<Person> people;

void initMap(){
    for(int i = 0 ; i<106;i++){
        for(int j = 0 ; j<106;j++){
            map[i][j] = 0;
        }
    }
}

int checkNumber(int i1, int j1){
    int ans = 0;

    for(int i =0;i<people.size();i++){
        char nowDir = people[i].dir;
        if(nowDir =='N'){
            if(people[i].y<i1){
                ans++;
            }
        }
        if(nowDir =='S'){
            if(people[i].y>i1){
                ans++;
            }
        }
        if(nowDir =='W'){
            if(people[i].x>j1){
                ans++;
            }
        }
        if(nowDir =='E'){
            if(people[i].x<j1){
                ans++;
            }
        }

    }

    return ans;
}

void checkMap(){
    for(int i = 0; i<106;i++){
        for(int j = 0; j<106;j++){
            map[i][j] = checkNumber(i,j);
        }
    }
}

int bigNumber(){
    int big = 0;
    for(int i = 0 ; i<106;i++){
        for(int j = 0 ; j<106;j++){
            if(map[i][j]>big){
                big = map[i][j];
            }
        }
    }
    return big;
}

int findAnswer(int find){
    for(int j = 0; j<106;j++){
        for(int i=0;i<106;i++){
            if(map[i][j]==find){
                cout << j << " " << i<<endl;
                return 0;
            }
        }
    }
}

int main() {

    int t;
    cin >> t;
    for(int z=0;z<t;z++){
        initMap();
        cin >> n >> q;
        people.clear();


        for(int i = 0;i<n;i++){
            int x,y;
            char dir;
            cin >> x >>y >>dir;
            Person tmp = Person(x,y,dir);
            people.push_back(tmp);
        }

        checkMap();

        int findNumber = bigNumber();

        cout << "Case #" <<z+1<<": ";
        findAnswer(findNumber);
    }

    return 0;
}