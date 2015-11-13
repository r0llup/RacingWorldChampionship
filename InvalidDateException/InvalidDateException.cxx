#include <stdlib.h>
#include <string.h>
#include "InvalidDateException.h"

InvalidDateException::~InvalidDateException(void)
{
	cout << "Destructeur (InvalidDateException)" << endl;
	if(format)
	{
		cout << "destruction de " << getFormat() << endl;
		delete [] format;
	}
}

char * InvalidDateException::getFormat(void) const
{
	return format;
}

void InvalidDateException::setFormat(char *form)
{
	if(format)
	{
		cout << "destruction de " << getFormat() << endl;
		delete [] format;
	}

	if(form)
	{
		format = new char[strlen(form)+1];
		strcpy(format, form);
	}

	else
	{
		format = new char[L_FORM];
		strcpy(format, "JJ/MM/AAAA");
	}
}
