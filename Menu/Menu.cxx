#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"

int getValAnsi(char ta)
{
	char *codes = " G  SC I";
	char *p = strchr(codes, ta);

	if(!p)
	{
		return 0;
	}

	else
	{
		return (p - codes);
	}
}

ostream & clr(ostream& s)
{
	s << "\x1B[2J\x1B[1;1H";
	return s;
}

Menu::Menu(void)
{
	cout << "Constructeur par defaut (Menu)" << endl;
	nChoixMenu = 1;
	choix = 'Q';
}

// opt = tableau qui contient les choix possibles, no = nombre de choix
Menu::Menu(char *opt[], int no)
{
	cout << "Constructeur d'intialisation (Menu)" << endl;

	// opt est copié dans le tableau 'options' (variable membre)
	for(int i = 0; i < no; i++)
	{
		options[i] = new char[strlen(opt[i])+1];
		strcpy(options[i], opt[i]);
	}

	nChoixMenu = no;
	choix = 'Q';
}

void Menu::affiche(void)
{
	for(int i = 0; i < nChoixMenu; i++)
	{
		cout << options[i] << endl;
	}

	cout << "Q. Quitter" << endl << endl;
}

int Menu::choisir(void)
{
	// ch = tableau qui contient les différents possibilités de choix
	char *ch = new char [nChoixMenu+2], r;

	// On copie le premier caractère de chaque intitulé d'option dans ch
	for(int i = 0; i < nChoixMenu; i++)
	{
		char *pTrav = strchr(options[i], '.');
		pTrav--;
		ch[i] = *pTrav;
	}

	ch[nChoixMenu] = 'Q';
	ch[nChoixMenu+1] = 0;

	//Entree du choix par l'utilisateur et on le recherche dans ch
	cout << "Votre choix : ";

	do
	{
		cin >> r;
		r = toupper(r);		
	}

	while (!strchr(ch, r));

	cout << "\n";
	choix = r; // on enregistre le choix
	//Calcule quelle option a été choisie à partir de la position où l'occurence a été trouvée dans ch - la position de base du tableau 
	int test1;
	test1 = (strchr(ch, r) - ch);
	delete ch;
	return test1;
}

Menu::~Menu(void)
{
	cout << "Destructeur (Menu)" << endl;

	for(int i = 0; i < nChoixMenu; i++)
	{
		if(options[i])
		{
			cout << "Destruction de " << *(options[i]) << endl;
			delete [] options[i];
		}
	}
}

void Menu::afficheMenu(const char *t)
{
	cout << t << endl;
	affiche();
	choisir();
}

char Menu::getChoix(void)
{
	return choix;
}

void MenuAnsi::affiche(void)
{
	cout << endl;

	for(int i = 0; i < nChoixMenu; i++)
	{
		cout << "\x1B[" << getValAnsi(tAff) << "m" << options[i] << "\x1B[0m \n";
		cout << "\x1B[" << getValAnsi(tAff) << "m" << "(Q)uitter" << "\x1B[0m" << endl << endl;
	}
}

//noS = nombre de choix dans le sous-menu
MenuAvecSm::MenuAvecSm(char *opt[], int no, char *optSm[][N_C_SOUS_MENU], int noS[]) : Menu(opt, no)
{
	cout << endl;

	// nChoixMenu étant initialiser puisque le constructeur de 'menu' est appelé avant
	for(int i = 0; i < nChoixMenu; i++)
	{
		for (int j = 0; j < noS[i]; j++) 
		{
			optionsSm[i][j] = new char[strlen(optSm[i][j])+1];
			strcpy(optionsSm[i][j], optSm[i][j]);
		}

		// nombre de choix dans chaque sous_menu est stocké
		nChoixSousMenu[i] = noS[i];
	}
}

int MenuAvecSm::choisir(void)
{
	return (numChoix = Menu::choisir()); // numChoix = choix = sous_menu souhaité
}

void MenuAvecSm::afficheSm(void)
{
	// nChoixSousMenu = nombre de choix possibles dans le sous-menu souhaité (numChoix)
	for(int i = 0; i < nChoixSousMenu[numChoix]; i++)
	{
		cout << "\t " << optionsSm[numChoix][i] << " \n";
	}

	cout << "\t Q. Quitter" << endl << endl;
}

void MenuAvecSm::choisirSm(void)
{
	char *ch = new char[nChoixSousMenu[numChoix]+2], r; // Quitter et le 0 fin de chaine

	for(int i = 0; i < nChoixSousMenu[numChoix]; i++)
	{
		char *pTrav = strchr(optionsSm[numChoix][i], '.');
		pTrav--;
		ch[i] = *pTrav;
	}

	ch[nChoixSousMenu[numChoix]] = 'Q';
	ch[nChoixSousMenu[numChoix]+1] = 0;

	cout << "Votre choix : ";

	do
	{
		cin >> r;
		r = toupper(r);
	}

	while(!strchr(ch, r));

	cout << "\n";
	delete ch;
	choixSm = r;
}

void MenuAvecSm::afficheMenuSm(void)
{
	afficheSm();
	choisirSm();
}

char MenuAvecSm::getChoixSm(void)
{
	return choixSm;
}
