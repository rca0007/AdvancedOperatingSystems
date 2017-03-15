#include "PageTable.h"

PageTable::PageTable(int newSize, ReplacementPolicy& policy)
{
	size = newSize;
	pages = new Page*[size];
	replacementPolicy = &policy;
}

PageTable::~PageTable()
{
	delete [] pages;
}

void PageTable::addPage(Page& newPage)
{
	replacementPolicy->replace(pages, newPage, size);
}

Page* PageTable::findPage(int pageData)
{
	int i = 0;
	while(i < size)
	{
		if(nullptr != pages[i] && pages[i]->getData() == pageData)
		{
			replacementPolicy->manipulate(*pages[i]);
			return pages[i];
		}

		i++;
	}

	return nullptr;
}

void PageTable::incrementAgeOfAllPages()
{
	int i = 0;

	Page* currentPage = nullptr;
	while(i < size)
	{
		currentPage = pages[i];
		
		if(nullptr != currentPage)
		{
			currentPage->setAge(currentPage->getAge() + 1);
		}

		i++;
	}
}
