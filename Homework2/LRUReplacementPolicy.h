#ifndef LRUREPLACEMENTPOLICY_H
#define LRUREPLACEMENTPOLICY_H

#include "Page.h"
#include "ReplacementPolicy.h"

class LRUReplacementPolicy : public ReplacementPolicy
{
public:
	virtual void replace(Page* pages[], Page& pageToBeAdded, int size);
	virtual void manipulate(Page& pageToBeManipulated);
};

#endif
