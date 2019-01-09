#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int m;
vector<int> number;

bool sort(int num, int first, int last) {
	if (first > last) {
		return false;
	}

	int mid = (first + last) / 2;

	if (number[mid] == num) {
		return true;
	}
	else if (number[mid] > num) {
		return sort(num, first, mid - 1);
	}
	else {
		return sort(num, mid + 1, last);
	}

}

int main()
{

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		number.push_back(tmp);
	}

	sort(number.begin(), number.end());

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);

		if (sort(tmp, 0, n-1)) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}

	}

}