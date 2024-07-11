#pragma once
#include "Solution.h"
class 카카오프렌즈컬러링북 : public Solution
{
public:
	virtual void 진행() override;
private:
	vector<int> solution(int m, int n, vector<vector<int>> picture);
};

