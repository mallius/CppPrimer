template<class Type>
class List
{
public:
	List();
	Type &front();
	const Type &front()const;
	void insert(const Type &);
	void pop();
	bool empty()const;
private:
	// ...
};

