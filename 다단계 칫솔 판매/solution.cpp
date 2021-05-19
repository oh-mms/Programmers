#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void SetRefMoneyRecursive(	unordered_map<string, int>& totalMoney,
												unordered_map<string, string>& refTable, string seller, int money)
{
	int moneyOneTenth = money * 0.1;

	if (refTable.find(seller) != refTable.end())
	{
		SetRefMoneyRecursive(totalMoney, refTable, refTable[seller], moneyOneTenth);
		money -= moneyOneTenth;
	}

	totalMoney[seller] += money;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
	vector<int> answer;

	// ����� �� ������ ����
	unordered_map<string, int> totalMoney;
	for (auto& iter : enroll)
		totalMoney[iter] = 0;

	// �ڽ��� ����ڸ� ���
	unordered_map<string, string> refTable;
	for (int i = 0; i < referral.size(); ++i)
	{
		string indexString = enroll[i];
		if (referral[i] != "-")
			refTable[indexString] = referral[i];
		else
			refTable[indexString] = "center"; // �ӽ� ���̺��� �������.
	}

	for (int i = 0; i < seller.size(); ++i)
	{
		int money = amount[i] * 100;
		SetRefMoneyRecursive(totalMoney, refTable, seller[i], money);
	}

	for (auto& iter : enroll)
		answer.push_back(totalMoney[iter]);

	return answer;
}