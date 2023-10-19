#include "GroceryList.hpp"

/// <summary>
/// defualt constructor for the List class
/// </summary>
List::List()
{
	mpHead = nullptr;
}

/// <summary>
/// destructor for the list class
/// </summary>
List::~List()
{
	ListNode* pCur = mpHead;
	ListNode* pPrev = nullptr;

	while (pCur != nullptr)
	{
		pPrev = pCur;
		pCur = pCur->getpNext();
		delete pPrev;
	}
}

/// <summary>
/// insert at front function for a linked list
/// </summary>
/// <param name="newItem">the string that will be stored in the node</param>
void List::mInsertAtFront(string newItem)
{
	ListNode* pMem = mCreateNode(newItem);

	if (pMem != nullptr)
	{
		if (this->mpHead == nullptr)//empty list
		{
			mpHead = pMem;
		}
		else
		{
			pMem->setpNext(mpHead);
			mpHead = pMem;
		}
	}
}

/// <summary>
/// allocates space for a list a ListNode 
/// </summary>
/// <param name="newItem">the string that will be stored in the node</param>
/// <returns>a pointer to the newly allocated node</returns>
ListNode* List::mCreateNode(string& newItem)
{
	ListNode* pMem = new ListNode(newItem);
	return pMem;
}
