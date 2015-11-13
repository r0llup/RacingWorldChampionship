#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include "Date.h"

Date::Date(void)
{
	time_t t;
	struct tm *pt;

	t = time(0);
	pt = gmtime(&t);

	setJour(pt->tm_mday);
	setMois(pt->tm_mon+1);
	setAnnee(pt->tm_year+1900);
}

Date::Date(unsigned int j, unsigned int m, unsigned int a)
{
	setJour(j);
	setMois(m);
	setAnnee(a);
}

Date::Date(unsigned int j, unsigned int m)
{
	time_t t;
	struct tm *pt;

	t = time(0);
	pt = gmtime(&t);

	setJour(j);
	setMois(m);
	setAnnee(pt->tm_year+1900);
}

Date::Date(unsigned int j)
{
	time_t t;
	struct tm *pt;

	t = time(0);
	pt = gmtime(&t);

	setJour(j);
	setMois(pt->tm_mon+1);
	setAnnee(pt->tm_year+1900);
}

Date::Date(char *d)
{
	char cd[11], *dcd = cd;
	strcpy(cd, d);
	char *p = strchr(cd, '/');

	if(!p) // date mal formee
	{
		cout << "ici" << endl;
		InvalidDateException de("Format de date invalide");
		throw de;
	}

	*p++;
	setJour(atoi(dcd));
	dcd = p;

	p = strchr(dcd, '/');
	if(!p) // date mal formee
	{
		cout << "ici" << endl;
		InvalidDateException de("Format de date invalide");
		throw de;
		setJour(1);
		setMois(1);
		setAnnee(1900);
		return;
	}

	*p++;
	setMois(atoi(dcd));
	setAnnee(atoi(p));
	if(getAnnee() < 100) setAnnee(getAnnee() + 1900);
}

Date::Date(const Date &d)
{
	jour = d.jour;
	mois = d.mois;
	annee = d.annee;
}

unsigned int Date::getJour(void) const
{
	return jour;
}

unsigned int Date::getMois(void) const
{
	return mois;
}

unsigned int Date::getAnnee(void) const
{
	return annee;
}

void Date::setJour(unsigned int j)
{
	jour = j;
}

void Date::setMois(unsigned int m)
{
	mois = m;
}

void Date::setAnnee(unsigned int a)
{
	annee = a;
}

void Date::affiche(void)
{
	cout << "Date : " << getJour() << "/" << getMois() << "/" << getAnnee() << endl;
}

bool Date::operator<(const Date & d)
{
	if(getAnnee() > d.getAnnee())
	{
		return false;
	}

	else
	{	
		if(getAnnee() == d.getAnnee())
		{
			if(getMois() > d.getMois())
			{
				return false;
			}

			else
			{
				if(getMois() == d.getMois())
				{
					if(getJour() >= d.getJour())
					{
						return false;
					}

					else
					{
						return true;
					}
				}

				else
				{

					return true;
				}
			}
		}

		else
		{
			return true;
		}
	}
}

bool Date::operator<=(const Date & d)
{
	if(getAnnee() > d.getAnnee())
	{
		return false;
	}

	else
	{	
		if(getAnnee() == d.getAnnee())
		{
			if(getMois() > d.getMois())
			{
				return false;
			}

			else
			{
				if(getMois() == d.getMois())
				{
					if(getJour() > d.getJour())
					{
						return false;
					}

					else
					{
						return true;
					}
				}

				else
				{
					return true;
				}
			}
		}

		else
		{
			return true;
		}
	}
}

bool Date::operator==(const Date & d)
{
	if(getJour() == d.getJour() && getMois() == d.getMois() && getAnnee() == d.getAnnee())
	{
		return true;
	}

	return false;
}

bool Date::operator>(const Date & d)
{
	if(getAnnee() < d.getAnnee())
	{
		return false;
	}

	else
	{	
		if(getAnnee() == d.getAnnee())
		{
			if(getMois() < d.getMois())
			{
				return false;
			}

			else
			{
				if(getMois() == d.getMois())
				{
					if(getJour() < d.getJour())
					{
						return false;
					}

					else
					{
						if(getJour() == d.getJour())
						{
							return false;
						}

						else
						{
							return true;
						}
					}
				}

				else
				{
					return true;
				}
			}
		}

		else
		{
			return true;
		}
	}
}

bool Date::operator>=(const Date & d)
{
	if(getAnnee() < d.getAnnee())
	{
		return false;
	}

	else
	{	
		if(getAnnee() == d.getAnnee())
		{
			if(getMois() < d.getMois())
			{
				return false;
			}

			else
			{
				if(getMois() == d.getMois())
				{
					if(getJour() < d.getJour())
					{
						return false;
					}

					else
					{
						return true;
					}
				}

				else
				{
					return true;
				}
			}
		}

		else
		{
			return true;
		}
	}
}

istream & operator>>(istream & s, Date & d)
{
	ifstream *tmp;

	tmp = dynamic_cast<ifstream *> (&s);
	cout << "Operateur >> (Date)" << endl;

	if(tmp == 0)
	{
		cout << "Jour : ";
		s >> d.jour;
		cout << "Mois : ";
		s >> d.mois;
		cout << "Annee : ";
		s >> d.annee;
	}

	else
	{
		*tmp >> d.jour;
		*tmp >> d.mois;
		*tmp >> d.annee;
	}

	return s;
}

ostream & operator<<(ostream & s, const Date & d)
{
	ofstream *tmp;

	tmp = dynamic_cast<ofstream *> (&s);
	cout << "Operateur << (Date)" << endl;

	if(tmp == 0)
	{
		s << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee() << endl;
	}

	else
	{
		*tmp << d.jour << endl;
		*tmp  << d.mois << endl;
		*tmp << d.annee << endl;
	}

	return s;
}
