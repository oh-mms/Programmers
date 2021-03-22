#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 10000; i > 0; --i) {
		auto iter = lower_bound(citations.begin(), citations.end(), i);
		int count = citations.end() - iter;
		if (i <= count) {
			answer = i;
			break;
		}
	}

	return answer;
}