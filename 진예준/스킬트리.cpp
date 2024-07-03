
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(string skill, vector<string> skill_trees)
{
	int anwser = 0;

	for (auto& skill_tree : skill_trees)
	{
		vector<string::iterator> got_skills = {}; //스킬 트리 안에 선행스킬에 해당하는지;

		bool success = true;
		//선행 스킬이 스킬트리에 있으면 넣는다.
		for (auto i : skill)
		{
			auto a = find(skill_tree.begin(), skill_tree.end(), i);
			//if (a != skill_tree.end())
			if (true)
			{
				got_skills.push_back(a);
			}
		}

		for (int i = 0; i < got_skills.size() - 1; i++)
		{
			if (got_skills[i] > got_skills[i + 1])
			{
				success = false;
				break;
			}
		}

		if (success)
		{
			//cout << "A " << skill_tree << endl;
			anwser++;
		}

	}
	return anwser;
}
