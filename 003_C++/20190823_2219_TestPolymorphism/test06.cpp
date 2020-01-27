#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <memory>


class Produit {
	public:
		Produit(double une_valeur = 0.0) : valeur(une_valeur) {}
		virtual ~Produit() = 0 ;
		virtual double prix() const { return valeur; }
		virtual void afficher(ostream& sortie) const ;
	private :
		const double valeur;
};

Produit::~Produit() {}

void Produit::afficher(ostream& sortie) const {
	sortie << prix();
}

// On y revient plus tard
ostream& operator<<(ostream& sortie,Produit const& machin) {
	machin.afficher(sortie);
	return sortie;
}

class Accessoire : public Produit {
	public:
		Accessoire(string const& un_nom,double prix_de_base): Produit(prix_de_base), nom(un_nom){}
		virtual ~Accessoire() {}
		virtual void afficher(ostream& sortie) const override {
			sortie << nom << " coûtant ";
			Produit::afficher(sortie);
		}
	private :
		const string nom;
};

class Bracelet : public Accessoire {
public:
	Bracelet(string const& un_nom, double prix_de_base) : Accessoire("bracelet " + un_nom, prix_de_base){}
	virtual ~Bracelet() {}
};

//------------------------------------------------------------
class Fermoir : public Accessoire {
	public:
		Fermoir(string const& un_nom, double prix_de_base): Accessoire("fermoir " + un_nom, prix_de_base){}
		virtual ~Fermoir() {}
};
//------------------------------------------------------------
class Boitier : public Accessoire {
	public:
		Boitier(string const& un_nom, double prix_de_base): Accessoire("boitier " + un_nom, prix_de_base){}
		virtual ~Boitier() {}
};
//------------------------------------------------------------
class Vitre : public Accessoire {
	public:
		Vitre(string const& un_nom, double prix_de_base): Accessoire("Vitre " + un_nom, prix_de_base){}
		virtual ~Vitre() {}
};

class Mecanisme : public Produit {
	public:
		Mecanisme(double valeur_de_base, string une_heure = "12:00"): Produit(valeur_de_base), heure(une_heure) {}
		//...
		// Tous les mécanismes DOIVENT s'afficher comme ceci
		virtual void afficher(ostream& sortie) const override final {
			sortie << "mécanisme "; afficher_type(sortie);
			sortie << " (affichage : " ; afficher_cadran(sortie);
			sortie << "), prix : " ; Produit::afficher(sortie);
		}
		virtual ~Mecanisme() {}
	protected :
		// On veut offrir la version par défaut aux sous-classes
		// Par défaut, on affiche juste l'heure.
		virtual void afficher_cadran(ostream& sortie) const {
			sortie << heure;
		}
	private :
		string heure;
		virtual void afficher_type(ostream& sortie) const = 0;
	
};

class MecanismeAnalogique : virtual public Mecanisme {
	public:
		MecanismeAnalogique(double valeur_de_base, string une_heure, int une_date) : Mecanisme(valeur_de_base, une_heure), date(une_date){}
		MecanismeAnalogique(double valeur_de_base, int une_date) : Mecanisme(valeur_de_base), date(une_date){}
		virtual ~MecanismeAnalogique() {}
	protected:
		virtual void afficher_type(ostream& sortie) const override {
			sortie << "analogique";
		}
		virtual void afficher_cadran(ostream& sortie) const override {
			// On affiche l'heure (façon de base)...
			Mecanisme::afficher_cadran(sortie);
			// ...et en plus la date.
			sortie << ", date " << date;
		}
	private :
		int date;
};
class MecanismeDigital : virtual public Mecanisme {
	public:
		MecanismeDigital(double valeur_de_base, string une_heure, string un_reveil) : Mecanisme(valeur_de_base, une_heure), reveil(un_reveil){}
		MecanismeDigital(double valeur_de_base, string un_reveil) : Mecanisme(valeur_de_base), reveil(un_reveil){}
		virtual ~MecanismeDigital() {}
	private :
		string reveil;
	protected:
		virtual void afficher_type(ostream& sortie) const override {
			sortie << "digital";
		}
		virtual void afficher_cadran(ostream& sortie) const override {
			// On affiche l'heure (façon de base)...
			Mecanisme::afficher_cadran(sortie);
			// ...et en plus la date.
			sortie << ", reveil " << reveil;
		}
};
class MecanismeDouble : public MecanismeAnalogique, public MecanismeDigital {
	public:
		MecanismeDouble(double valeur_de_base, string une_heure, int une_date, string heure_reveil) : 
			Mecanisme(valeur_de_base, une_heure), 
			MecanismeAnalogique(valeur_de_base, une_heure, une_date), 
			MecanismeDigital(valeur_de_base, une_heure,heure_reveil) 
			{}
		MecanismeDouble(double valeur_de_base, int une_date, string heure_reveil) : 
			Mecanisme(valeur_de_base), 
			MecanismeAnalogique(valeur_de_base, une_date), 
			MecanismeDigital(valeur_de_base, heure_reveil) {}
		virtual ~MecanismeDouble() {}

