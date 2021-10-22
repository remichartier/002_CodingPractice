#include <iostream>

using namespace std;

class Personnage {
	public:
		// ...
		virtual string get_nom()  =0;

		virtual void rencontrer(Personnage& p) { 
			cout << "Bonjour !" << endl;
		}
};

class Guerrier : public Personnage {
	public:
		// ...
		string get_nom() {
			return "guerrier";
		}

		virtual void rencontrer(Personnage& p) {
			cout << "Boum !" << endl;
		}
};

class Voleur : public Personnage{

		string get_nom() {
			return "voleur";
		}

		virtual void rencontrer(Personnage& p) {
			cout << "Le voleur est tué !" << endl;
		}
};

void faire_rencontrer(Personnage& un, Personnage& autre) {
//void faire_rencontrer(Personnage const& un, Personnage const& autre) {
	
	cout << un.get_nom() << " rencontre " << autre.get_nom() << " : ";
	un.rencontrer(autre);
}

int main() {
	Guerrier g;
	Voleur v;
	
	faire_rencontrer(g, v);
	faire_rencontrer(v, g);

}

// g++ -o main.exe dynamicLinkResolution_v00.cpp