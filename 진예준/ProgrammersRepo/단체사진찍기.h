#pragma once
#include "Solution.h"


class 단체사진찍기 : public Solution
{
public:
	virtual void 진행() override;
private:
	int solution(int n, vector<string> data);
};

