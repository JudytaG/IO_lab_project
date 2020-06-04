#pragma once
#include "Osoba.h"
#include "Wydarzenie.h"
#include "Karnet.h"
#include "GrTrening.h"
#include<vector>
class Klient :
	public Osoba
{
private:
	int nr_telefonu;
	string adres_email;
	vector<Wydarzenie*> lista_wydarzen;
	Karnet* karnet=NULL;

public:
	Klient(string Login, string Haslo, string Imie, string Nazwisko, Data Data_urodzenia, int Id, int nr_tel,string Adres_email) :
		Osoba(Login, Haslo, Imie, Nazwisko, Id, Data_urodzenia), nr_telefonu(nr_tel),adres_email(Adres_email) {};
	bool Dodaj_wydarzenie(Wydarzenie* wydarzenie);
	void Wyswietl_kalendarz();
	bool Dodaj_karnet(Karnet* nowy_karnet);
	void Sprawdz_status();
	void Wyswietl();
	bool Zapisz_do_GrTrening(GrTrening* grTrening);
};

