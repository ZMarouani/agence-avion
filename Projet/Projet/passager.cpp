#include "passager.h"

passager::passager(string nom,string prenom,long cin , int age , long numP):personne(nom , prenom , cin ,age)
{
	numPasseport=numP ;
}


passager::~passager(void)
{
}

void passager::afficher(void)
{ 
	cout <<"les donnees du client:" << endl;
	cout << this; 
	
}



istream& operator >> (istream& in, passager& pass)
{
	personne* p = &pass; 
	in >> *p ;
	in >> pass.numPasseport;
	return in;
}


ostream& operator << (ostream& out, passager& pass)
{
	cout << "surcharge de agent fonctionne" << endl;

	personne *p = &pass;
	out << *p << endl; 
	out << " numero du passeport   " << pass.numPasseport << endl;

	return out;
}




