#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> um;

	for (int i = 0; i < participant.size(); ++i) {
		um[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); ++i) {
		um[completion[i]]--;
	}

	for (auto iter = um.begin(); iter != um.end(); ++iter) {
		if ((*iter).second == 1) {
			answer = (*iter).first;
			break;
		}
	}

	return answer;
}