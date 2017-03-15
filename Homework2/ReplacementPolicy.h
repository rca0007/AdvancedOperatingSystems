#ifndef REPLACEMENTPOLICY_H
#define REPLACEMENTPOLICY_H

class Page;

class ReplacementPolicy
{
private:
	

public:
	virtual void replace(Page* pages[], Page& pageToBeAdded, int size) = 0;
	virtual void manipulate(Page& pageToBeManipulated) = 0;

protected:
	bool tryToPutInEmptySlot(Page* pages[], Page& pageToBeAdded, int size);
};
#endif
