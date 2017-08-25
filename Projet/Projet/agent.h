#include<iostream>
#include<string>
#include <fstream>

#include"personne.h"

using namespace std;


class agent : public personne
{ public:

	string metier;

public:
	agent(string = " ", string = " ", long =0 ,int = 22 , string=" ");
	~agent(void);
	void afficher(); 
	
	friend istream& operator >> (istream&, agent&);
	friend ostream& operator << (ostream&, agent&); 

	

};

