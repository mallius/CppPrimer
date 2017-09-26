NoName&  NoName::operator=(const Noname& noName)
{
	pstring = new std::string;
	*pstring = *(noName.pstring);	
	i = noName.i;
	d = noName.d;

	retunr *this;
}
