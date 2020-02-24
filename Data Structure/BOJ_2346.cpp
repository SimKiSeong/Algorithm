#include <string>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

deque<int> numbers;
deque<int> values;

int abs(int num){
    if(num<0){
        return -num;
    }
    return num-1;
}

int findDir(int num){
    // 왼쪽
    if(num < 0){
        return 2;
    }
    // 오른
    return 1;
}

int main(){

    int n;

    cin >> n;

    for(int i = 0; i<n;i++){
        int tmp;
        cin >> tmp;
        numbers.push_back(i+1);
        values.push_back(tmp);
    }


    int counter = 1;
    int move = abs(values[0]);
    int dir = findDir(values[0]);
    cout << numbers[0] << " ";
    numbers.pop_front();
    values.pop_front();

    while(counter != n){

        if(dir == 1) {
            for (int i = 0; i <move;i++){
                numbers.push_back(numbers[0]);
                values.push_back(values[0]);
                numbers.pop_front();
                values.pop_front();
            }
            cout << numbers[0] << " ";
            move = abs(values[0]);
            dir = findDir(values[0]);
            numbers.pop_front();
            values.pop_front();

        }else{
            for (int i = 0; i <move;i++){
                numbers.push_front(numbers[numbers.size()-1]);
                values.push_front(values[values.size()-1]);
                numbers.pop_back();
                values.pop_back();
            }
            cout << numbers[0] << " ";
            move = abs(values[0]);
            dir = findDir(values[0]);
            numbers.pop_front();
            values.pop_front();
        }
        counter++;
    }



    return 0;
}