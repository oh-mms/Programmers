#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int process(vector<vector<int>>& picture, const int i, const int j)
{
	int count = 1;
	int color = picture[i][j];
	picture[i][j] = -1; // 방문 처리

	// 종료 조건 및 재귀
	if (i + 1 < picture.size() && picture[i + 1][j] == color)
		count += process(picture, i + 1, j);

	if (i - 1 >= 0 && picture[i - 1][j] == color)
		count += process(picture, i - 1, j);

	if (j + 1 < picture[i].size() && picture[i][j + 1] == color)
		count += process(picture, i, j + 1);

	if (j - 1 >= 0 && picture[i][j - 1] == color)
		count += process(picture, i, j - 1);

	return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	unordered_map<int, int> um;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (picture[i][j] <= 0)
				continue;
			int candidate = process(picture, i, j);
			um[picture[i][j]] = max(um[picture[i][j]], candidate);
			answer[0]++;
		}
	}

	answer[1] = max_element(um.begin(), um.end())->second;

	return answer;
}