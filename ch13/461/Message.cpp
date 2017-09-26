#include "Message.h"

Message::Message(const Message &m):
	contents(m.contents), folder(m.folder)
{
	put_Msg_in_Folders(folder);
}
