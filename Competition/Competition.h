#ifndef COMPETITION_H
#define COMPETITION_H
#include "MyList.h"
#include "MySortedList.h"
#include "Circuit.h"
#include "Race.h"
#include "Competitor.h"
#include "Vehicule.h"
#include "FichierLog.h"
#include "../Fichier.ini"

using namespace std;

class Competition
{
	friend istream & operator>>(istream &s, Competition &c);
	friend ostream & operator<<(ostream &s, Competition &c);
    private:
        string nom;
        string type; // circuit, route ou piste
        string typeVehicule; // voiture, moto, ...
		MyVector<Circuit> vecteurCircuit;
        MySortedList<Race> listeCourse;
		MySortedList<Competitor> listeConcurrent;
		FichierLog log;
    public:
        Competition(void);
		Competition(string nom);
		Competition(string nom, string type);
        Competition(string nom, string type, string typeVehicule);
        Competition(const Competition &c);
        ~Competition(void);
        void setNom(string nm);
        void setType(string typ);
        void setTypeVehicule(string typeVeh);
        string getNom(void) const;
        string getType(void) const;
        string getTypeVehicule(void) const;
		void ajouterConcurrent(void);
		void ajouterCourse(void);
		void listerConcurrent(void);
		void listerCourse(void);
		void loadCompetition(void);
		void loadCircuit(void);
		void saveCompetition(void);
		int verifierDossard(int dossard);
		void gererResultat(void);
		void afficherResultat(void);
};

#endif
