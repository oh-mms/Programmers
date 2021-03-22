#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0, minValue = people[0];
	sort(people.begin(), people.end());
	int lIdx = 0;
	int rIdx = people.size() - 1;
	while (lIdx <= rIdx) {
		int l = limit - people[lIdx];
		if (people[rIdx] <= l) {
			lIdx++;
			rIdx--;
		}
		else
			rIdx--;

		answer++;
	}

	return answer;
}