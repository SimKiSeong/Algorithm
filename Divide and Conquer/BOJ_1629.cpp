#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int a;
int b;
int c;

vector<long long> numbers;
vector<int> address;

long long divide(long long now) {
    long long tmp = now * now;

    return tmp % c;
}

int main() {

    cin >> a;
    cin >> b;
    cin >> c;

    long long counter = 1;
    numbers.push_back(a % c);
    address.push_back(counter);

    int ans = 1;


    // divide
    while (counter * 2 < b) {
        numbers.push_back(divide(numbers[numbers.size() - 1]));
        counter = counter * 2;
        address.push_back(counter);
    }


    // conqure

    while (b > 0) {
        int tmp = address.size() - 1;
        while (address[tmp] > b) {
            tmp--;
        }
        ans = (ans * numbers[tmp] % c);
        b = b - address[tmp];
    }

    cout << ans;

    return 0;
}