#pragma once
#include "Osoba.h"
#include "Klient.h"
#include "GrTrening.h"
#include "KalendarzG.h"
class Pracownik_Administracji :
	public Osoba
{
private:

public:
	Pracownik_Administracji();
	void Wyswietl_kalendarz(KalendarzG* kalendarz);
	bool Dodaj_karnet(int okres, int id, Klient* klient);
	bool Edytuj_Karnet(Karnet* karnet,int nowy_okres); //ile dni od dzisiaj!
	bool Zaplanuj_GrTrening(Data data, Czas czas, int czas_trwania, string opis, int id);
	bool Edytuj_GrTrening(GrTrening* grTrening,Data data, Czas czas, int czas_trwania, string opis, int id);
	bool Usun_GrTrening(GrTrening* grTrening);
	void Wyswietl_liste_uczestnikow(GrTrening grTrening);
	void Wyswietl_GrTrening(GrTrening grTrening);
};

