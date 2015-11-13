#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include "FichierCircuit.h"

void FichierCircuit::save(Circuit &c)
{
	ofstream fichier(getFileName().data(), ios::out | ios::app);

	if(fichier)
	{
		fichier << c;
		fichier.close();
	}

	else
	{
		cerr << "Erreur lors de l\'ouverture du fichier !" << endl;
	}
}

bool FichierCircuit::load(Circuit &c, string paysCir)
{
	Circuit tmp;
	ifstream fichier(getFileName().data(), ios::in);

	if(fichier)
	{
		fichier >> tmp;

		if(tmp.getPays() == paysCir)
		{
			c = tmp;
			return 0;
		}

		while(!fichier.eof())
		{
			fichier >> tmp;

			if(!fichier.eof())
			{
				if(tmp.getPays() == paysCir)
				{
					c = tmp;
					return 0;
				}
			}
		}

		fichier.close();
	}

	else
	{
		cerr << "Erreur lors de l\'ouverture du fichier !" << endl;
	}

	return 1;
}

void FichierCircuit::list(void)
{
	Circuit c;
	ifstream fichier(getFileName().data(), ios::in);

	if(fichier)
	{
		fichier >> c;
		c.affiche();

		while(!fichier.eof())
		{
			fichier >> c;
			if(!fichier.eof())
			{
				c.affiche();
			}
		}
		fichier.close();
	}

	else
	{
		cerr << "Erreur lors de l\'ouverture du fichier !" << endl;
	}
}
