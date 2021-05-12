#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	long long size = m * n + 1;
	vector<long long> v(size, 0);

	v[1] = 1;               // Ω√¿€¡ˆ¡°
	for (auto x : puddles)   // øıµ¢¿Ã
		v[(m*(x[1] - 1)) + x[0]] = -1;

	for (long long i = 2; i < size; ++i)
	{
		if (v[i] == -1) // øıµ¢¿Ã∂Û∏È ≥—æÓ∞®.
			continue;

		if ((i - 1) % m != 0 && v[(i - 1)] != -1) // øﬁ¬ 
			v[i] += (v[i - 1]) % 1000000007;
		if (i - m > 0 && v[i - m] != -1)        // ¿ß
			v[i] += (v[i - m]) % 1000000007;

		v[i] %= 1000000007;
	}

	return v[m*n];
}