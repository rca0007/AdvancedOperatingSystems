#include <fstream>
#include <string.h>
#include <iostream>
#include "FIFOReplacementPolicy.h"
#include "LRUReplacementPolicy.h"
#include "PageTable.h"



int main(int len, char** args)
{

	int numberOfPageFaults = 0;
	ReplacementPolicy* replacementPolicy = nullptr;
	if(0 == strcmp(args[1], "FIFO")) 
	{
		replacementPolicy = new FIFOReplacementPolicy();
	}
	else
	{
		replacementPolicy = new LRUReplacementPolicy();
	}	


	
	int numberOfFrames = atoi(args[3]);
	PageTable* pageTable = new PageTable(numberOfFrames, *replacementPolicy);

	char pageNumberBuffer[2];

	std::string buffer;
	std::ifstream infile(args[2]);	

	while(getline(infile, buffer))
	{
		Page* page = pageTable->findPage(atoi(buffer.data()));
		
		if(nullptr == page)
		{
			std::cout << "Could not find page" << atoi(buffer.data()) << std::endl;
			numberOfPageFaults = numberOfPageFaults + 1;
			Page* pageToBeAdded = new Page(atoi(buffer.data()));
			pageTable->addPage(*pageToBeAdded);			
		}		

		pageTable->incrementAgeOfAllPages();
	}


	std::cout << "Number of page faults: " << numberOfPageFaults << std::endl;

	return 0;
}
