#ifndef INVALIDRACESIZEEXCEPTION_H
#define  INVALIDRACESIZEEXCEPTION_H
#include <iostream.h>
#include "ExceptionBase.h"

class InvalidRaceSizeException : public ExceptionBase
{
	private:
		int raceLength;
	public:
		InvalidRaceSizeException() : ExceptionBase()
		{
			cout << "Constructeur par defaut (InvalidRaceSizeException)" << endl;
			raceLength = 0;
		}
		InvalidRaceSizeException(int rcLength) : ExceptionBase()
		{
			cout << "Constructeur d'initialisation (1) (InvalidRaceSizeException)" \
				<< endl;
			setRaceLength(rcLength);
		}
		InvalidRaceSizeException(char *msg, int rcLength) : ExceptionBase(msg)
		{
			cout << "Constructeur d'initialisation (2) (InvalidRaceSizeException)" \
				<< endl;
			setRaceLength(rcLength);
		}
		InvalidRaceSizeException(InvalidRaceSizeException &irse) : ExceptionBase(irse)
		{
			cout << "Constructeur de copie (InvalidRaceSizeException)" << endl;
			setRaceLength(irse.getRaceLength());
		}
		int getRaceLength(void);
		void setRaceLength(int rcLength);
};

#endif
