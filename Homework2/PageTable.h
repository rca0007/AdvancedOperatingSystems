#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <vector>
#include "ReplacementPolicy.h"
#include "Page.h"

class PageTable
{
private:
	Page** pages;
	ReplacementPolicy* replacementPolicy;
	int size;

public:
	PageTable(int size, ReplacementPolicy& policy);
	~PageTable();

	void addPage(Page& page);
	Page* findPage(int pageData);
	void incrementAgeOfAllPages();	
};

#endif
