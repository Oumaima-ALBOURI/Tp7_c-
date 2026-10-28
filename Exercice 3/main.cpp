
#include <iostream>
using namespace std;

class CompteBancaire {
private:
    double solde;
    int codeSecurite;

public:
    // Constructeur 1 : sans solde initial
    CompteBancaire() {
        solde = 0;
        codeSecurite = 1234;
    }

    // Constructeur 2 : avec un solde initial
    CompteBancaire(double s, int code = 1234) {
        if (s >= 0) {
            solde = s;
        } else {
            solde = 0;
        }

        codeSecurite = code;
    }

    // Afficher le solde
    void afficherSolde() {
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    // Retrait 1 : montant uniquement
    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Erreur : montant invalide !" << endl;
        } else if (montant > solde) {
            cout << "Erreur : solde insuffisant !" << endl;
        } else {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        }
    }

    // Retrait 2 : montant et code de securite
    void retrait(double montant, int code) {
        if (code != codeSecurite) {
            cout << "Erreur : code de securite incorrect !" << endl;
        } else if (montant <= 0) {
            cout << "Erreur : montant invalide !" << endl;
        } else if (montant > solde) {
            cout << "Erreur : solde insuffisant !" << endl;
        } else {
            solde -= montant;
            cout << "Retrait securise effectue avec succes." << endl;
        }
    }
};

int main() {
    // Compte sans solde initial
    CompteBancaire c1;

    // Compte avec solde initial de 1000 DH et code 2026
    CompteBancaire c2(1000, 2026);

    cout << "--- Compte 1 ---" << endl;
    c1.afficherSolde();
    c1.retrait(100);

    cout << "\n--- Compte 2 ---" << endl;
    c2.afficherSolde();

    c2.retrait(200);
    c2.afficherSolde();

    c2.retrait(100, 1234);
    c2.retrait(100, 2026);
    c2.afficherSolde();

    return 0;
}
