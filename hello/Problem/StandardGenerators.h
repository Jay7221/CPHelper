#include<bits/stdc++.h>
using namespace std;
int randNum(int mn, int mx)
{
	int diff = mx - mn;
	if(diff == 0)
	{
		return mn;
	}
	int n = std::rand() % diff;
	n = mn + n;
	return n;
}
std::vector<int> randArray(int n, int mx, int mn)
{
	std::vector<int> arr(n);
	for(int i = 0; i < n; ++i)
	{
		arr[i] = randNum(mn, mx);
	}
	return arr;
}
template<class T>
void shuffle(std::vector<T> arr)
{
	std::random_shuffle(arr.begin(), arr.end());
}
template<class T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		std::cerr << elem << ' ';
	}
	std::cerr << '\n';
}
int main()
{
	vector<int> a = {1, 2, 3};
	debug(a);
	
}