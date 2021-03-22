#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 3�� 4�� ���� �׽�Ʈ ���̽��� ����Ǿ��ٰ� �Ѵ�. (�׷��� ������ ����ϴ� �ڵ忴����, ���翡�� ������� �� �Ѵ�.)
// �� �ڵ�ó�� substr�� Ǫ�� ��� ��� hash�� ����� �ڵ�� Ǫ�� ���� �����Ѵ�.

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