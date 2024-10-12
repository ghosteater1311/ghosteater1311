#include <bits/stdc++.h>
using namespace std;

int LCS(vector<int>& firstArr, vector<int>& secondArr)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < firstArr.size(); i++) {
		mp[firstArr[i]] = i + 1;
	}
	vector<int> tempArr;
	for (int i = 0; i < secondArr.size(); i++) {
		if (mp.find(secondArr[i]) != mp.end()) {

			tempArr.push_back(mp[secondArr[i]]);
		}
	}
	vector<int> tail;

	tail.push_back(tempArr[0]);

	for (int i = 1; i < tempArr.size(); i++) {

		if (tempArr[i] > tail.back())
			tail.push_back(tempArr[i]);
		else if (tempArr[i] < tail[0])
			tail[0] = tempArr[i];
		else {
			auto it = lower_bound(tail.begin(),
								tail.end(),
								tempArr[i]);
			*it = tempArr[i];
		}
	}
	return (int)tail.size();
}

int main()
{
	int m, n;
	vector<int> firstArr(m);
	vector<int> secondArr(n);
	cin >> m >> n;
	for (int i = 0; i < m - 1; i++)
	{
		cin >> firstArr[i];
	}
	for (int j = 0; j < n - 1; j++)
	{
		cin >> secondArr[j];
	}
	cout << LCS(firstArr, secondArr);
	return 0;
}
