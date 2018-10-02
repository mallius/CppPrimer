#include "middle.hpp"

template <class T>
bool middle(vector<T>& vec, T& m)
{
	vector<T> temp = vec;
	sort(temp.begin(), temp.end());	
	if(temp.size() == 0)
		return false;
	m = temp[temp.size()/2];
	return true;
}
