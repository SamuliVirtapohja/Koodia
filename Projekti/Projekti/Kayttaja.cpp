#include <iostream>
#include "Kirjautuminen.h"

using namespace std;

int Valikko(){ // Käyttäjältä kysytään mitä tehdään.
	int vastaus;
	cout << "Valikko: " << endl << "1.Tee käyttäjä" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	vastaus = HyvaksyttySyotto(vastaus); // tarkistetaan käyttäjän syöttö
	return vastaus; // Käyttäjän syöttö palautetaan
}

void Aloitus() {// Käyttäjän syötön perusteella:
	int kayttajansyotto;
	int* osoitinsyotto; // osoittimen muuttuja

	osoitinsyotto = &kayttajansyotto; // kutsutaan osoittimen kautta käyttäjänsyöttöä

	do // do/while looppi kirjautumismenuun ja käyttäjän luomiseen
	{
		kayttajansyotto = Valikko(); // palautetaan käyttäjänsyöttö
		switch (*osoitinsyotto) {// käyttäjän syötön perusteella
		case 1: {
			LuoKayttaja(); // luodaan käyttäjä
			break;
		}
		case 2: {
			Kirjautuminen();//kirjaudu	
			break;
		}
		}
	} while (*osoitinsyotto != 0);
}




