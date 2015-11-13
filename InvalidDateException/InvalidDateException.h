#ifndef INVALIDDATEEXCEPTION_H
#define INVALIDDATEEXCEPTION_H
#include <iostream.h>
#include "ExceptionBase.h"

const int L_FORM = 15;

class InvalidDateException : public ExceptionBase
{
	private:
		char *format;
	public:
		InvalidDateException() : ExceptionBase()
		{
			cout << "Constructeur par defaut (InvalidDateException)" << endl;
			format = NULL;
			setFormat(NULL);
		}
		InvalidDateException(char *msg) : ExceptionBase(msg)
		{
			cout << "Constructeur d'intialisation (1) (InvalidDateException)" \
				<< endl;
			format = NULL;
			setFormat(NULL);
		}
		InvalidDateException(char *msg, char *form) : ExceptionBase(msg)
		{
			cout << "Constructeur d'initialisation (2) (InvalidDateException)" \
				<< endl;
			format = NULL;
			setFormat(form);
		}
		InvalidDateException(const InvalidDateException &ide) : ExceptionBase(ide)
		{
			cout << "Constructeur de copie (InvalidDateException)" << endl;
			format = NULL;
			setFormat(ide.getFormat());
		}
		~InvalidDateException(void);
		char *getFormat(void) const;
		void setFormat(char *form);
};

#endif
