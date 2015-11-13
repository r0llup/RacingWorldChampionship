#ifndef EXCEPTIONBASE_H
#define EXCEPTIONBASE_H

const int L_MSG = 10;

class ExceptionBase
{
	private:
		char *message;
	public:
		ExceptionBase(void);
		ExceptionBase(char *msg);
		ExceptionBase(const ExceptionBase &e);
		~ExceptionBase(void);
		char *getMessage(void) const;
		void setMessage(char *msg);
};

#endif
