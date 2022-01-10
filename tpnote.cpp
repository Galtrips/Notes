#include <iostream>
#include <ctime>
#include "../../TP6_notes.h"
using namespace std;

const int NBETU = 25;
const int NBNOTES = 5;
const int Taille = NBNOTES * NBETU;

void init_alea(float t[], int taille) {


	for (int i = 0; i < taille; i++) {
		float p = 100;
		float x = (rand() % 2001) /p ;
		t[i] = x;
	}
}

void affiche(int n,float t[], int taille) {
	while (n < taille) {
		cout << t[n] << endl;
		n = n + NBETU;
	}
}

void maxNote(int n, float t[], int taille) {

	float max = t[n];
	int inc = 1;
	int maxinc = 1;

	while (n < taille) {
		if (t[n] > max) {
			max = t[n];
			maxinc = inc;
		}
		n = n + NBETU;
		inc++;
	}
	cout << "La meilleur note est au DS" << maxinc << ", elle est de : " << max << endl;
}
float minNote(int n, float t[], int taille) {

	float min = t[n];
	int inc = 1;
	int mininc = 1;

	while (n < taille) {
		if (t[n] < min) {
			min = t[n];
			mininc = inc;
		}
		n = n + NBETU;
		inc++;
	}
	cout << "La note la plus basse est au DS" << mininc << ", elle est de : " << min << endl;
	return min;
}

float moyenne(int n, float t[], int taille) {
	float moyenne = 0; 
	float min = t[n];
	int inc = 1;
	int mininc = 1;
	int n2 = n;
	while (n < taille) {
		if (t[n] < min) {
			min = t[n];
			mininc = inc;
		}
		n = n + NBETU;
		inc++;
	}

	while (n2 < taille) {
		moyenne = moyenne + t[n2];
		n2 = n2 + NBETU;
	}
	moyenne = (moyenne - min) / (NBNOTES-1);
	cout << "La moyenne de l'etudiant est de : " << moyenne << endl;
	return moyenne;
}


void stats(int n, float t[], int taille) {
	int min=0;
	for (int i = 0; i < NBETU; i++) {

		t[i] = moyenne(i, Notes_bis, Taille);

	}

}


void afficheStats(float t[], int taille) {

	cout << endl;
	for (int i = 0; i < NBETU; i++) {
		cout << "-------------------" << endl;
		if (i > 8) {
			cout <<"| " << i + 1 << " | " << t[i] <<"/20" << endl;
		}
		else {
			cout << "| " << i+1 << "  | " << t[i]  << endl;
		}
	}
	cout << "-------------------" << endl;
}

float mDS(int n ,float t[], int taille) {
	float moyenne = 0;
	n = (n - 1) * NBETU;
	for (int i = 0; i < NBETU; i++) {

		moyenne = moyenne + t[n];
		n++;

	}
	float tot = NBETU;
	moyenne = moyenne / tot;
	return moyenne;
}

void afficheMDS(float t[], int taille) {

	for (int i = 0; i < NBNOTES; i++) {

		cout << "  DS" << i+1 << " ==> " << mDS(i + 1, Notes_bis, Taille)<<"/20" << endl;
		cout << endl;

	}
}





int main() {
	srand(time(NULL));
	int n = 1;
	float m1[NBETU];
	float m2[NBNOTES];

	while (n > -1) {

		cout << "Donnez un nouveau numero d'etudiant : ";
		cin >> n;
		if (n > 25 || n < 0) {
			while (n > 25 || n < 0) {
				cout << "Donnez un numero etudiant valide (1-25) : ";
				cin >> n;
			}
		}
		n--;

		if (n != -1) {

		
			int choix;
			cout << endl;
			cout << "Choisissez entre ces options : \n " << endl;
			cout << "1) Afficher les notes d'un etudiant" << endl;
			cout << "2) Afficher la note la plus haute de l etudiant ainsi que le DS" << endl;
			cout << "3) Afficher la note la plus basse de l etudiant, le numero du controle et la moyenne" << endl;
			cout << "4) Afficher la moyenne de tous les etudiants" << endl;
			cout << "5) Afficher la moyenne de tous les DS" << endl;
			cout << endl;
			cout << "Votre choix est : ";
			cin >> choix;
			
			switch (choix)
				{
			case 1:
				cout << endl;
				affiche(n, Notes_bis, Taille);
				break;
			case 2:
				cout << endl;
				maxNote(n, Notes_bis, Taille);
				break;
			case 3:
				cout << endl;
				minNote(n, Notes_bis, Taille);
				moyenne(n, Notes_bis, Taille);
				break;
			case 4:
				cout << endl;
				stats(n, m1, Taille);
				afficheStats(m1, Taille);
				break;
			case 5:
				cout << endl;
				afficheMDS(Notes_bis, Taille);
				break;
			default:
				cout << endl;
				cout << "Vous etes revenu en arriere..." << endl;
				break;
			}
			cout << endl;
		}
		else {
			cout << endl;
			cout << "Bonne journee !" << endl;
		}
	}
}