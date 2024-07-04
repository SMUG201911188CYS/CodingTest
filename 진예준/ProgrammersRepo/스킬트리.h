#pragma once
#include "Solution.h"

using namespace std;

class 스킬트리 : public Solution
{
public:
	virtual void 진행() override;
private:
	int solution(string skill, vector<string> skill_trees);
};

