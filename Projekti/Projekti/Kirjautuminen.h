#pragma once
struct kayttaja {// luodaan k�ytt�j� tietue
	char salasana[20], nimi[20];
}; 

// k�ytt�j�n kanssa kohtaavat funktiot
int Valikko(); // valikon funktio
void Aloitus(); // aloituksen funktio

// funktiot mitk� eiv�t koske k�ytt�j�� mitenk��n.
void LuoKayttaja(); // k�ytt�j�n luominen
void Kirjautuminen(); // k�ytt�j�n� kirjautuminen sis��n
int HyvaksyttySyotto(int); // tarkistetaan k�ytt�j�n sy�tt��
int HashattySyotto(char*); // Salasana muutetaan hasheiksi
bool NimenTarkastus(char*); // duplikaattien tarkastus tiedostosta
