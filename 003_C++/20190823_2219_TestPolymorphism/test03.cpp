#include <iostream>
using namespace std;
#include <string>



class Mammifere {
	public:
		Mammifere(){cout << "Un nouveau mammifère est né !" << endl ;}
		virtual ~Mammifere(){cout << "Un mammifère est en train de mourir :-(" << endl ;}
		void manger(){cout << "Miam... croumf !" << endl ;}
		virtual void avancer(){cout << "Un grand pas pour l'humanité." << endl ;}	
};

class Dauphin : public Mammifere {
	public:
		Dauphin(){cout << "Couic, Couic !" << endl ;}
		~Dauphin(){cout << "Flipper, c'est fini ..." << endl ;}
		void manger(){cout << "Sglups, un poisson" << endl ;}
		void avancer(){cout << "Je nage" << endl ;}	
};

int main() {
	Mammifere* lui(new Dauphin());
	lui->avancer();
	lui->manger();
	delete lui;
	return 0;
}

/* result : 
My pronostic : 

	Mammifere* lui(new Dauphin())	"Un nouveau mammifère est né !" "Couic, Couic !"
	lui->avancer();					"Je nage"
	lui->manger();					"Sglups, un poisson"
	delete lui;						"Flipper, c'est fini ..."  "Un mammifère est en train de mourir :-("
	return 0;


In reality : 

$ g++ test03.cpp -o test03
$ ./test03
Un nouveau mammifère est né !
Couic, Couic !
Je nage
Miam... croumf !
Flipper, c'est fini ...
Un mammifère est en train de mourir :-(

*/