	private :
	protected:
		virtual void afficher_type(ostream& sortie) const override {
			sortie << "double";
		}
		virtual void afficher_cadran(ostream& sortie) const override {
			// On affiche l'heure (façon de base)...
			sortie << " sur les aiguilles : " ;
			MecanismeAnalogique::afficher_cadran(sortie);
			// ...et en plus la date.
			sortie << " sur l'écran " ;
			MecanismeDigital::afficher_cadran(sortie);
		}
};


class Montre : public Produit {
	public:
		Montre() = default;
		Montre(Mecanisme* depart) : coeur(unique_ptr<Mecanisme>(depart)) {}

		virtual ~Montre() {}
		void operator+=(Accessoire* p_accessoire){
			accessoires.push_back(unique_ptr<Accessoire>(p_accessoire));
		}

		virtual double prix() const override {
			// Au départ, le prix est la valeur de base
			double prix_final(Produit::prix());

			for (auto const& p_acc : accessoires) {
				prix_final += p_acc->prix();
			}
			return prix_final;
		}

		virtual void afficher(ostream& sortie) const override {
			sortie << "Une montre composée de :"<< endl;
			for (auto const& p_acc : accessoires) {
				sortie << " * " << *p_acc << endl;
			}
			sortie << "==> Prix total : " << prix() << endl;
		}



	private :
		unique_ptr<Mecanisme> coeur;
		vector<unique_ptr<Accessoire>> accessoires;
		Montre(const Montre&) = delete;
		Montre& operator=(Montre) = delete;
};


int main() {

	MecanismeAnalogique v1(312.00, 20141212);
	MecanismeDigital v2( 32.00, "11:45", "7:00");
	MecanismeDouble v3(543.00, "8:20", 20140328, "6:30");
	cout << v1 << endl << v2 << endl << v3 << endl;
	
	// Test des montres
	Montre m(new MecanismeDouble(468.00, "9:15", 20140401, "7:00"));
	
	 m += new Bracelet("cuir", 54.0);
	 m += new Fermoir("acier", 12.5);
	 m += new Boitier("boitier", 36.60);
	 m += new Vitre("quartz", 44.80);

	cout << "Montre m :" << endl;
	cout << m << endl;


	return 0;
}

/* result : 
$ g++ test06.cpp -o test06
$ ./test06

mécanisme analogique (affichage : 12:00, date 20141212), prix : 312
mécanisme digital (affichage : 11:45, reveil 7:00), prix : 32
mécanisme double (affichage :  sur les aiguilles : 8:20, date 20140328 sur l'écran 8:20, reveil 6:30), prix : 543
Montre m :
Une montre composée de :
 * bracelet cuir coûtant 54
 * fermoir acier coûtant 12.5
 * boitier boitier coûtant 36.6
 * Vitre quartz coûtant 44.8
==> Prix total : 147.9



*/


