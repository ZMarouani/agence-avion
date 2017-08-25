#include "agent.h"


agent::agent(string a, string b ,long cin ,int c , string m):personne(a,b,cin,c)
{
	
	metier = m ;
}


agent::~agent(void)
{
}

void agent::afficher()
{
	cout << this; 
}



istream& operator >> (istream& in, agent& a)
{
	personne *p = &a; 
	in >> *p; 
	in >> a.metier; 

	return in;
}


ostream& operator << (ostream& out, agent& a)
{
	cout << "surcharge de agent fonctionne" << endl;
	personne *p = &a;
	out << *p;
	 
	out << a.metier; 



	return out;
}


