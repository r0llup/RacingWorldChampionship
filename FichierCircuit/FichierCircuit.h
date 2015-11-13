#ifndef FICHIERCIRCUIT_H
#define FICHIERCIRCUIT_H
#include "FichierLog.h"
#include "Circuit.h"

using namespace std;

class FichierCircuit : public FichierLog
{
	public:
		FichierCircuit(void) : FichierLog() {};
		FichierCircuit(string fn) : FichierLog(fn) {};
		FichierCircuit(const FichierCircuit &fc) : FichierLog(fc) {};
		void save(Circuit &c);
		bool load(Circuit &c, string paysCir);
		void list(void);
};

#endif
