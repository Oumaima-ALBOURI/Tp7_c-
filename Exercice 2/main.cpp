
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Facture {
private:
    struct Article {
        string nom;
        double prix;
        int quantite;
        double tva;
    };

    vector<Article> articles;

public:
    // Version 1 : nom et prix unitaire
    void ajouterArticle(string nom, double prix) {
        articles.push_back({nom, prix, 1, 0});
    }

    // Version 2 : nom, prix unitaire et quantite
    void ajouterArticle(string nom, double prix, int quantite) {
        articles.push_back({nom, prix, quantite, 0});
    }

    // Version 3 : nom, prix, quantite et taux de TVA
    void ajouterArticle(string nom, double prix,
                        int quantite, double tva) {
        articles.push_back({nom, prix, quantite, tva});
    }

    // Afficher le total de la facture
    void afficherTotal() {
        double total = 0;

        cout << "----- FACTURE -----" << endl;

        for (const Article& a : articles) {
            double montantHT = a.prix * a.quantite;
            double montantTTC = montantHT * (1 + a.tva / 100);

            cout << "Article : " << a.nom << endl;
            cout << "Prix unitaire : " << a.prix << " DH" << endl;
            cout << "Quantite : " << a.quantite << endl;
            cout << "TVA : " << a.tva << "%" << endl;
            cout << "Montant TTC : " << montantTTC << " DH" << endl;
            cout << "-------------------" << endl;

            total += montantTTC;
        }

        cout << "Total de la facture : "
             << total << " DH" << endl;
    }
};

int main() {
    Facture f;

    f.ajouterArticle("Stylo", 5);
    f.ajouterArticle("Cahier", 20, 3);
    f.ajouterArticle("Ordinateur", 5000, 2, 20);

    f.afficherTotal();

    return 0;
}
