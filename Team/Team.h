#ifndef TEAM_H
#define TEAM_H
#include "MySortedList.h"
#include "FichierLog.h"
#include "Competitor.h"
#include "Vehicule.h"
#include "../Fichier.ini"

using namespace std;

class Team
{
	friend ostream & operator<<(ostream &s, Team &t);
	friend istream & operator>>(istream &s, Team &t);
	private:
		string name;
		MySortedList<Competitor> compList;
		Vehicule vehicule;
		FichierLog log;
		void loadTeam(void);
		void saveTeam(void);
	public:
		Team(void);
		Team(const string nm);
		Team(const Team &t);
		~Team();
		string getName(void) const;
		Vehicule getVehicule(void) const;
		void setName(const string nm);
		void setVehicule(void);
		void showTeam(void);
		void addCompetitor(void);
		void addTeamName(void);
};

#endif
