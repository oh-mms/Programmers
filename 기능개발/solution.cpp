#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int remain;
	vector<int> remainProgresses;
	for (int i = 0; i < progresses.size(); ++i) {
		remain = ceil((double)(100 - progresses[i]) / speeds[i]);
		remainProgresses.push_back(remain);
	}
	remainProgresses.push_back(101); // remain ���Ϳ� �� ������ ���� �־��� �� �ֵ��� �ְ��� �־���.

	int count = 1, max = remainProgresses[0];
	for (int i = 1; i < remainProgresses.size(); ++i) {
		if (max < remainProgresses[i]) {
			max = remainProgresses[i];
			answer.push_back(count);
			count = 1;
		}
		else
			count++;
	}

	return answer;
}