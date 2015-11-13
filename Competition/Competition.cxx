#include "Competition.h"
#include <fstream.h>

Competition::Competition(void)
{
	cout << "Constructeur par defaut (Competition)" << endl;
	setNom("default");
	setType("default");
	setTypeVehicule("default");
	log.setFileName(LOG_FN);
	loadCompetition();
	loadCircuit();
}

Competition::Competition(string nom)
{
	cout << "Constructeur d'intialisation (1) (Competition)" << endl;
	setNom(nom);
	setType("default");
	setTypeVehicule("default");
	log.setFileName(LOG_FN);
	loadCompetition();
	loadCircuit();
}

Competition::Competition(string nom, string type)
{
	cout << "Constructeur d'initialisation (2) (Competition)" << endl;
	setNom(nom);
	setType(type);
	setTypeVehicule("default");
	log.setFileName(LOG_FN);
	loadCompetition();
	loadCircuit();
}

Competition::Competition(string nom, string type, string typeVehicule)
{
	cout << "Constructeur d'initialisation (3) (Competition)" << endl;
	setNom(nom);
	setType(type);
	setTypeVehicule(typeVehicule);
	log.setFileName(LOG_FN);
	loadCompetition();
	loadCircuit();
}

Competition::Competition(const Competition &c)
{
	cout << "Constructeur de copie (Competition)" << endl;
	setNom(c.getNom());
	setType(c.getType());
	setTypeVehicule(c.getTypeVehicule());
	log.setFileName(LOG_FN);
	loadCompetition();
	loadCircuit();
}

Competition::~Competition(void)
{
	cout << "Destructeur (Competition)" << endl;
	saveCompetition();
}

void Competition::setNom(string nm)
{
	nom = nm;
}

void Competition::setType(string typ)
{
	type = typ;
}

void Competition::setTypeVehicule(string typeVeh)
{
	typeVehicule = typeVeh;
}

string Competition::getNom(void) const
{
	return nom;
}

string Competition::getType(void) const
{
	return type;
}

string Competition::getTypeVehicule(void) const
{
	return typeVehicule;
}

void Competition::ajouterConcurrent(void)
{
	char tmp[255];
	ifstream teamsFile(TMS_FN, ios::in);
	MySortedList<Competitor> tmpList; // liste de concurrents non inscrits

	if(!teamsFile)
	{
		sprintf(tmp, "Fichier '%s' non trouve", TMS_FN);
		log << tmp;
	}

	else
	{
		ifstream teamFile;
		string teamName; // nom de chaque équipe
		Vehicule vehicule; // véhicule
		int nbreConc = 0;

		teamsFile >> teamName;

		while(!teamsFile.eof())
		{
			teamFile.open((teamName + ".team").c_str(), ios::in);

			if(!teamFile)
			{
				log << ("Fichier '" + teamName + ".team' non trouve").c_str();
			}

			else
			{
				Competitor c;

				teamFile >> teamName;
				teamFile >> vehicule;
				teamFile >> nbreConc;

				if(nbreConc > 0)
				{
					teamFile >> c;

					while(!teamFile.eof())
					{
						tmpList.insert(c);
						teamFile >> c;
					}
				}

				else
				{
					log << ("Aucun enregistrement dans '" + teamName + ".team'").c_str();
				}

				teamFile.close();
			}

			teamsFile >> teamName;
		}

		teamsFile.close();

		IterList<Competitor> iterTmp(tmpList);
		int choix, dossard;

		iterTmp.reset();

		if(!tmpList.empty())
		{
			do
			{
				cout << (Competitor &) iterTmp << endl << endl;

				cout << "1. Ajouter ce concurrent" << endl;
				cout << "2. Passer ce concurrent" << endl;
				cout << "3. Quitter" << endl << endl;

				do
				{
					cout << "Choix ? ";
					cin >> choix;
				} while((choix < 1) || (choix > 3));

				switch(choix)
				{
					case 1:
						do
						{
							cout << "Numero de dossard du concurrent : ";
							cin >> dossard;

							if(verifierDossard(dossard))
							{
								cout << "Ce numero de dossard est deja utilise" << endl;
							}

						} while(verifierDossard(dossard));

						((Competitor &) iterTmp).setDossard(dossard);
						listeConcurrent.insert((Competitor &) iterTmp);
						tmpList.remove((Competitor &) iterTmp);
						iterTmp.reset();
						break;
					case 2:
						iterTmp++;

						if(iterTmp.end())
						{
							iterTmp.reset();
						}
						break;
					case 3:
						break;
				}
			} while((choix != 3) && (!tmpList.empty()));
		}
	}
}

