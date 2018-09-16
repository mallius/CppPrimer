#include "MessageFolder.h"

//Message类私有函数 
void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
	for(std::set<Folder*>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg)
		(*beg)->addMsg(this);
}

void Message::remove_Msg_from_Folders()
{
	for(std::set<Folder*>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg)
		(*beg)->remMsg(this);
}

void Message::addFldr(Folder *f)
{
	folders.insert(f);
}

void Message::remFldr(Folder *f)
{
	folders.erase(f);
}

//Message公有函数
Message::Message(const Message &m): 
	content(m.content), folders(m.folders)
{
	put_Msg_in_Folders(folders);
}

Message& Message::operator=(const Message &rhs)
{
	if(&rhs != this)
	{
		remove_Msg_from_Folders();
		content = rhs.content;
		folders = rhs.folders;
		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
}


Message::~Message()
{
	remove_Msg_from_Folders();
}

void Message::save(Folder& f)
{
	
}

void Message::remove(Folder& f)
{

}



//Folder类私有函数
void Folder::addMsg(Message* m)
{
	
}

void Folder::remMsg(Message* m)
{

}
