#include "compagnie.h"
#include <string>
#include <iostream>
#include "avion.h"
#include<fstream>

using namespace std; 



/* compagnie::compagnie() {}  */

compagnie::~compagnie()
{
	for (int i = 0; i < vavion.size(); i++)
		delete vavion[i];
	vavion.clear();
}

compagnie::compagnie(const compagnie& w)
{
	nom = w.nom; 

	for (int i=0; i < w.vavion.size() ; i++)
	{
		avion* q = new avion(*w.vavion[i]);
		vavion.push_back(q); 
	}
}

void compagnie::ajouterVol(avion* a )
{
	vavion.push_back(a); 
}

void compagnie::modifierVol()
{
	int j , x;
	avion* a ;
	
	this->affichListe(); 

	cout << " \n saisir 1: supprimer un avion" << endl;
	cout << " \n saisir 2: supprimer toute la liste " << endl;
	cout << " \n saisir 3: ajouter un avion  " << endl;
	cin >> x;
	switch (x)
	{
	case 1: cout << "  saisir le numero de l'avion a supprimer " << endl;
		cin >> j;
		this->vavion.erase(vavion.begin() + j);
		break;

	case 2: this->vavion.clear();  break;

	case 3: cout << " saisir l'avion a ajouter  " << endl;

		cin >> a  ;
		cout << "  saisir la position de l'avion " << endl;
		cin >> j;
		
		this->vavion.insert(vavion.begin() + j, a ); 
		
		break;
	}
}

void compagnie::supprimerVol()
{
}

void compagnie::chercherVol(string a , string b )
{
	bool trouve = false; 

	for (int i = 0; i < vavion.size(); i++)
	{
		if (vavion[i]->getDepart() == a && vavion[i]->getArrivee() == b)
			cout << i << ") " <<" ceci est l'avion du vol cherchee "<< vavion[i] << endl; 
		trouve = true; 
	}
	
	if (trouve == false) { cout << " ce trajet n'existe pas" << endl;  }
}

void compagnie::affichListe()
{  
	for (int i=0 ; i< this->vavion.size(); i++)
	
		cout << " \n " << i << ")" << vavion[i] << endl;
	

}






istream& operator >> (istream& in, compagnie& sc)
	{
		in >> sc.nom;
		
		return in;
	}





ostream & operator<<(ostream & out, compagnie & sc)
{
	out << sc.nom;

	for (int i = 0; i < sc.vavion.size(); i++)
	{
		out << sc.vavion[i];
	}

	return out;

}




