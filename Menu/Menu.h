#ifndef MENU_H
#define MENU_H

const int N_C_MENU = 12;
const int N_C_SOUS_MENU = 6;

class Menu
{
	protected:
		char *options[N_C_MENU]; // tableau contenant les choix possible
		int nChoixMenu; // nombre de choix
		char choix; // choix de l'utilisateur
		virtual void affiche(void);
		virtual int choisir(void);
	public:
		Menu(void);
		Menu(char *opt[], int no);
		/*Menu(const Menu &m);*/
		~Menu(void);
		// appel de la fonction affichage... (celle-ci etant declare en private, on y a pas accès)
		void afficheMenu(const char *t);
		char getChoix(void); // retourne le choix de l'utilisateur
};

class MenuAnsi: public virtual Menu
{
	protected:
		char tAff; // type d'affichage (G S C I)
		void affiche(void);
	public:
		MenuAnsi(void): Menu()
		{
			tAff = 'N';
		}

		MenuAnsi(char *opt[], int no, char ta) : Menu(opt, no)
		{
			tAff = ta;
		}
};

class MenuAvecSm : public virtual Menu
{
	protected:
		char *optionsSm[N_C_MENU][N_C_SOUS_MENU]; // tableau contenant les choix possibles
		int nChoixSousMenu[N_C_MENU]; // nombre de choix pour chaque sous menu
		int choixSm; // choix de l'utilisateur
		int numChoix;
		int choisir(void);
		void afficheSm(void);
		void choisirSm(void);
	public:
		MenuAvecSm(char *opt[], int no, char *optSm[][N_C_SOUS_MENU], int noS[]);
		void afficheMenuSm(void);
		char getChoixSm(void);
};

class MenuAnsiAvecSm : public MenuAnsi, public MenuAvecSm
{
	public:
		MenuAnsiAvecSm(char *opt[], int no, char *optS[][N_C_SOUS_MENU], int noS[], char ta) : MenuAvecSm(opt, no, optS, noS), MenuAnsi(opt, no, ta), Menu(opt, no)
		{
			tAff = ta;
		}

		void afficheMenu(char *t)
		{
			cout << t << endl;
			MenuAnsi::affiche();
			MenuAvecSm::choisir();
		}
};

#endif
