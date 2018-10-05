#ifndef _SALES_ITEM_H_
#define _SALES_ITEM_H_ 

#include "Handle.h"
#include "ItemBase.h"

class Sales_item {
public:
	Sales_item(): h() {  }
	Sales_item(const Item_base& item): h(item.clone()) {  }

	const Item_base& operator*() const { return *h; }
	const Item_base* operator->() const { return h.operator->(); }
private:
	Handle<Item_base> h;
};

#endif
