# pragma once 

#include "date.h"
#include"passager.h"
#include"agent.h"
#include"personne.h"

#include <fstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std; 

class avion
{
	int numero; //numero d'avion
int capacite; //nbre de places maximales
float prix; //prix d'avion dans un trajet choisie
string ville_depart;
string ville_arrivee;
date dtrajet; //objet date
public:
vector<personne*> vpersonne;// vector contenant les passagers sur cet avion

							
							//vector<agent*> vAgent; 
							// vector contenant les agents qui travaillent  sur cette avion


public:
	avion(int=0,int=0,float=0.0,string="",string="");
	//constructeur de recopie 
	avion(const avion&);
	~avion(void);

	int getNum() { return numero;};
int getCapacite(){return capacite;};
float getPrix() { return prix; };
date getDate() { return dtrajet; };
string getDepart() { return ville_depart; }
string getArrivee() { return ville_arrivee; }

void setPrix(float);
void setDepart(string);
void setArrivée(string);
void setDate(date); 


void reservation();
void annuler_reservation();
int places_vides() { return  ( capacite -(this->vpersonne.size())); }

void remplir(); 
void affichVpersonne(); 
// meme que reservation ??

void ajouterPers(personne*);
void ajouterPers(passager);
void ajouterPers( agent );

void supprimer(int = 0); 

/*
void supprimerPers(passager);
void modifierPers(passager);
void chercherPers(passager);


void supprimerPers(agent);
void modifierPers(agent);
void chercherPers(agent);
*/




friend istream& operator >> (istream&, avion&);
friend ostream& operator << (ostream&, avion&);

friend istream& operator >> (istream&, avion*);
friend ostream& operator << (ostream&, avion*);







};


	
