
#include"personne.h"

using namespace std;


class passager : public personne
{
public:
	long numPasseport ;

public:
	passager(string=" " , string=" " , long =0 , int =22 , long =0 );
	virtual ~passager(void);
	void afficher(void); 

	friend istream& operator >> (istream&, passager&);
	friend ostream& operator<<(ostream&, passager&);

	
	
};

