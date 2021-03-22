#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	if (clothes.size() == 0)
		return answer;

	// nCr combination에서 하나만 선택하는 경우, [none, none, hat] 과 같은 형태가 나올 수 있음.
	// 따라서 각 종류별 의류 초기화시 본래 옷과 none의 경우를 하나씩 넣어줌.
	// 하나의 옷이라도 입는다고 [none, none, none] 의 경우는 제외하라고 했으니 리턴시 1을 빼줌.
	unordered_map<string, int> um;
	for (auto& x : clothes) {
		if (um[x[1]] == 0)
			um[x[1]] = 2; // none을 넣어줌.
		else
			um[x[1]]++;
	}
	answer = 1;
	for (auto iter = um.begin(); iter != um.end(); ++iter) {
		answer *= iter->second;
	}

	return answer - 1;
}