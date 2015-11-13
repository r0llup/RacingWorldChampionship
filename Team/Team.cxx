#include "Team.h"
#include <fstream.h>

Team::Team(void)
{
	cout << "Constructeur par defaut (Team)" << endl;
	setName("default");
	log.setFileName(LOG_FN);
	loadTeam();
}

Team::Team(const string nm)
{
	cout << "Constructeur d'intialisation (Team)" << endl;
	setName(nm);
	log.setFileName(LOG_FN);
	loadTeam();
}

Team::Team(const Team &t)
{
	cout << "Constructeur de copie (Team)" << endl;
	setName(t.getName());
	log.setFileName(LOG_FN);
	loadTeam();
}

Team::~Team()
{
	cout << "Destructeur (Team)" << endl;
	saveTeam();
}

string Team::getName(void) const
{
	return name;
}

Vehicule Team::getVehicule(void) const
{
	return vehicule;
}

void Team::setName(const string nm)
{
	name = nm;
}

void Team::setVehicule(void)
{
	cin >> vehicule;
}

void Team::showTeam(void)
{
	cout << *this;
}

void Team::addCompetitor(void)
{
	Competitor comp;
	cin >> comp;
	compList.insert(comp);
}

void Team::loadTeam(void)
{
	ifstream file((getName() + ".team").c_str(), ios::in);

	if(!file)
	{
		log << ("Fichier '" + getName() + ".team' non trouve").c_str();

		if(!file)
		{
			addTeamName(); // ajout de l'équipe au fichier d'équipes
			cin >> *this; // initialisation de l'équipe
		}
	}

	else
	{
		file >> *this;
		file.close();
		log << ("admin : Fichier '" + getName() + ".team' charge avec succes").c_str();
	}
}

void Team::saveTeam(void)
{
	ofstream file((getName() + ".team").c_str(), ios::out);

	if(!file)
	{
		log << ("Fichier '" + getName() + ".team' non trouve").c_str();
		exit(1);
	}

	file << *this;
	file.close();
	log << ("admin : Fichier '" + getName() + ".team' sauve avec succes").c_str();
}

void Team::addTeamName(void)
{
	char tmp[255];
	ofstream file(TMS_FN, ios::out | ios::app);

	if(!file)
	{
		sprintf(tmp, "admin : Fichier '%s' non trouve", TMS_FN);
		log << tmp;
		exit(1);
	}

	else
	{
		file << getName() << endl;
		file.close();
		sprintf(tmp, "admin : Fichier '%s' sauve avec succes", TMS_FN);
		log << tmp;
	}
}

ostream & operator<<(ostream &s, Team &t)
{
	cout << "Operateur << (Team)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << "Nom : " << t.getName() << endl;
		s << "Vehicule : " << endl;
		s << t.getVehicule();
		s << "Competiteurs : " << endl;

		IterList<Competitor> iterateur(t.compList);

		if(!t.compList.empty())
		{
			iterateur.reset();

			while(!iterateur.end())
			{
				s << (Competitor &) iterateur << endl;
				iterateur++;
			}
		}
	}

	else
	{
		*tmp << t.getName() << endl; // nom de la team
		*tmp << t.getVehicule(); // véhicule
		*tmp << t.compList.getNbreElem() << endl; // nombre de compétiteurs
		IterList<Competitor> iterateur(t.compList);

		if(!t.compList.empty())
		{
			iterateur.reset();

			while(!iterateur.end())
			{
				*tmp << (Competitor &) iterateur;
				iterateur++;
			}
		}
	}

	return s;
}

istream & operator>>(istream &s, Team &t)
{
	cout << "Operateur >> (Team)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		s >> t.vehicule; // véhicule
	}

	else
	{
		int nbrelem;
		*tmp >> t.name; // nom de la team
		*tmp >> t.vehicule; // véhicule
		*tmp >> nbrelem; // nombre de compétiteurs
		Competitor c;

		for(int i = 0; i < nbrelem; i++)
		{
			*tmp >> c;
			t.compList.insert(c);
		}
	}

	return s;
}
