#ifndef BAG_H
#define BAG_H
#include <queue>
#include <random>
using namespace std;

class Bag {
public:
	int getTetromino();
private:
    random_device rd; // 초기화 비용이 큼
	queue<int> q;
};

#endif // !BAG_H