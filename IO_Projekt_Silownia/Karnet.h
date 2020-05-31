#pragma once
class Karnet
{
public:
	int okres;
	int id;
	bool status;
	Karnet();
	Karnet(int okres, int id);
	bool GetStatus();
	bool Przedluz(int nowy_okres);

};

