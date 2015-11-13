#include "AuthorisedPerson.h"
#include "Circuit.h"
#include "Competitor.h"
#include "FichierLog.h"
#include "Date.h"
#include "ExceptionBase.h"
#include "FederationAdmin.h"
#include "Person.h"
#include "Race.h"
#include "TeamMember.h"
#include "Login.h"
#include "Menu.h"
#include "Admin.h"
#include "Competition.h"
#include "Team.h"
#include "MyList.h"
#include "MySortedList.h"

char menuAdmin(void);
char menuTeamMember(string nom);
char menuFederationAdmin(string nom);

int main(int argc, char *argv[])
{
	// login
	char session = 'N';
	Login log;

	do
	{
		log.makeConnection();

		if(log.getLogged())
		{
			switch(log.getTypeCompte())
			{
				case ADMIN:
					session = menuAdmin();
					break;
				case FEDERATION_ADMIN:
					session = menuFederationAdmin(log.getNomCompetition());
					break;
				case TEAM_MEMBER:
					session = menuTeamMember(log.getNomEquipe());
					break;
				default:
					session = 'Q';
					break;
			}
		}
		cout << "\x1B[2J\x1B[1;1H";
	} while(session == 'N');

	log.closeConnection();
}

char menuAdmin(void)
{
	Admin admin;
	char tmp;

	char *optionsMenu[] = {"1. Utilisateurs", "2. Circuits", "N. Nouvelle session"};
	int nbOptionsMenu = 3;
	char *optionsSousMenu[][N_C_SOUS_MENU] = 
		{
			{"1. Afficher la liste des utilisateurs", \
				"2. Creer un administrateur de federation", \
				"3. Creer un administrateur d'equipe", \
				"4. Changer le mot de passe 'admin'"},
			{"1. Ajouter un circuit", "2. Afficher la liste des circuits disponibles"},
			{},
		};
	int nbOptionsSousMenu[] = {4, 2, 0, 0};

	MenuAvecSm menu(optionsMenu, nbOptionsMenu, optionsSousMenu, nbOptionsSousMenu);

	// affichage du menu

	do
	{
		cout << "\x1B[2J\x1B[1;1H";
		menu.afficheMenu("*** RacingWorldChampionship - Administrator ***\n***********************************************\n");

		switch(menu.getChoix())
		{
			case '1':
				menu.afficheMenuSm();
				switch(menu.getChoixSm())
				{
					case '1':
						admin.afficherUtilisateurs();
						cin >> tmp;
						break;
					case '2':
						admin.ajouterFederationAdmin();
						break;
					case '3':
						admin.ajouterTeamMember();
						break;
					case '4':
						admin.changePassword();
						break;
				}
				break;
			case '2':
				menu.afficheMenuSm();
				switch(menu.getChoixSm())
				{
					case '1':
						admin.ajouterCircuit();
						break;
					case '2':
						admin.afficherCircuits();
						cin >> tmp;
						break;
				}
				break;
			case 'N':
				break;
			case 'Q':
				cout << "Au revoir" << endl;
				break;
		}

	} while(menu.getChoix() != 'N' && menu.getChoix() != 'Q');

	return menu.getChoix();
}

char menuTeamMember(string nom)
{
	char tmp;
	string ch;
	Team team(nom);

	char *optionsMenu[] = {"1. Afficher mon equipe", "2. Ajouter un concurrent", \
		"3. Configurer le vehicule", "N. Nouvelle session"};
	int nbOptionsMenu = 4;
	Menu menu(optionsMenu, nbOptionsMenu);

	// affichage du menu

	do
	{
		cout << "\x1B[2J\x1B[1;1H";
		ch = "*** RacingWorldChampionship - " + nom + " Administrator ***\n\n";
		menu.afficheMenu(ch.data());

		switch(menu.getChoix())
		{
			case '1':
				team.showTeam();
				cin >> tmp;
				break;
			case '2':
				team.addCompetitor();
				break;
			case '3':
				team.setVehicule();
				break;
			case 'N':
				break;
			case 'Q':
				cout << "Au revoir" << endl;
				break;
		}
	} while(menu.getChoix() != 'N' && menu.getChoix() != 'Q');

	return menu.getChoix();
}

char menuFederationAdmin(string nom)
{
	char tmp;
	string ch;
	int dossard;
	Competition competition(nom);
	char *optionsMenu[] = {"1. Afficher ma competition", "2. Ajouter un concurrent", \
		"3. Courses", "N. Nouvelle session"};
	int nbOptionsMenu = 4;
	char *optionsSousMenu[][N_C_SOUS_MENU] = 
		{
			{},
			{},
			{"1. Ajouter une course", "2. Gerer les resultats d'une course", \
				"3. Afficher les resultats d'une course"},
			{},
			{},
		};
	int nbOptionsSousMenu[] = {0, 0, 3, 0, 0};
	MenuAvecSm menu(optionsMenu, nbOptionsMenu, optionsSousMenu, nbOptionsSousMenu);

	// affichage du menu

	do
	{
		cout << "\x1B[2J\x1B[1;1H";
		ch = "*** RacingWorldChampionship - Welcome " + nom + " Administrator ***\n\n";
		menu.afficheMenu(ch.data());

		switch(menu.getChoix())
		{
			case '1':
				cout << competition; // affichage des concurrents
				cin >> tmp;
				break;
			case '2':
				competition.ajouterConcurrent();
				break;
			case '3':
				menu.afficheMenuSm();

				switch(menu.getChoixSm())
				{
					case '1':
						competition.ajouterCourse();
						break;
					case '2':
						competition.gererResultat();
						break;
					case '3':
						competition.afficherResultat();
						cin >> tmp;
						break;
				}
		}
	} while(menu.getChoix() != 'N' && menu.getChoix() != 'Q');

return menu.getChoix();
}
