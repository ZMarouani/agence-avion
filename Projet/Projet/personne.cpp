#include "personne.h"


personne::personne(string nom, string prenom, long id, int age)
{
	this->nom = nom;
	this->prenom = prenom;
	this->id = id;
	this->age = age;
}

personne::~personne()
{}

ostream & operator<<(ostream &out, personne &p)
{
	cout << "surcharge de classe mere personne " << endl; 
	out << "nom : " << p.nom << endl,
	out << "prenom : " << p.prenom << endl; 
	out << "identifiant : "  << p.id << endl; 
	out << " age :" << p.age << endl; 

	return out; 
}

istream & operator >> (istream &in, personne &p)
{
	in >> p.nom ;
	in >> p.prenom;
	in >> p.id;
	in >> p.age;

	return in; 
}

bool personne::operator==(const personne& p)
{
	if (this->id == p.id)

		return true;
	else return false;
}

/*bool passager::egalité(passager* p)
{
if		(   nom == p->nom &&
prenom == p->prenom &&
age == p->age)
return true;
return false;
}  */

