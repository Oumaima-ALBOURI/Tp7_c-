
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    // Constructeur 1 : nom uniquement
    Contact(string n) {
        nom = n;
        telephone = "Non disponible";
        email = "Non disponible";
    }

    // Constructeur 2 : nom et téléphone
    Contact(string n, string t) {
        nom = n;
        telephone = t;
        email = "Non disponible";
    }

    // Constructeur 3 : nom, téléphone et email
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    // Méthode d'affichage
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    Contact c1("Oumaima");
    Contact c2("Sara", "0612345678");
    Contact c3("Amine", "0623456789", "amine@gmail.com");

    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
