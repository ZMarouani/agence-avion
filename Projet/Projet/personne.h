#pragma once

#include <string>
#include<fstream>
#include<iostream>
#include<vector>

using namespace std; 

class personne
{
public:
	string nom;
	string prenom ;
	long id ;
	int age ;

public:
	personne(string="",string="",long=0,int=0);
	virtual void afficher() = 0;
	friend ostream& operator << (ostream&, personne&); 
	friend istream& operator >> (istream&, personne&); 
	bool operator == (const personne&); 

	virtual ~personne();
	
};

