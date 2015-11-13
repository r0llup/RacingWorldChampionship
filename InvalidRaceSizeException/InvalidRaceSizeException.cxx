#include "InvalidRaceSizeException.h"

int InvalidRaceSizeException::getRaceLength(void)
{
	return raceLength;
}

void InvalidRaceSizeException::setRaceLength(int rcLength)
{
	raceLength = rcLength;
}
