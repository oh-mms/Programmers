#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	unordered_map<string, vector<pair<int, int>>> um;
	unordered_map<string, int> counts;
	for (int i = 0; i < genres.size(); ++i) {
		um[genres[i]].push_back(make_pair(i, plays[i]));
		counts[genres[i]] += plays[i];
	}

	for (auto iter = um.begin(); iter != um.end(); ++iter)
		sort(iter->second.begin(), iter->second.end(), comp);

	map<int, string, greater<int>> priority;
	for (auto iter = counts.begin(); iter != counts.end(); ++iter) {
		string s = iter->first;
		int c = iter->second;
		priority[c] = s;
	}

	auto iter = priority.begin();
	int count;
	while (iter != priority.end()) {
		count = 0;
		for (auto i = um[iter->second].begin(); i != um[iter->second].end(); ++i) {
			answer.push_back((*i).first);
			count++;
			if (count == 2)
				break;
		}
		iter++;
	}

	return answer;
}