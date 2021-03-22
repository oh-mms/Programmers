#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int sum = brown + yellow;
	for (int height = 2; height <= sum / 2; ++height) {
		if (sum%height == 0) {
			int temp = (sum / height) * 2 + (height * 2) - 4;
			if (temp == brown) {
				answer.push_back(sum / height);
				answer.push_back(height);
				break;
			}
		}
	}
	return answer;
}