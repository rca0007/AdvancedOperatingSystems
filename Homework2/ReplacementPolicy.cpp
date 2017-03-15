#include "ReplacementPolicy.h"

bool ReplacementPolicy::tryToPutInEmptySlot(Page* pages[], Page& pageToBeAdded, int size)
{	
	int i = 0;
	while(i < size)
	{
		if(pages[i] == nullptr || pages[i] == 0)
		{
			pages[i] = &pageToBeAdded;
			return true;
		}

		i++;
	}

	return false;
}


