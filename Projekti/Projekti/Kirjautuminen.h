#pragma once
struct kayttaja {// luodaan käyttäjä tietue
	char salasana[20], nimi[20];
}; 

// käyttäjän kanssa kohtaavat funktiot
int Valikko(); // valikon funktio
void Aloitus(); // aloituksen funktio

int HyvaksyttySyotto(int); // tarkistetaan käyttäjän syöttöä

// funktiot mitkä eivät koske käyttäjää mitenkään.
void LuoKayttaja(); // käyttäjän luominen
void Kirjautuminen(); // käyttäjänä kirjautuminen sisään

