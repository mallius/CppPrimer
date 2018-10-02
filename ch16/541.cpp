template <class T1, class T2, class T3>
T1 sum(T2, T3)
{

}

template <class T1, class T2, class T3>
T3 alternative_sum(T2, T1)
{

}

int main(void)
{
	int i = 1;
	long lng = 2;
	long val3 = sum<long>(i, lng);

	// long val3 = alternative_sum<long>(i, lng);
	long val2 = alternative_sum<long, int, long>(i, lng);
	
}
