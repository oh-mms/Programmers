#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
	long long answer = 0;
	//sort(times.begin(), times.end());   

	long long minTime = 0;
	long long maxTime = times[times.size() - 1] * (long long)n;
	long long midTime;

	while (minTime <= maxTime)
	{
		midTime = (minTime + maxTime) / 2;

		// 해당 midTime 동안 심사할 수 있는 사람 수.
		long long sum = 0;
		for (long long i = 0; i < times.size(); ++i)
			sum += midTime / times[i];

		if (n <= sum)
		{
			answer = midTime;
			maxTime = midTime - 1;
		}
		else
			minTime = midTime + 1;
	}

	return answer;
}