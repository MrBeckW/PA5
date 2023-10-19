#include "ListNode.hpp"

/// <summary>
/// constuctor for listNode
/// </summary>
/// <param name="item">string to be inserted</param>
ListNode::ListNode(string& item)
{
	this->item = item;
	this->pNext = nullptr;
}

/// <summary>
/// getter for pNext
/// </summary>
/// <returns></returns>
ListNode* ListNode::getpNext()
{
	return pNext;
}

/// <summary>
/// setter for pNext
/// </summary>
/// <param name="pNext"></param>
void ListNode::setpNext(ListNode* pNext)
{
	this->pNext = pNext;
}
