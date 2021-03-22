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
	// ������� �μ� ��⿭�� �������.
	while (!pq.empty()) {
		max = pq.top();

		// ��⿭ �ȿ��� ���� ã�� location�� ��� ��ġ�� �������.
		location--;
		if (location < 0) {
			if (max == target) break; // ���� ���� ã�� ��ȣ�� �μ�� ���ʶ�� ���̻� ����� �ʿ䰡 ����.
			else              location = pq.size() - 1;
		}

		if (q.front() != max) {
			q.push(q.front()); q.pop();
			continue;
		}
		q.pop(); pq.pop();
		count++; // �߿䵵�� ���� ū ������ ��µǹǷ�, ��µ� ������ ���� �ű�.
	}
	return answer = count;
}