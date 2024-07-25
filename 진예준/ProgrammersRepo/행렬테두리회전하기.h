#pragma once
#include "Solution.h"
class 행렬테두리회전하기 :public Solution
{
public:
	void 진행() override;
private:
	vector<int> solution(int rows, int columns, vector<vector<int>> queries);

};

