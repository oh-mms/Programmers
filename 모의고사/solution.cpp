#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	const vector<int> sol1{ 1, 2, 3, 4, 5 };
	const vector<int> sol2{ 2, 1, 2, 3, 2, 4, 2, 5 };
	const vector<int> sol3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	vector<int> count(3, 0);

	for (int i = 0; i < answers.size(); ++i) {
		if (answers[i] == sol1[i % 5]) count[0]++;
		if (answers[i] == sol2[i % 8]) count[1]++;
		if (answers[i] == sol3[i % 10]) count[2]++;
	}
	vector<int> answer;
	auto iter = max_element(count.begin(), count.end());
	int max = *iter; *iter = -1; answer.push_back(iter - count.begin() + 1);
	iter = max_element(count.begin(), count.end());
	if (max == *iter) { *iter = -1; answer.push_back(iter - count.begin() + 1); }
	iter = max_element(count.begin(), count.end());
	if (max == *iter) { *iter = -1; answer.push_back(iter - count.begin() + 1); }
	return answer;
}