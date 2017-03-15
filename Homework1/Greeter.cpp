#include <unistd.h>
#include <iostream>
#include <string>

bool isCapitalLetter(char letter)
{
	bool isCapitalLetter = false;

	int asciiDecimalValue = (int) letter;

	if(90 >= asciiDecimalValue && 65 <= asciiDecimalValue)
	{
		isCapitalLetter = true;
	}

	return isCapitalLetter;
}

bool isLowerCaseLetter(char letter)
{
	bool isLowerCaseLetter = false;

	int asciiDecimalValue = (int) letter;

	if(122 >= asciiDecimalValue && 97 <= asciiDecimalValue)
	{
		isLowerCaseLetter = true;
	}

	return isLowerCaseLetter;
}

void reverseCase(char* stringToBeMutated)
{
	int count = 0;
	while(stringToBeMutated[count] != '\0')
	{
		char currentLetter = stringToBeMutated[count];

		if(isLowerCaseLetter(currentLetter))
		{
			int asciiDecimalValue = (int) currentLetter;
			asciiDecimalValue = asciiDecimalValue - 32;

			currentLetter = (char) asciiDecimalValue;
		}
		else if(isCapitalLetter(currentLetter))
		{
			int asciiDecimalValue = (int) currentLetter;
			asciiDecimalValue = asciiDecimalValue + 32;

			currentLetter = (char) asciiDecimalValue;
		}
		else
		{
			//not a letter but a special symbol
		}

		stringToBeMutated[count] = currentLetter;

		count = count + 1;
	}
}

void childProcessWork(int* childPipeFileDescriptors, int* parentPipeFileDescriptors)
{
	int parentReadEnd = parentPipeFileDescriptors[0];
	int childWriteEnd = childPipeFileDescriptors[1];

	char stringToHaveCaseSwitched[100];
	while(0 == read(parentPipeFileDescriptors[0], stringToHaveCaseSwitched, 100))
	{
		sleep(10);
	}

	reverseCase(stringToHaveCaseSwitched);

	std::string reversedString(stringToHaveCaseSwitched);

	write(childWriteEnd, reversedString.data(), reversedString.length() + 1);
}

std::string* parentProcessWork(int* parentPipeFileDescriptors, int* childPipeFileDescriptors, std::string stringToHaveCaseSwitched)
{
	int parentWriteEnd = parentPipeFileDescriptors[1];
	int childReadEnd = childPipeFileDescriptors[0];

	write(parentWriteEnd, stringToHaveCaseSwitched.data(), stringToHaveCaseSwitched.length() + 1);

	char caseSwitchedString[stringToHaveCaseSwitched.length() + 1];

	while(0 == read(childReadEnd, caseSwitchedString, stringToHaveCaseSwitched.length() + 1))
	{
		sleep(10);
	}

	std::string* stringOnHeap = new std::string(caseSwitchedString);

	return stringOnHeap;
}

int getLength(char* string)
{
	if (NULL == string)
	{
		return 0;
	}

	int index = 0;
	int count = 0;
	while(string[index] != '\0') 
	{
		int numberOfCharacters = 0;

		if(string[index] == '\0')
		{
			return count;
		}
		else
		{
			count = count + 1;
		}
	}
}

int main(int len, char** args)
{
	std::string stringToHaveCaseSwitched;

	std::cout << "Please enter a string to have case of the letters switched: ";
	std::getline(std::cin, stringToHaveCaseSwitched);

	int childPipeFileDescriptors[2];
	int parentPipeFileDescriptors[2];

	if (-1 == pipe(childPipeFileDescriptors))
	{
		perror("Error on creation of child pipe.");
		exit(EXIT_FAILURE);
	}

	if (-1 == pipe(parentPipeFileDescriptors))
	{
		perror("Error on creation of parent pipe.");
		exit(EXIT_FAILURE);
	}

	int childProcessID = fork();

	if (-1 == childProcessID)
	{
		perror("Error on creation of child process.");
		exit(EXIT_FAILURE);
	}

	if (0 == childProcessID) //child process code
	{
		childProcessWork(childPipeFileDescriptors, parentPipeFileDescriptors);
		close(childPipeFileDescriptors[0]);
		close(childPipeFileDescriptors[1]);
		close(parentPipeFileDescriptors[0]);
		close(parentPipeFileDescriptors[1]);
		exit(EXIT_SUCCESS);
	}
	else //parent process code
	{
		std::string* caseSwitchedString = parentProcessWork(parentPipeFileDescriptors, childPipeFileDescriptors, stringToHaveCaseSwitched);
		std::cout << *caseSwitchedString;
		close(childPipeFileDescriptors[0]);
		close(childPipeFileDescriptors[1]);
		close(parentPipeFileDescriptors[0]);
		close(parentPipeFileDescriptors[1]);
	}

	return 0;
}

