#pragma once
#include<string>
#include "Pomocnicze.h"
#include <iostream>
using namespace std;
class Osoba
{
private:
	string login;
	string haslo;
	string imie;
	string nazwisko;
	int id;
	Data data_urodzenia;
public:
	Osoba(string Login, string Haslo, string Imie, string Nazwisko, Data Data_urodzenia) :login(Login), haslo(Haslo), imie(Imie), nazwisko(Nazwisko), id(Id), data_urodzenia(Data_urodzenia) {};
	bool zmien_haslo(string nowe_haslo);
	bool edytuj_dane(string Imie, string Nazwisko, Data Data_urodzenia);
	void Wyswietl();
};

