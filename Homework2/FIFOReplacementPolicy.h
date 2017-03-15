#ifndef FIFOREPLACEMENTPOLICY_H
#define FIFOREPLACEMENTPOLICY_H

#include "Page.h"
#include "ReplacementPolicy.h"

class FIFOReplacementPolicy : public ReplacementPolicy
{
public:
	virtual void replace(Page* pages[], Page& pageToBeAdded, int size);
	virtual void manipulate(Page& pageToBeManipulated);
};

#endif
