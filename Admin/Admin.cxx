#include "Admin.h"
#include <fstream.h>

Admin::Admin(void)
{
	cout << "Constructeur par defaut (Admin)" << endl;
	log.setFileName(LOG_FN);
	loadFederationAdminList();
	loadTeamMemberList();
	loadCircuitVector();
}

Admin::~Admin(void)
{
	cout << "Destructeur (Admin)" << endl;
	saveFederationAdminList();
	saveTeamMemberList();
	saveCircuitVector();
}

void Admin::loadFederationAdminList(void)
{
	FederationAdmin fa;
	char tmp[255];
	ifstream file(FED_FN, ios::in);

	if(!file) // tentative d'ouverture du fichier 'FederationAdmin.dat'
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", FED_FN);
		log << tmp;
	}

	else
	{
		file >> fa;

		while(!file.eof())
		{
			faList.insert(fa);
			file >> fa;
		}

		file.close();
		log << "admin : la liste FederationAdmin a ete cree avec succes";
	}
}

void Admin::saveFederationAdminList(void)
{
	char tmp[255];
	ofstream file(FED_FN, ios::out | ios::trunc);

	if(!file)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", FED_FN);
		log << tmp;
		exit(1);
	}

	IterList<FederationAdmin> iterateur(faList);

	if(!faList.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			file << (FederationAdmin &) iterateur;
			iterateur++;
		}
	}

	file.close();
	log << "admin : la liste FederationAdmin a ete sauvee avec succes";
}

void Admin::loadTeamMemberList(void)
{
	char tmp[255];
	TeamMember tm;
	ifstream file(TEM_FN, ios::in);

	if(!file)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", TEM_FN);
		log << tmp;
	}

	else
	{
		file >> tm;

		while(!file.eof())
		{
			tmList.insert(tm);
			file >> tm;
		}

		file.close();
		log << "admin :la liste TeamMember a ete cree avec succes";
	}
}

void Admin::saveTeamMemberList(void)
{
	char tmp[255];
	ofstream file(TEM_FN, ios::out | ios::trunc);

	if(!file)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", TEM_FN);
		log << tmp;
		exit(1);
	}

	IterList<TeamMember> iterateur(tmList);

	if(!tmList.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			file << (TeamMember &) iterateur;
			iterateur++;
		}
	}

	file.close();
	log << "admin : la liste TeamMember a ete sauvee avec succes";
}

void Admin::loadCircuitVector(void)
{
	char tmp[255];
	Circuit c;
	ifstream file(CIR_FN, ios::in);

	if(!file)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", CIR_FN);
		log << tmp;
	}

	else
	{
		file >> c;

		while(!file.eof())
		{
			ccVector.ajout(c);
			file >> c;
		}

		file.close();
		log << "admin : le vecteur Circuit a ete cree avec succes";
	}
}

void Admin::saveCircuitVector(void)
{
	char tmp[255];
	ofstream file(CIR_FN, ios::out | ios::trunc);

	if(!file)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", CIR_FN);
		log << tmp;
		exit(1);
	}

	IterVector<Circuit> iterateur(ccVector);

	if(!ccVector.empty())
	{
		iterateur.reset();

		while(!iterateur.end())
		{
			if(((Circuit &) iterateur).getNom() != "default")
			{
				file << (Circuit &) iterateur;
			}

			iterateur++;
		}
	}

	file.close();
	log << "admin : le vecteur Circuit a ete sauve avec succes";
}

void Admin::afficherUtilisateurs(void)
{
	char tmp[255];
	string ch;
	ifstream file(USR_FN, ios::in);

	cout << "Utilisateurs" << endl << "************" << endl << endl;

	if(!file) // tentative d'ouverture du fichier 'User.txt'
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", USR_FN);
		log << tmp;
	}

	else
	{
		file >> ch;

		while(!file.eof())
		{
			ch = ch.substr(0, ch.find(':')); // pseudo
			cout << ch << endl;
			file >> ch;
		}

		file.close();
	}
}

void Admin::afficherCircuits(void)
{
	cout << "Circuits" << endl << "********" << endl << endl;
	ccVector.Affichage();
}

void Admin::ajouterFederationAdmin(void)
{
	FederationAdmin fa;
	cin >> fa;
	faList.insert(fa);
	ajouterUtilisateur(fa.getLogin());
}

void Admin::ajouterTeamMember(void)
{
	TeamMember tm;
	cin >> tm;
	tmList.insert(tm);
	ajouterUtilisateur(tm.getLogin());
}

void Admin::ajouterCircuit(void)
{
	Circuit c;
	cin >> c;
	ccVector.ajout(c);
}

void Admin::ajouterUtilisateur(string username)
{
	char tmp[255];
	string password;
	ofstream file(USR_FN, ios::out | ios::app);

	if(!file)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", USR_FN);
		log << tmp;
		exit(1);
	}

	cout << "Entrez un mot de passe : ";
	cin >> password;
	file << username << ":" << password << endl;
	file.close();
	log << ("admin : utilisateur '" + username + "' cree avec succes").c_str();
}

void Admin::changePassword(void)
{
	char tmp[255];
	string oldPassword;
	string oldPasswordUsr;
	string newPasswordUsr;
	string newPasswordCfm;
	ifstream fileR(ADM_FN, ios::in); // lecture de l'ancien mot de passe

	if(!fileR)
	{
		sprintf(tmp, "admin : fichier '%s' non trouve", ADM_FN);
		log << tmp;
	}

	else
	{
		fileR >> oldPassword;
		fileR.close();
		oldPassword = oldPassword.substr(oldPassword.find(':') + 1);

		ofstream fileW(ADM_FN, ios::out | ios::trunc); // écriture du nouveau mot de passe

		if(!fileW)
		{
			sprintf(tmp, "admin : fichier '%s' non trouve", ADM_FN);
			log << tmp;
			exit(1);
		}

		else
		{
			do
			{
				cout << "Entrez l'ancien mot de passe : ";
				cin >> oldPasswordUsr;

				if(oldPassword != oldPasswordUsr)
				{
					cout << "Mot de passe incorrect." << endl;
					log << "admin : mot de passe incorrect";
				}

			} while(oldPassword != oldPasswordUsr);

			do
			{
				cout << "Entrez le nouveau mot de passe : ";
				cin >> newPasswordUsr;
				cout << "Confirmez le nouveau mot de passe : ";
				cin >> newPasswordCfm;

				if(newPasswordUsr != newPasswordCfm)
				{
					cout << "Mot de passe different." << endl;
					log << "admin : mot de passe different";
				}

			} while(newPasswordUsr != newPasswordCfm);

			fileW << "admin:" << newPasswordUsr << endl;
			log << "admin : nouveau mot de passe enregistre";
		}

		fileW.close();
	}
}
