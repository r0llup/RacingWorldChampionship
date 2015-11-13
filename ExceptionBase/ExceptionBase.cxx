#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include "ExceptionBase.h"

ExceptionBase::ExceptionBase(void)
{
	cout << "Constructeur par defaut (ExceptionBase)" << endl;
	message = NULL;
	setMessage(NULL);
}

ExceptionBase::ExceptionBase(char *msg)
{
	cout << "Constructeur d'initialisation (ExceptionBase)" << endl;
	message = NULL;
	setMessage(msg);
}

ExceptionBase::ExceptionBase(const ExceptionBase &e)
{
	cout << "Constructeur de copie (ExceptionBase)" << endl;
	message = NULL;
	setMessage(e.getMessage());
}

ExceptionBase::~ExceptionBase(void)
{
	cout << "Destructeur (ExceptionBase)" << endl;
	if(message)
	{
		cout << "destruction de " << getMessage() << endl;
		delete [] message;
	}
}

char * ExceptionBase::getMessage(void) const
{
	return message;
}

void ExceptionBase::setMessage(char *msg)
{
	if(message)
	{
		cout << "destruction de " << getMessage() << endl;
		delete [] message;
	}

	if(msg)
	{
		message = new char[strlen(msg)+1];
		strcpy(message, msg);
	}

	else
	{
		message = new char[L_MSG];
		strcpy(message, "inconnu");
	}
}
