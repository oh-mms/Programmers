#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<int> q;
	priority_queue<int> pq;
	for (auto x : priorities) {
		q.push(x);
		pq.push(x);
	}

	int max, count = 1, target = priorities[location];
	// 문제대로 인쇄 대기열을 만들어줌.
	while (!pq.empty()) {
		max = pq.top();

		// 대기열 안에서 내가 찾는 location의 상대 위치를 계산해줌.
		location--;
		if (location < 0) {
			if (max == target) break; // 만약 내가 찾던 번호가 인쇄될 차례라면 더이상 계산할 필요가 없음.
			else              location = pq.size() - 1;
		}

		if (q.front() != max) {
			q.push(q.front()); q.pop();
			continue;
		}
		q.pop(); pq.pop();
		count++; // 중요도가 제일 큰 값부터 출력되므로, 출력된 순위를 따로 매김.
	}
	return answer = count;
}