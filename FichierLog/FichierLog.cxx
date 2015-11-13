#include "FichierLog.h"
#include <time.h>
#include <fstream.h>

FichierLog::FichierLog(void)
{
	cout << "Constructeur par defaut (FichierLog)" << endl;
	setFileName("");
}

FichierLog::FichierLog(string fn)
{
	cout << "Constructeur d'intialisation (FichierLog)" << endl;
	setFileName(fn);
}

FichierLog::FichierLog(const FichierLog &fl)
{
	cout << "Constructeur de copie (FichierLog)" << endl;
	setFileName(fl.getFileName());
}

string FichierLog::getFileName(void) const
{
	return filename;
}

void FichierLog::setFileName(string fn)
{
	filename = fn;
}

FichierLog & operator<<(FichierLog &fl, const char * log)
{
	cout << "Operateur << (FichierLog)" << endl;
  	time_t timestamp;
    struct tm * t;
    timestamp = time(NULL);
    t = localtime(&timestamp);

	char ch[255];
	sprintf(&ch[0], "%02u-%02u-%04u %02u:%02u:%02u> ", t->tm_mday, t->tm_mon, \
		1900+t->tm_year, t->tm_hour, t->tm_min, t->tm_sec);

	ofstream fichier(fl.getFileName().data(), ios::out | ios::app);

	if(fichier)
	{
		fichier << ch << log << endl;
		fichier.close();
	}

	else
	{
		cerr << "Erreur d\'ouverture !" << endl;
	}

	return fl;
}
