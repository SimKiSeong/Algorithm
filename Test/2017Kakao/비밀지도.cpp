#include <string>
#include <vector>

using namespace std;

int length;
vector<string> map1;
vector<string> map2;

string binary(int n) {
    string answer = "";
    if (n == 0) {
        answer = " ";
    }

    else {
        while (n > 1) {
            if (n % 2 == 0) {
                answer = " " + answer;
            }
            else {
                answer = +"#" + answer;
            }
            n = n / 2;
        }
        answer = "#" + answer;
    }

    while (answer.size() < length) {
        answer = " " + answer;
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    vector<string> answer;

    length = n;

    for (int i = 0; i < n; i++) {
        map1.push_back(binary(arr1[i]));
        map2.push_back(binary(arr2[i]));
    }

    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == '#' || map2[i][j] == '#') {
                tmp = tmp + "#";
            }
            else {
                tmp = tmp + " ";
            }
        }
        answer.push_back(tmp);
    }

    return answer;


}