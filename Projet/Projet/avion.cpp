#include "avion.h"

#include<string>

#include<typeinfo>


using namespace std; 


 avion::avion( int numero , int capacite, float prix ,string ville_depart,string ville_arrivee )
{
	 this->numero=numero; 
	 this->capacite=capacite; 
	 this->prix=prix; 
	 this->ville_depart =ville_depart;
	 this->ville_arrivee = ville_arrivee;
	 
	

}


 avion::avion(const avion &w)
 {
	 numero = w.numero;
	 capacite = w.capacite;
	 prix = w.prix;
	 ville_depart = w.ville_depart;
	 ville_arrivee = w.ville_arrivee;


	 // dans le cas d'un seul vector qui contients les deux types
	 personne* p;
	 for (int i = 0; i < w.vpersonne.size(); i++)
	 {

		 if (typeid(*w.vpersonne[i]) == typeid(passager))
		 {

			 p = new passager(static_cast<const passager&> (*w.vpersonne[i]));
		 }
		 else if (typeid(w.vpersonne[i]) == typeid(agent))
			 p = new agent(static_cast<const agent&> (*w.vpersonne[i]));

		 vpersonne.push_back(p);

		 /* personne *p;
			  for (int i = 0; i < w.vpersonne.size(); i++)
			  {

				  if (typeid(*w.vpersonne[i]) == typeid(passager))
				  {

					  p=new passager(static_cast<const passager&> (*w.vpersonne[i]));
				  }
				  else if (typeid(w.vpersonne[i]) == typeid(agent))
					  p= new agent(static_cast<const passager&> (*w.vpersonne[i]));

				  vpersonne.push_back(p);*/

	 }
 

 }

 
avion::~avion(void)
{ 
	for (int i = 0; i < vpersonne.size(); i++)
		delete vpersonne[i]; 
	vpersonne.clear(); 
}


void avion::reservation()
{
	personne* p; 
	passager* pass; 
	agent* ag; 
	int a;


	if (vpersonne.size()< capacite) { 
		cout << " reserver pour :" << endl; 
		cout << " 1: client" << endl; 
		cout << "2: agent" << endl; 

		cin>> a; 
		switch (a) 
		{case 1: {
			
			cout << "  saisir le nouveau passager " << endl;
		cin >> *pass ;  }
		case 2: {
		
			cout << "  saisir les données de l'agent " << endl;
			cin >> *ag ; }
				break;

		}


		
		vpersonne.push_back(p); 
			
	}
	else { cout << "  there is no more available places " << endl; }


}


void avion::annuler_reservation()
{ 
	long x; 
	int y; 
	cout << " \n saisir le cin du passager qui va annuler la reservation " << endl; 
	cin >> x; 
	for (int i = 0; i < vpersonne.size(); i++)
	{
		if ((vpersonne[i]->id) == x)
		{
			cout << "confirmer l'annulation" << endl;
			cout << " 1: oui" << endl;
			cout << "2 : annuller" << endl;
			cin >> y;
			switch (y) {
			case 1:
			{
				this->vpersonne.erase(vpersonne.begin() + i);

				cout << " \n la reservation a été annullée " << endl;
			}
			case 2: { break; }
					break;
			}
		}
		else cout << " \n ce client n'existe pas " << endl; 
	}
	
}

void avion::remplir()
{
	char rep;
	personne* q;
	int choix;
	do
	{
		cout << "\n taper1: client, 2:agent" << endl;
		cin >> choix;
		if (choix == 1) q = new passager();
		else if (choix == 2) q = new agent();
		else break;
		cin >> *q;
		vpersonne.push_back(q);
		cout << "\n rajouter ? saisir oui " << endl;
		cin >> rep;
	} while (rep == 'oui');
}

void avion::affichVpersonne()
{
	for (int i = 0; i < vpersonne.size(); i++)
	{
		cout << typeid(*vpersonne[i] ).name()  << endl; 
		
		cout << *vpersonne[i] << endl;		
		cout << "--------------------------" << endl;
		
	}
}

void avion::ajouterPers(personne* p)
{
	vpersonne.push_back(p); 
}

void avion::ajouterPers(passager pass )
{
	personne* p = new passager(pass); 
	vpersonne.push_back(p); 

}

void avion::ajouterPers(agent a)
{
	personne* p = new agent(a);
	vpersonne.push_back(p);
}

void avion::supprimer(int ind)
{
	delete vpersonne[ind]; 
	vpersonne.erase(vpersonne.begin() + ind); 
}






/* void avion::annuler_reservation(int pos)
vpersonne[pos]=vpersonne[vpersonne.size()-1];
vpersonne.pop_back();

*/





void avion::setPrix(float p)
{
	prix = p; 
}

void avion::setDepart(string depart)
{
	ville_depart = depart; 
}

void avion::setArrivée(string arrivee)
{  
	ville_arrivee = arrivee; 
}

void avion::setDate(date d )
{
	this->dtrajet = d; 
}


/*
void avion::ajouterPers(personne* p)
{
	vpersonne.push_back(p)

}



void avion::ajouterPers(passager* p)
{
	vpersonne.push_back(p)
}

void avion::supprimerPers(passager)
{
}

void avion::modifierPers(passager)
{
}

void avion::ajouterPers(passager* p)
{
	vpersonne.push_back(p)
}

void avion::supprimerPers(passager)
{
}

void avion::modifierPers(passager)
{
}


*/


istream& operator >> (istream& f, avion& a)
{  
	cout << " \n saisir le numero du avion " << endl; 
	f >> a.numero; 
	cout << " \n saisir la capacité du avion  " << endl; 
	f >> a.capacite; 
	cout << " \n saisir le prix " << endl;
	f >> a.prix; 
	cout << " \n saisir la date du sortie" << endl; 
	f >> a.dtrajet; 
	cout << " \n saisir la ville de depart " << endl;
	f >> a.ville_depart;
	cout << " \n saisir la ville d'arrivée " << endl;
	f >> a.ville_arrivee;

	return f; 
	
}
ostream& operator << (ostream& f , avion& a)
{  
	
	f << "  le numero du vol " << a.numero << endl;

	f << "  la capacite de l'avion  " << a.capacite << endl;

	f << "  le prix " << a.prix << endl;

	f << "le trajet : " << a.ville_depart << "-" << a.ville_arrivee << endl;

	f << "  la date du vol" << a.dtrajet << endl;

	return f;
}

istream & operator >> (istream &f, avion *a)
{
	cout << " \n saisir le numero du avion " << endl;
	f >> a->numero;
	cout << " \n saisir la capacite du avion  " << endl;
	f >> a->capacite;
	cout << " \n saisir le prix " << endl;
	f >> a->prix;
	cout << " \n saisir la date du sortie" << endl;
	f >> a->dtrajet;
	cout << " \n saisir la ville de depart " << endl;
	f >> a->ville_depart;
	cout << " \n saisir la ville d'arrivée " << endl;
	f >> a->ville_arrivee;

	return f; 
}

ostream & operator<<(ostream &f, avion *a)
{
	f << " le numero du vol : " << a->numero << endl;

	f << " la capacite de l'avion :  " << a->capacite << endl;

	f << " le prix : " << a->prix << endl;
	
	f << "le trajet : " << a->ville_depart  << "-" << a->ville_arrivee << endl; 

	f << "  la date du sortie :" << a->dtrajet << endl;

	return f;
}





  