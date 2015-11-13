RC=Race
CIR=Circuit
DAT=Date
PER=Person
CMP=Competitor
AUTPER=AuthorisedPerson
FEDADM=FederationAdmin
TEAMMB=TeamMember
EXBASE=ExceptionBase
EXDATE=InvalidDateException
EXSIZE=InvalidRaceSizeException
MYVECT=MyVector
MYLIST=MyList
MYSORTEDLIST=MySortedList
FICHLG=FichierLog
FICHCR=FichierCircuit
MENU=Menu
LOGIN=Login
COMP=Competition
ADM=Admin
TEAM=Team
VEHI=Vehicule
OBJS=Race.o Circuit.o Date.o Person.o Competitor.o  AuthorisedPerson.o FederationAdmin.o TeamMember.o ExceptionBase.o InvalidDateException.o InvalidRaceSizeException.o MyVector.o MyList.o MySortedList.o FichierLog.o FichierCircuit.o Menu.o Login.o Competition.o Admin.o Team.o Vehicule.o
CPP=c++ -Wno-deprecated -I$(RC) -I$(CIR) -I$(DAT) -I$(PER) -I$(CMP) -I$(AUTPER) -I$(FEDADM) -I$(TEAMMB) -I$(EXBASE) -I$(EXDATE) -I$(EXSIZE) -I$(MYVECT) -I$(MYLIST) -I$(MYSORTEDLIST) -I$(FICHLG) -I$(FICHCR) -I$(MENU) -I$(LOGIN) -I$(COMP) -I$(ADM) -I$(TEAM) -I$(VEHI)

all:	Main

Test2:	Test2.cxx $(OBJS)
	$(CPP) Test2.cxx $(OBJS) -o Test2

Test3:	Test3.cxx $(OBJS)
	$(CPP) Test3.cxx $(OBJS) -o Test3

Test4:	Test4.cxx $(OBJS)
	$(CPP) Test4.cxx $(OBJS) -o Test4

Test5:	Test5.cxx $(OBJS)
	$(CPP) Test5.cxx $(OBJS) -o Test5

Test6:	Test6.cxx $(OBJS)
	$(CPP) Test6.cxx $(OBJS) -o Test6

Test7:	Test7.cxx $(OBJS)
	$(CPP) Test7.cxx $(OBJS) -o Test7

Main:	Main.cxx $(OBJS)
	$(CPP) Main.cxx $(OBJS) -o Main

Race.o:	$(RC)/Race.cxx $(RC)/Race.h
	$(CPP) $(RC)/Race.cxx -c

Circuit.o: $(CIR)/Circuit.cxx $(CIR)/Circuit.h
	$(CPP) $(CIR)/Circuit.cxx -c

Date.o:	$(DAT)/Date.cxx $(DAT)/Date.h
	$(CPP) $(DAT)/Date.cxx -c

Person.o:	$(PER)/Person.cxx $(PER)/Person.h
	$(CPP) $(PER)/Person.cxx -c

Competitor.o:	$(CMP)/Competitor.cxx $(CMP)/Competitor.h
	$(CPP) $(CMP)/Competitor.cxx -c
	
AuthorisedPerson.o:	$(AUTPER)/AuthorisedPerson.cxx $(AUTPER)/AuthorisedPerson.h
	$(CPP) $(AUTPER)/AuthorisedPerson.cxx -c

FederationAdmin.o:	$(FEDADM)/FederationAdmin.cxx $(FEDADM)/FederationAdmin.h
	$(CPP) $(FEDADM)/FederationAdmin.cxx -c

TeamMember.o:	$(TEAMMB)/TeamMember.cxx $(TEAMMB)/TeamMember.h
	$(CPP) $(TEAMMB)/TeamMember.cxx -c

ExceptionBase.o:	$(EXBASE)/ExceptionBase.cxx $(EXBASE)/ExceptionBase.h
	$(CPP) $(EXBASE)/ExceptionBase.cxx -c

InvalidDateException.o:	$(EXDATE)/InvalidDateException.cxx $(EXDATE)/InvalidDateException.h
	$(CPP) $(EXDATE)/InvalidDateException.cxx -c

InvalidRaceSizeException.o:	$(EXSIZE)/InvalidRaceSizeException.cxx $(EXSIZE)/InvalidRaceSizeException.h
	$(CPP) $(EXSIZE)/InvalidRaceSizeException.cxx -c

MyVector.o:	$(MYVECT)/MyVector.cxx $(MYVECT)/MyVector.h
	$(CPP) $(MYVECT)/MyVector.cxx -c
	
MyList.o:	$(MYLIST)/MyList.cxx $(MYLIST)/MyList.h
	$(CPP) $(MYLIST)/MyList.cxx -c

MySortedList.o:	$(MYSORTEDLIST)/MySortedList.cxx $(MYSORTEDLIST)/MySortedList.h
	$(CPP) $(MYSORTEDLIST)/MySortedList.cxx -c

FichierLog.o:	$(FICHLG)/FichierLog.cxx $(FICHLG)/FichierLog.h
	$(CPP) $(FICHLG)/FichierLog.cxx -c

FichierCircuit.o:	$(FICHCR)/FichierCircuit.cxx $(FICHCR)/FichierCircuit.h
	$(CPP) $(FICHCR)/FichierCircuit.cxx -c

Menu.o:	$(MENU)/Menu.cxx $(MENU)/Menu.h
	$(CPP) $(MENU)/Menu.cxx -c

Login.o:	$(LOGIN)/Login.cxx $(LOGIN)/Login.h
	$(CPP) $(LOGIN)/Login.cxx -c

Competition.o:	$(COMP)/Competition.cxx $(COMP)/Competition.h
	$(CPP) $(COMP)/Competition.cxx -c

Admin.o:	$(ADM)/Admin.cxx $(ADM)/Admin.h
	$(CPP) $(ADM)/Admin.cxx -c

Team.o:	$(TEAM)/Team.cxx $(TEAM)/Team.h
	$(CPP) $(TEAM)/Team.cxx -c

Vehicule.o:	$(VEHI)/Vehicule.cxx $(VEHI)/Vehicule.h
	$(CPP) $(VEHI)/Vehicule.cxx -c

clean:
	rm -f $(OBJS) core Main *.log *.txt *.dat *.team *.comp

clobber:	clean
	rm -f tags $(PROGRAM)
