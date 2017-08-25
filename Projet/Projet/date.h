#include<iostream>

using namespace std;

class date
{
 int jour;
 int mois;
 int annee;
 int heure;
 int minute;
public:
	 date(int =0,int =0,int =0,int =0,int =0);
	 ~date(void);

	 void saisir_date();
     void saisir_heure();
     void afficher_date ();
	 void afficher_heure();
	 friend ostream& operator<<(ostream&, date&);
	 friend istream& operator >> (istream&, date&);
	
};

