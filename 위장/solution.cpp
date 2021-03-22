#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	if (clothes.size() == 0)
		return answer;

	// nCr combination���� �ϳ��� �����ϴ� ���, [none, none, hat] �� ���� ���°� ���� �� ����.
	// ���� �� ������ �Ƿ� �ʱ�ȭ�� ���� �ʰ� none�� ��츦 �ϳ��� �־���.
	// �ϳ��� ���̶� �Դ´ٰ� [none, none, none] �� ���� �����϶�� ������ ���Ͻ� 1�� ����.
	unordered_map<string, int> um;
	for (auto& x : clothes) {
		if (um[x[1]] == 0)
			um[x[1]] = 2; // none�� �־���.
		else
			um[x[1]]++;
	}
	answer = 1;
	for (auto iter = um.begin(); iter != um.end(); ++iter) {
		answer *= iter->second;
	}

	return answer - 1;
}