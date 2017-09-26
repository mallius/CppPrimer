#ifndef __MESSAGE_H__
#define __MESSAGE_H__ 

#include <string>
#include <set>

using namespace std;

class Message
{
public:
	Message(const std::string &str = ""): contents(str){  }
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folder;
	void put_Msg_in_Folders(const std::set<Folder *>&);
	void remove_Msg_from_Folders();
};
#endif