void Competition::ajouterCourse(void)
{
	int choix;
	Race r;
	IterVector<Circuit> iterCircuit(vecteurCircuit);

	iterCircuit.reset();

	if(!vecteurCircuit.empty())
	{
		do
		{
			cout << (Circuit &) iterCircuit << endl;

			cout << "1. Ajouter ce circuit" << endl;
			cout << "2. Passer ce circuit" << endl;
			cout << "3. Quitter" << endl << endl;

			do
			{
				cout << "Votre choix ? ";
				cin >> choix;
			} while((choix < 1) || (choix > 3));

			switch(choix)
			{
				case 1:
					cin >> r;
					r.setCircuit(&((Circuit &) iterCircuit));
					listeCourse.insert(r);
					iterCircuit++;
					break;
				case 2:
					iterCircuit++;

					if(iterCircuit.end())
					{
						iterCircuit.reset();
					}
					break;
				case 3:
					break;
			}
		} while(choix != 3);
	}
}

void Competition::listerConcurrent(void)
{
	IterList<Competitor> iterateur(listeConcurrent);

	cout << "Liste des concurrents : " << endl;

	if(!listeConcurrent.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			cout << (Competitor &) iterateur << endl;
			iterateur++;
		}
	}
}

void Competition::listerCourse(void)
{
	IterList<Race> iterateur(listeCourse);

	cout << "Liste des courses : " << endl;

	if(!listeCourse.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			cout << (Race &) iterateur;
			iterateur++;
		}
	}
}

void Competition::loadCompetition(void)
{
	ifstream file((getNom() + ".comp").c_str(), ios::in);

	if(!file)
	{
		log << ("Fichier '" + getNom() + ".comp' non trouve").c_str();
		cin >> *this; // initialisation de la compétition
	}

	else
	{
		file >> *this;
		file.close();
		log << ("admin : Fichier '" + getNom() + ".comp' charge avec succes").c_str();
	}
}

void Competition::loadCircuit(void)
{
	char tmp[255];
	ifstream file(CIR_FN, ios::in);

	if(!file)
	{
		sprintf(tmp, "Fichier '%s' non trouve", CIR_FN);
		log << tmp;
	}

	else
	{
		Circuit c;
		file >> c;

		while(!file.eof())
		{
			vecteurCircuit.ajout(c);
			file >> c;
		}

		file.close();
	}
}

void Competition::saveCompetition(void)
{
	ofstream file((getNom() + ".comp").c_str(), ios::out);

	if(!file)
	{
		log << ("Fichier '" + getNom() + ".comp' non trouve").c_str();
		exit(1);
	}

	file << *this;
	file.close();
	log << ("admin : Fichier '" + getNom() + ".comp' sauve avec succes").c_str();
}

int Competition::verifierDossard(int dossard)
{
	IterList<Competitor> iterateur(listeConcurrent);

	if(!listeConcurrent.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			if(dossard == ((Competitor &) iterateur).getDossard())
			{
				return 1;
			}

			iterateur++;
		}
	}

	return 0;
}

