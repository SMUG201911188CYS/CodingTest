#pragma once
#include "Solution.h"


using namespace std;

class 프로세스 : public Solution
{
public:
	virtual void 진행() override;
private:
	int solution(vector<int> priorities, int location);
};

