#include "Tauler.h"

class Partida
{
public:
	Partida();
	Partida(int nivell);
	~Partida();

	void inicialitza(int nivell);

	// Creat per mi
	int juga();

private:
	int m_nivell;
	Tauler m_tauler;
};