void Competition::gererResultat(void)
{
	int resultats[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
	int choix, choixSm, cpt = 0;

	if(!listeCourse.empty())
	{
		IterList<Race> iterCourse(listeCourse);
		iterCourse.reset();

		do
		{
			cout << (Race &) iterCourse << endl;

			cout << "1. Choisir cette course" << endl;
			cout << "2. Passer cette course" << endl;
			cout << "3. Quitter" << endl << endl;

			do
			{
				cout << "Votre choix ? ";
				cin >> choix;
			} while(choix < 1 || choix > 3);

			switch(choix)
			{
				case 1:
					if(!listeConcurrent.empty())
					{
						IterList<Competitor> iterConcurrent(listeConcurrent);
						iterConcurrent.reset();

						do
						{
							cout << (Competitor &) iterConcurrent << endl << endl;

							cout << "1. Choisir ce concurrent" << endl;
							cout << "2. Passer ce concurrent" << endl;
							cout << "3. Quitter" << endl << endl;

							do
							{
								cout << "Votre choix ? ";
								cin >> choixSm;
							} while(choixSm < 1 || choixSm > 3);

							switch(choixSm)
							{
								case 1:
									if(!((Race &) iterCourse).verifierDossard(((Competitor &) iterConcurrent).getDossard()))
									{
										cout << ((Competitor &) iterConcurrent).getDossard() << endl;
										((Race &) iterCourse).ajouterDossard(((Competitor &) iterConcurrent).getDossard());
										((Competitor &) iterConcurrent).setScore(resultats[cpt]);
										cpt++; // podium
										iterConcurrent++;
									}
									break;
								case 2:
									iterConcurrent++;

									if(iterConcurrent.end())
									{
										iterConcurrent.reset();
									}
									break;
								case 3:
									break;
							}

							if(iterConcurrent.end())
							{
								iterConcurrent.reset();
							}
						} while(choixSm != 3);

						iterCourse++;
					}
					break;
				case 2:
					iterCourse++;

					if(iterCourse.end())
					{
						iterCourse.reset();
					}
					break;
				case 3:
					break;
			}

			if(iterCourse.end())
			{
				iterCourse.reset();
			}
		} while(choix != 3);
	}
}

void Competition::afficherResultat(void)
{
	int choix, i;

	if(!listeCourse.empty())
	{
		IterList<Race> iterCourse(listeCourse);

		iterCourse.reset();

		do
		{
			cout << (Race &) iterCourse << endl;
			
			cout << "1. Choisir cette course" << endl;
			cout << "2. Passer cette course" << endl;
			cout << "3. Quitter" << endl << endl;

			do
			{
				cout << "Votre choix ? ";
				cin >> choix;
			} while(choix < 1 || choix > 3);

			if(choix == 1)
			{
				i = 0;
				IterVector<int> iterDossard(((Race &) iterCourse).getResultats());
				IterList<Competitor> iterConcurrent(listeConcurrent);

				iterDossard.reset();

				while (i < (((Race &) iterCourse).getResultats().getNbreElem()))
				{
					iterConcurrent.reset();

					while((!iterConcurrent.end()) && ((int &) iterDossard != ((Competitor &) iterConcurrent).getDossard()))
					{
						iterConcurrent++;
						
					}

					cout << endl << "Position [" << i + 1<< "]" << endl << endl;
					cout << (Competitor &) iterConcurrent << endl << endl;
					iterDossard++;
					i++;
				}
			}

			else
			{
				if(choix == 2)
				{
					iterCourse++;

					if(iterCourse.end())
					{
						iterCourse.reset();
					}
				}
			}

		} while(choix != 3);
	}
}

istream & operator>>(istream &s, Competition &c)
{
	cout << "Operateur >> (Competition" << endl;
	ifstream * tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		cout << "Entrez le type de competition : ";
		cin >> c.type;
		cout << "Entrez le type de vehicule : ";
		cin >> c.typeVehicule;
	}

	else
	{
		int nbrelem;
		Competitor comp;

		*tmp >> c.nom; // nom de la compétition
		*tmp >> c.type; // type de la compétition
		*tmp >> c.typeVehicule; // type de véhicule

		*tmp >> nbrelem; // nombre de concurrents

		for(int i = 0; i < nbrelem; i++)
		{
			*tmp >> comp;
			c.listeConcurrent.insert(comp);
		}

		Race r;
		*tmp >> nbrelem; // nombre de courses

		for(int i = 0; i < nbrelem; i++)
		{
			*tmp >> r;
			c.listeCourse.insert(r);
		}
	}

	return s;
}

ostream & operator<<(ostream &s, Competition &c)
{
	cout << "Operateur << (Competition)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		cout << "Nom : " << c.getNom() << endl;
		cout << "Type : " << c.getType() << endl;
		cout << "Type vehicule : " << c.getTypeVehicule() << endl;
		c.listerConcurrent();
		c.listerCourse();
	}

	else
	{
		*tmp << c.getNom() << endl; // nom de la compétition
		*tmp << c.getType() << endl; // type de la compétition
		*tmp << c.getTypeVehicule() << endl; // type de véhicule

		IterList<Competitor> iterConcurrent(c.listeConcurrent);

		*tmp << c.listeConcurrent.getNbreElem() << endl; // nombre de concurrents

		if(!c.listeConcurrent.empty())
		{
			iterConcurrent.reset();

			while(!iterConcurrent.end())
			{
				*tmp << (Competitor &) iterConcurrent << endl;
				iterConcurrent++;
			}
		}

		IterList<Race> iterRace(c.listeCourse);

		*tmp << c.listeCourse.getNbreElem() << endl; // nombre de courses

		if(!c.listeCourse.empty())
		{
			iterRace.reset();

			while(!iterRace.end())
			{
				*tmp << (Race &) iterRace;
				iterRace++;
			}
		}
	}

	return s;
}
