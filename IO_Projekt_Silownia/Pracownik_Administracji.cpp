#include "Pracownik_Administracji.h"

Pracownik_Administracji::Pracownik_Administracji()
{
}

void Pracownik_Administracji::Wyswietl_kalendarz(KalendarzG* kalendarz)
{
	kalendarz->Wyswietl();
}

bool Pracownik_Administracji::Dodaj_karnet(int okres, int id, Klient* klient)
{
	Karnet* nowy_karnet = new Karnet(okres, id);
	klient->Dodaj_karnet(nowy_karnet);
	return true;
}

bool Pracownik_Administracji::Edytuj_Karnet(Karnet* karnet, int nowy_okres)
{
	karnet->Przedluz(nowy_okres);
	return false;
}

bool Pracownik_Administracji::Zaplanuj_GrTrening(Data data, Czas czas, int czas_trwania, string opis, int id)
{
	
	return false;
}

bool Pracownik_Administracji::Zaplanuj_GrTrening(Data data, Czas czas, int czas_trwania, string opis, int id)
{

	return false;
}

bool Pracownik_Administracji::Edytuj_GrTrening(GrTrening* grTrening, Data data, Czas czas, int czas_trwania, string opis, int id)
{

	return false;
}

bool Pracownik_Administracji::Usun_GrTrening(GrTrening* grTrening)
{

	return false;
}

void Pracownik_Administracji::Wyswietl_liste_uczestnikow(GrTrening grTrening)
{

	
}

void Pracownik_Administracji::Wyswietl_GrTrening(GrTrening grTrening)
{



}


