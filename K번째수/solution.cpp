#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int Idx = 0; Idx < commands.size(); ++Idx) {
		int i = commands[Idx][0] - 1;
		int j = commands[Idx][1] - 1;
		int k = commands[Idx][2] - 1;
		vector<int> tempVec(array.begin() + i, array.begin() + j + 1);
		sort(tempVec.begin(), tempVec.end());
		answer.push_back(tempVec[k]);
	}

	return answer;
}