NoName::NoName(const Noname& noName)
{
	i = noName.i;
	d = noName.d;
	pstring = new std::string;
	*pstring = *(noName.pstring);	
}
