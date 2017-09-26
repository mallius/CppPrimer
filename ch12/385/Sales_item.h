class Sales_item
{
public:
	Sales_item(): units_sold(0), revenue(0.0){}
public:
	Sales_item(const std::string&);
	Sales_item(std::istream&);
	Sales_item();
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
