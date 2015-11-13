#include "Login.h"
#include <fstream>

Login::Login(void)
{
	cout << "Constructeur par defaut (Login)" << endl;
	setPseudo("default");
	setPassword("default");
	setTypeCompte(0);
	setLogged(false);
	log.setFileName(LOG_FN);
}

string Login::getPseudo(void) const
{
	return pseudo;
}

string Login::getPassword(void) const
{
	return password;
}

int Login::getTypeCompte(void)
{
	return typeCompte;
}

bool Login::getLogged(void)
{
	return logged;
}

string Login::getNomCompetition(void) const
{
	return fa.getNomCompetition();
}

string Login::getNomEquipe(void) const
{
	return tm.getNomEquipe();
}

void Login::setPseudo(string p)
{
	pseudo = p;
}

void Login::setPassword(string p)
{
	password = p;
}

void Login::setTypeCompte(int tc)
{
	typeCompte = tc;
}

void Login::setLogged(bool l)
{
	logged = l;
}

int Login::extractTypeCompte(void)
{
	char tmp[255];

	ifstream fileTm(TEM_FN, ios::in);

	if(!fileTm) // tentative d'ouverture du fichier 'TeamMember.dat'
	{
		sprintf(tmp, "Fichier '%s' non trouve", TEM_FN);
		log << tmp;
	}

	else
	{
		fileTm >> tm;

		while(!fileTm.eof())
		{
			if(tm.getLogin() == getPseudo())
			{
				log << ("'" + getPseudo() + "' est maintenant TeamMember").c_str();
				fileTm.close();
				return TEAM_MEMBER;
			}

			fileTm >> tm;
		}

		fileTm.close();
	}

	ifstream fileFa(FED_FN, ios::in);

	if(!fileFa) // tentative d'ouverture du fichier 'FederationAdmin.dat'
	{
		sprintf(tmp, "Fichier '%s' non trouve", FED_FN);
		log << tmp;
	}

	else
	{
		fileFa >> fa;

		while(!fileFa.eof())
		{
			if(fa.getLogin() == getPseudo())
			{
				log << ("'" + getPseudo() + "' est maintenant FederationAdmin").c_str();
				fileFa.close();
				return FEDERATION_ADMIN;
			}

			fileFa >> fa;
		}

		fileFa.close();
	}

	return 0;
}

string Login::extractPseudo(string &ch)
{
	return ch.substr(0, ch.find(':'));
}

string Login::extractPassword(string &ch)
{
	return ch.substr(ch.find(':')+1);
}

bool Login::makeConnection(void)
{
	char tmp[255];
	string login;
	string password;
	string ch;
	bool quit;
	bool trouve;

	if(getLogged())
	{
		closeConnection();
	}

	do
	{
		quit = true;
		cout << "\x1B[2J\x1B[1;1H";
		cout << "*** Welcome to RacingWorldChampionship ***" << endl << endl;
		cout << "Nom d'utilisateur : ";
		cin >> login;
		setPseudo(login);
		cout << "Mot de passe : ";
		cin >> password;
		setPassword(password);
		log << ("'" + getPseudo() + "' : tentative de connexion").c_str();

		if(getPseudo() == "admin") // recherche dans le fichier 'Admin.txt'
		{
			ifstream file(ADM_FN, ios::in); 

			if(!file) // tentative d'ouverture du fichier 'Admin.txt'
			{
				sprintf(tmp, "Fichier '%s' non trouve", ADM_FN);
				log << tmp;

				ch = "admin:admin";
				ofstream fileW(ADM_FN, ios::out);

				if(!fileW)
				{
					exit(1);
				}

				fileW << ch << endl;
				fileW.close();
				sprintf(tmp, "Fichier '%s' cree", ADM_FN);
				log << tmp;
			}

			else
			{
				ch = "";
				file >> ch;
				file.close();
			}

			if(extractPassword(ch) == getPassword())
			{
				log << "admin : connecte";
				setTypeCompte(ADMIN);
				setLogged(true);
			}

			else
			{
				log << "admin : mot de passe invalide";
			}
		}

		else // recherche dans le fichier 'User.txt'
		{
			trouve = false;

			ifstream file(USR_FN, ios::in);
	
			if(!file) // tentative d'ouverture du fichier 'User.txt'
			{
				sprintf(tmp, "Fichier '%s' non trouve", USR_FN);
				log << tmp;
			}

			else
			{
				do
				{
					ch = "";
					file >> ch;

					if(extractPseudo(ch) == getPseudo())
					{
						if(extractPassword(ch) == getPassword())
						{
							trouve = true;
							log << ("'" + getPseudo() + "' : connecte").c_str();
							setTypeCompte(extractTypeCompte());
							setLogged(true);
						}
					}
				} while(!trouve && !file.eof());

				file.close();
			}

			if(!trouve)
			{
				log << ("'" + getPseudo() + "' : connexion impossible").c_str();
			}
		}

		if(!getLogged())
		{
			char choix;

			cout << endl << "Les identifiants sont invalide." << endl << endl;
			cout << "Q. Quitter." << endl;
			cout << "R. Reessayer." << endl << endl;
			cout << "Votre choix ? ";

			do
			{
				cin >> choix;
			} while(toupper(choix) != 'Q' && toupper(choix) != 'R');

			if(toupper(choix) == 'R')
			{
				quit = false;
			}
		}

	} while(!quit);

	return getLogged();
}

bool Login::closeConnection(void)
{
	if(getLogged())
	{
		log << ("'" + getPseudo() + "' : deconnexion").c_str();
		setPseudo("");
		setPassword("");
		setLogged(false);
		setTypeCompte(0);
		return true;
	}

	else
	{
		log << ("'" + getPseudo() + "' : deconnexion impossible").c_str();
		return false;
	}
}
