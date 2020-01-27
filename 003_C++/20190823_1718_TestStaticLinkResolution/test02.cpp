#include <iostream>
using namespace std;
#include <string>



class Personnage {
	public:
		Personnage(string nm):name(nm){};
		virtual void rencontrer(Personnage& p) const { cout << "Bonjour !" << endl; }
		string get_nom() const {return(name);}
	private :
		string name ;
};

class Guerrier : public Personnage {
	public:
		Guerrier(string nm):Personnage(nm){};
		void rencontrer(Personnage& p) const { cout << "Boum !" << endl; }
};


class Voleur : public Personnage {
	public:
		Voleur(string nm):Personnage(nm){};
};


void faire_rencontrer(Personnage const& un, Personnage autre) {
	cout << un.get_nom() << " rencontre " << autre.get_nom() << " : " ;
	un.rencontrer(autre);
}

int main() {
	Guerrier g("guerrier") ;
	Voleur v("voleur") ;
	
	faire_rencontrer(g, v);
	//p.rencontrer(p) ;
}

/* result : 
./test02 
guerrier rencontre voleur : Boum !
*/


