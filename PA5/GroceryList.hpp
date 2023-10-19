#pragma once
#include "ListNode.hpp"



class List
{
public:
	List();
	~List();

	void mInsertAtFront(string newItem);

private:
	ListNode* mpHead;
	ListNode* mCreateNode(string& newItem);

};