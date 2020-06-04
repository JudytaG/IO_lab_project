#include "Pracownik_Administracji.h"

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

GrTrening* Pracownik_Administracji::Zaplanuj_GrTrening(Data data, Czas czas, Czas czas_trwania, string opis, int id, Trener_Personalny* trener)
{
	string status = "utworzony";
	GrTrening* trening = new GrTrening(data, czas, czas_trwania, id, status, opis, trener);
	KalendarzG::getInstance()->Dodaj_Wydarzenie(trening);
	return trening;
}

bool Pracownik_Administracji::Edytuj_GrTrening(GrTrening* grTrening, Data data, Czas czas, Czas czas_trwania, string opis, int id)
{
	grTrening->EdytujTrening(data, czas, czas_trwania, opis, id);
	return true;
}

bool Pracownik_Administracji::Usun_GrTrening(GrTrening* grTrening)
{
	grTrening = NULL;
	return false;
}

void Pracownik_Administracji::Wyswietl_liste_uczestnikow(GrTrening* grTrening)
{
	grTrening->WyswietlUczestnikow();
}

void Pracownik_Administracji::Wyswietl_GrTrening(GrTrening* grTrening)
{
	grTrening->Wyswietl();
}
