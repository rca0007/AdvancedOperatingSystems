#include "LRUReplacementPolicy.h"

void LRUReplacementPolicy::replace(Page* pages[], Page& pageToBeAdded, int size)
{
	if(true == tryToPutInEmptySlot(pages, pageToBeAdded, size))
	{
		return;
	}

	int indexOfOldestPage = 0;
	int oldestAge = -1;	
	for(int i = 0; i < size; i++)
	{
		if(pages[i]->getAge() > oldestAge)
		{
			oldestAge = pages[i]->getAge();
			indexOfOldestPage = i;
		}
	}

	pages[indexOfOldestPage] = &pageToBeAdded;
}

void LRUReplacementPolicy::manipulate(Page& pageToBeManipulated)
{
	pageToBeManipulated.setAge(0);
}
