#include "date.h"
date::date(int jour , int mois, int annee , int heure , int minute)
{ 
	
	this->jour=jour;
	this->mois=mois;
	this->annee=annee;
	this->heure=heure;
	this->minute=minute;

}

void date :: saisir_date()
{
	
	cout << "\n saisir le jour " << endl;
    cin>>jour;
	cout<<"\n saisir le mois"<<endl;
	cin>>mois;
	
	cout<<"\n saisir l'annee "<<endl;
	cin>>annee;}

void date ::saisir_heure()
{
	cout <<" \n l'heure et la minute"<<endl;
    cin >>heure>>minute;
}

void date ::afficher_date()
{
cout <<"la date est "<<endl;
cout <<jour<<"/"<<mois<<"/"<<annee<<endl;

}


void date ::afficher_heure()
{
	cout<<"\n l'heure est "<<heure <<endl;
	cout<<"\n la minute est " <<minute<<endl;

}
 



date::~date(void)
{
}

istream& operator >> (istream& in, date& dt)
{
	in >> dt.jour;
	in >> dt.mois;
	in >> dt.annee;
	in >> dt.heure;
	in >> dt.minute;
	return in;
}
ostream& operator<<(ostream& out, date &dt)
{
	out << dt.jour << "/" << dt.mois << "/" << dt.annee << endl;
	return out;
}