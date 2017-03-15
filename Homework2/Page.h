#ifndef PAGE_H
#define PAGE_H

class Page
{
private:
	int age = 0;
	int data;

public:
	Page(int data);

	int getAge();
	void setAge(int age);
	int getData();
};

#endif
