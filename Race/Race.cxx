#include "Race.h"
#include <fstream.h>

Race::Race(void)
{
	cout << "Constructeur par defaut (Race)" << endl;
	circuit = NULL;
	setCircuit(NULL);
	setNbTours(1);
}

Race::Race(Circuit *c)
{
	cout << "Constructeur d'initialisation (1) (Race)" << endl;
	circuit = NULL;
	setCircuit(c);
	setNbTours(1);
}

Race::Race(Circuit *c, Date d, int nbt)
{
	cout << "Constructeur d'initialisation (2) (Race)" << endl;
	circuit = NULL;
	setCircuit(c);
	setDate(d);
	setNbTours(nbt);
}

Race::Race(const Race &r)
{
	cout << "Constructeur de copie (Race)" << endl;
	circuit = NULL;
	setCircuit(r.getCircuit());
	setDate(r.getDate());
	setNbTours(r.getNbTours());
}

Race::~Race(void)
{
	cout << "Destructeur (Race)" << endl;
	cout << "destruction de " << getCircuit()->getNom() << endl;
	delete circuit;
}

Circuit * Race::getCircuit(void) const
{
	return circuit;
}

Date Race::getDate(void) const
{
	return date;
}

int Race::getNbTours(void) const
{
	return nbTours;
}

float Race::getRaceLength() const
{
	return getCircuit()->getLongueur() * getNbTours();
}

void Race::setCircuit(const Circuit *c)
{
	if(circuit)
	{
		cout << "destruction de " << getCircuit()->getNom() << endl;
		delete circuit;
	}

	if(c)
	{
		circuit = new Circuit;
		circuit->setNom(c->getNom());
		circuit->setPays(c->getPays());
		circuit->setLongueur(c->getLongueur());
	}

	else
	{
		circuit = new Circuit();
	}
}

void Race::setDate(Date d)
{
	date = d;
}

void Race::setNbTours(int ntc)
{
	if(ntc <= 0)
	{
		InvalidRaceSizeException se("Nombre de tours invalide", ntc);
		throw se;
	}

	nbTours = ntc;
}

void Race::affiche(void) const
{
	if(getCircuit())
	{
		getCircuit()->affiche();
	}

	getDate().affiche();
	cout << "Nombre de tour(s) du race : " << getNbTours() << endl;
}

int Race::verifierDossard(int dossard)
{
	IterVector<int> iterateur(resultats);

	if(!resultats.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			if((int) iterateur == dossard)
			{
				return 1;
			}

			iterateur++;
		}
	}

	return 0;
}

void Race::ajouterDossard(int dossard)
{
	resultats.ajout(dossard);
}

Race & Race::operator=(const Race & r)
{
	cout << "Operateur = (Race)" << endl;
	setCircuit(r.getCircuit());
	setDate(r.getDate());
	setNbTours(r.getNbTours());
	return *this;
}

bool Race::operator<(const Race & r)
{
	cout << "Operateur < (Race)" << endl;
	if(getDate() < r.getDate())
	{
		return true;
	}
	return false;
}

bool Race::operator<=(const Race & r)
{
	cout << "Operateur <= (Race)" << endl;
	if(getDate() <= r.getDate())
	{
		return true;
	}
	return false;
}

bool Race::operator==(const Race & r)
{
	cout << "Operateur == (Race)" << endl;
	if(getDate() == r.getDate())
	{
		return true;
	}
	return false;
}

bool Race::operator>(const Race & r)
{
	cout << "Operateur > (Race)" << endl;
	if(getDate() > r.getDate())
	{
		return true;
	}
	return false;
}

bool Race::operator>=(const Race & r)
{
	cout << "Operateur >= (Race)" << endl;
	if(getDate() >= r.getDate())
	{
		return true;
	}
	return false;
}

ostream & operator<<(ostream &s, Race & r)
{
	cout << "Operateur << (Race)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		if(r.getCircuit())
		{
			s << *(r.getCircuit());
		}

		s << "Date : " << r.getDate();
		s << "Nombre de tours : " << r.getNbTours() << endl;
		s << "Grille de resultats : " << endl;

		IterVector<int> iterateur(r.resultats);

		if(!r.resultats.empty())
		{
			iterateur.reset();

			for(int i=0; i < r.resultats.getNbreElem(); i++)
			{
				s << (int &) iterateur << endl;
				iterateur++;
			}
		}

		else
		{
			cout << "Aucun resultat" << endl;
		}
	}

	else
	{
		if(r.getCircuit())
		{
			*tmp << *(r.getCircuit());
			*tmp << r.getDate();
			*tmp << r.getNbTours() << endl;
			*tmp << r.resultats.getNbreElem() << endl;

			if(!r.resultats.empty())
			{
				IterVector<int> iterateur(r.resultats);

				iterateur.reset();

				for(int i=0; i < r.resultats.getNbreElem(); i++)
				{
					*tmp << (int &) iterateur << endl;
					iterateur++;
				}
			}
		}
	}

	return s;
}

istream & operator>>(istream & s, Race & r)
{
	cout << "Operateur >> (Race)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		cout << "Date : " << endl << endl;
		s >> r.date;
		cout << "Nombre de tours : ";
		s >> r.nbTours;
	}

	else
	{
		Circuit *c;
		c = new Circuit;
		*tmp >> *c;
		r.setCircuit(c);

		*tmp >> r.date;
		*tmp >> r.nbTours;

		int nbelem;
		*tmp >> nbelem;

		for(int i = 0, dossard; i < nbelem; i++)
		{
			*tmp >> dossard;
			cout << dossard << endl;
			r.resultats.ajout(dossard);
		}
	}

	return s;
}
