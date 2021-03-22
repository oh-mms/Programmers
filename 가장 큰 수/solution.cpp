#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(b) + to_string(a);
	// s1이 더 길면 True, s2가 더 길면 False.
	return s1 > s2;
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);

	for (int i = 0; i < numbers.size(); ++i) {
		string s = to_string(numbers[i]);
		answer += s;
	}

	return (answer[0] == '0') ? "0" : answer;
}