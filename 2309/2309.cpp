#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int sum;
pair<int, int> res;
vector<int> v, result;

// N이 작기 때문에 next_permutation을 활용해서 모든 경우 고려하는 것도 가능(조합 구현 대신) : 9C7대신 9P7로
// 필요한 부분만 잘라서
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);

	for (auto i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		sum += temp;
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if ((sum - v[i] - v[j]) == 100) {
				res = make_pair(i, j);
				break;
			}
		}
	}

	for (auto i = 0; i < v.size(); i++) {
		if (i == res.first || i == res.second) {
			continue;
		}

		result.push_back(v[i]);
	}

	sort(result.begin(), result.end());

	for (auto i : result) {
		cout << i << "\n";
	}

	return 0;
}