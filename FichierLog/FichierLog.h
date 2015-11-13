#ifndef FICHIERLOG_H
#define FICHIERLOG_H
#include <iostream.h>

using namespace std;

class FichierLog
{
	friend FichierLog & operator<<(FichierLog &fl, const char *log);
	private:
		string filename;
	public:
		FichierLog(void);
		FichierLog(string fn);
		FichierLog(const FichierLog &fl);
		string getFileName(void) const;
		void setFileName(string fn);
};

#endif
