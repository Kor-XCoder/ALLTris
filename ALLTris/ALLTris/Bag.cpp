#include "Bag.h"
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int Bag::getTetromino() {
	if (!q.empty()) { // 큐가 비지 않았다면
		int x = q.front(); q.pop();
		return x;
	} else {
		mt19937 gen(rd());
		vector<int> r = { 1, 2, 3, 4, 5, 6, 7 };
		shuffle(r.begin(), r.end(), gen);
		for (int& x : r) {
			q.push(r);
		}
	}
}