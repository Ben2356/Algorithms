#include <vector>
#include <queue>

using namespace std;

template <typename T>
vector<T> radixSort(vector<T> &arr)
{
	if (arr.size() <= 1)
		return arr;
	vector<queue<int>> q(9);
	int it = 1; 
	bool isDone = false;
	while (!isDone)
	{
		int mod, div, val;
		for (size_t i = 0; i < arr.size(); i++)
		{
			mod = pow(10, it);
			div = pow(10, it - 1);
			val = (arr[i] % mod) / div;
			q[(val - 1 < 0) ? 0 : val - 1].push(arr[i]);
		}
		int index = 0;
		for (size_t i = 0; i < q.size(); i++)
		{
			while (!q[i].empty())
			{
				if (i == 0 && q[i].size() == arr.size())
					isDone = true;
				T val = q[i].front();
				q[i].pop();
				arr[index++] = val;
			}
		}
		it++;
	}
	return arr;
}