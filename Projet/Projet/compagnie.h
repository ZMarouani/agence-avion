#pragma once 

#include<vector>
#include"avion.h"
#include<string>
#include <fstream>
#include<iostream>


using namespace std;


class compagnie
{
public:
	string nom;
	vector<avion*> vavion ;
	
public:
	compagnie() { nom = "tunisAir "; }

	compagnie(const compagnie&);
	
	string get_nom() { return nom; }
	
	void ajouterVol(avion*); 
	void modifierVol();
	void supprimerVol(); 
	void chercherVol(string, string);

	
	void affichListe(); 
	~compagnie();

	friend istream& operator >> (istream&, compagnie&);
	friend ostream& operator<<(ostream&, compagnie&);

	
	
	
};


