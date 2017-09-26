template<typename T> int compare(const T&, const T&)
{

	return 0;
}

int main(void)
{
	int (*pf1)(const int&, const int&) = compare;
}
