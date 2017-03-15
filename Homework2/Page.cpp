#include "Page.h"

Page::Page(int newData)
{
	data = newData;
}

int Page::getAge()
{
	return age;
}

void Page::setAge(int newAge)
{
	age = newAge;
}

int Page::getData()
{
	return data;
}
