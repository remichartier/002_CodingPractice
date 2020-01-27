#include <iostream>
using namespace std;
#include <string>



class jeu {
	public:
		void afficher() const ;
		void ajouter_personnage(Personnage*) ;
	private :
		vector<unique_ptr<Personnage>> personnages ;
}

void Jeu::ajouter_personnage(Personnage* nouveau) {
	if (nouveau != nullptr) {
		personnages.push_back(unique_ptr<Personnage>(nouveau));
	}
}

void Jeu::afficher() const {
	for (auto quidam : personnages) {
		quidam->afficher();
	}
}

/* another version :
void Jeu::afficher() const {
	for (auto const& quidam : personnages) {
		quidam->afficher();
	}
}
*/


int main() {
Jeu jeu;
jeu.ajouter_personnage(new Guerrier(...));
jeu.ajouter_personnage(new Magicien(...));
jeu.ajouter_personnage(new Voleur(...));
jeu.ajouter_personnage(new Guerrier(...));
// ...
jeu.afficher();

}

/* result : 
$ g++ test04.cpp -o test04
$ ./test04

*/


