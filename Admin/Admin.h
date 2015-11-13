#ifndef ADMIN_H
#define ADMIN_H
#include "MyVector.h"
#include "MySortedList.h"
#include "FichierLog.h"
#include "FederationAdmin.h"
#include "TeamMember.h"
#include "Circuit.h"
#include "../Fichier.ini"

using namespace std;

class Admin
{
	private:
		MySortedList<FederationAdmin> faList;
		MySortedList<TeamMember> tmList;
		MyVector<Circuit> ccVector;
		FichierLog log;
		void loadFederationAdminList(void);
		void saveFederationAdminList(void);
		void loadTeamMemberList(void);
		void saveTeamMemberList(void);
		void loadCircuitVector(void);
		void saveCircuitVector(void);
	public:
		Admin(void);
		~Admin(void);
		void afficherUtilisateurs(void);
		void afficherCircuits(void);
		void ajouterFederationAdmin(void);
		void ajouterTeamMember(void);
		void ajouterCircuit(void);
		void ajouterUtilisateur(string username);
		void changePassword(void);
};

#endif
