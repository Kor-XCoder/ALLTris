#ifndef BAG_H
#define BAG_H
#include <queue>
#include <random>
using namespace std;

class Bag {
public:
	int getTetromino();
private:
    random_device rd; // �ʱ�ȭ ����� ŭ
	queue<int> q;
};

#endif // !BAG_H