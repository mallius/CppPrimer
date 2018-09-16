#include <set>
#include <iostream>
using namespace std;

class Folder;

class Message {
friend class Folder;
public:
	Message(const std::string &str = ""): content(str) {  }
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	std::string content;
	std::set<Folder*> folders;
	void put_Msg_in_Folders(const std::set<Folder*>&);  //复制构造、赋值操作符使用  
	void remove_Msg_from_Folders();  //析构、赋值操作符使用
};

class Folder {
friend class Message;
private:
	void addMsg(Message* m);
	void remMsg(Message* m);

};
