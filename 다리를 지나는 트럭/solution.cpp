#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, time = 1, bridge_weight = 0;
	queue<int> crossingTrucks;
	vector<int> life(truck_weights.size(), bridge_length - 1);

	crossingTrucks.push(truck_weights[0]);
	bridge_weight += truck_weights[0];
	int crossing_idx = 0, next_idx = 1;
	while (!crossingTrucks.empty()) { // �ð��� �带 ������, �ٸ��� �ִ� Ʈ���� ������ ��.
		// ���� time
		for (int i = crossing_idx; i < next_idx; ++i) {
			if (life[i]) life[i]--;
			else {
				bridge_weight -= truck_weights[i];
				crossingTrucks.pop();
				crossing_idx++;
			}
		}

		// ���� time
		time++;
		if (next_idx < truck_weights.size()) {
			if (bridge_weight + truck_weights[next_idx] <= weight) {
				crossingTrucks.push(truck_weights[next_idx]);
				bridge_weight += truck_weights[next_idx];
				next_idx++;
			}
		}
	}

	return answer = time;
}