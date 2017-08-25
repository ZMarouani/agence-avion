#pragma once 

#include<iostream>

#include <string>

#include"compagnie.h"
#include"avion.h"





void main()
{
	float f;
	int c, y, x, z;
	string pass, ch, dep, arr;
	date date1(27, 04, 2017, 12, 53), date2(28, 04, 2017, 10, 22), date3(01, 01, 2018, 00, 00);
	compagnie s;
	avion a( 0 , 20 ,40 ,"tunis" ,"paris") , b(1, 20, 90, "tunis", "newYork") , d(2, 5, 10000, "tunis", "poleNord") ;
	passager p1("sabri","LasVegas",0,22 , 1598753), p2("3izdine ","karim", 000001,39 ,8546951 ), p3("antoine", "griezman", 000002,27 ,9645821 ), p4("layla", "benAli", 000003,54 ,6154827 ), p5("mohamed", "chiheb", 000004,7 ,6548528 ), p6("pablo", "escobar", 000005,50 ,5485464 ), p7("aymen", "chaker", 000006, 107, 4548924), p8("las3ed", "las3ed", 000007, 31, 8794658);
	agent a1("zied","marouani",785409 ,24 ,"pilote") , a2("jihen", "zitoun", 789409, 22, "pilote") ,  a3("amira ", "mahjoub", 785609, 27, "hotesse") , a4("sarra ", "mahjoub", 785609, 27, "hotesse") , a5("nour ", "mahjoub", 785609, 27, "hotesse") ;
	
	bool auth = false;

	a.setDate(date1);
	b.setDate(date2);
	d.setDate(date3); 

	a.ajouterPers(a1);
	a.ajouterPers(a2);
	a.ajouterPers(a3);
	a.ajouterPers(a4);
	a.ajouterPers(a5);
	a.ajouterPers(p1);
	a.ajouterPers(p2);
	a.ajouterPers(p3);
	a.ajouterPers(p4);
	a.ajouterPers(p5);
	a.ajouterPers(p6);
	a.ajouterPers(p7);
	a.ajouterPers(p8);

	b.ajouterPers(a1);
	b.ajouterPers(a2);
	b.ajouterPers(a3);
	b.ajouterPers(a4);
	b.ajouterPers(a5);
	b.ajouterPers(p1);
	b.ajouterPers(p2);
	b.ajouterPers(p3);
	b.ajouterPers(p4);
	
	
	d.ajouterPers(a1);
	d.ajouterPers(a2);
	d.ajouterPers(a3);
	d.ajouterPers(a4);
	d.ajouterPers(a5);

	s.ajouterVol(&a);
	s.ajouterVol(&b);
	s.ajouterVol(&d); 

	cout << typeid(a1).name() <<"    "<< a1 << endl; 
	cout << " --------------------------" << endl;

	cout << typeid(*s.vavion[1]->vpersonne[1] ).name() << "     "<<*s.vavion[1]->vpersonne[1] << endl;
	cout << " --------------------------" << endl; 
	cout << typeid(s.vavion[1]->vpersonne[1]).name() << endl; 
	/*	s.ajouterVol(c); */

	cout << " si vous etes un agent choisissez 1 , sinon si vous etes un client choisissez 2  " << endl;
	cin >> x;
	switch (x) 
	{
	case 1:
	{
		cout << " password " << endl;
		cin >> pass;
		
		if (pass == "admin")
		{
			cout << "welcom ADMIN " << endl;
			auth = true;

		}
		else { cout << " wrong password "; }

		break;
	}
	case 2:

		cout << "  ** WELCOME TO THE TRAVEL PLATFORME **  " << endl;
		break;
	}


/*----------------------------------------------------------------------------------------------------------------------------------------*/


	cout << "1:rechercher un trajet" << endl;
	cout << "2:consulter la liste des voyages disponibles" << endl;
	
	cin >> z;

	  switch (z)
	  {
	  case 1: {

		cout << "saisissez la ville de depart :" << endl;
		cin >> dep;

		cout << "saisissez la destination :" << endl;
		cin >> arr;

		s.chercherVol(dep, arr);

		break;
	         }

 /* ----------------------------------------------------------------------------------------------------------------------------------*/
	case 2:
	{

		s.affichListe();

		if (s.vavion.size() > 0)
		{
			cout << "\n saisir le numero d'avion que vous etes interesse a consulter" << endl;
			cin >> c;
		}

		cout << " \n saisir 0 : consulter la liste des passagers de l'avion " << endl;
		cout << " \n saisir 1 : consulter le prix  " << endl;
		cout << " \n saisir 2 : consulter la date du voyage  " << endl;
		cout << " \n saisir 3 : consulter la reference d'avion  " << endl;
		cout << " \n saisir 4 : voir le trajet  " << endl;
		cout << " \n saisir 5 : voir nombre de places vides  " << endl;
		cout << " \n saisir 6 : annuler une reservation  " << endl;

		if (auth == true)
		{
			cout << " \n saisir 7 : changer les parametres d'avion choisie " << endl;
			cout << " \n saisir 8 : modifier la liste des avions " << endl;
		}
		

	
	cin >> y;

	switch (y) 
	{
	case 0: 
		s.vavion[c]->affichVpersonne();
	break;
	
	case 1: cout << s.vavion[c]->getPrix() << endl;
		break;
	case 2: cout << s.vavion[c]->getDate() << endl;
		break;
	case 3:  cout << s.vavion[c]->getNum() << endl;
		break;
	case 4: cout << "\n ville de depart est " << s.vavion[c]->getDepart() << "\n ville d'arrivee est " << s.vavion[c]->getArrivee() << endl;
		break;
	case 5: cout << s.vavion[c]->places_vides() << endl;
		break;
	case 6: s.vavion[c]->annuler_reservation();
		break;

	case 7:
		if (auth == true) 
		{
			cout << " \n saisir le nouveau prix , depart et arrivee " << endl;
			cin >> f;
			cin >> dep;
			cin >> arr;

			s.vavion[c]->setPrix(f);
			s.vavion[c]->setDepart(dep);
			s.vavion[c]->setArrivée(arr);
			break;
		}

		else cout << " \ vous n'avez pas l'autorisation " << endl;

	case 8: if (auth == true) 
	   {
		s.modifierVol();
		break;
	   }
    
	} //switch y 
	
	break;
   } //switch x=2

  }
			
	
	system("PAUSE");
}