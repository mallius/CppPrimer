template<class Type>
std::istream& operator>> (std::istream& is, Queue<Type>& Q)
{
	Type val;
	while(is >> val)
		q.push(val);
	return is;
}
