#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 3월 4일 기준 테스트 케이스가 변경되었다고 한다. (그래서 전에는 통과하던 코드였지만, 현재에는 통과하지 못 한다.)
// 이 코드처럼 substr로 푸는 방법 대신 hash를 사용한 코드로 푸는 것을 권장한다.

bool SortByLength(string& a, string& b) {
	if (a.size() < b.size())		return true;
	else if (b.size() < a.size()) return false;
	else {
		if (a < b) return true;
		else      return false;
	}
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end(), SortByLength);
	for (int i = 0; i < phone_book.size() - 1; ++i) {
		for (int j = i + 1; j < phone_book.size(); ++j) {
			int strSize = phone_book[i].size();
			if (phone_book[i] == phone_book[j].substr(0, strSize))
				return false;
		}
	}
	return true;
}