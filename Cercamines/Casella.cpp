#include "Casella.h"


/**
* Constructor per defecte de la classe casella
*/
Casella::Casella()
{
	m_explotada = false;
	m_marcada = false;
	m_minada = false;
	m_numVeinesMinades = 0;
	m_tapada = false;
}


/**
* Destructor per defecte de la classe casella
*/
Casella::~Casella()
{

}


/**
* Ens diu si la casella està minada o no
* @return true si està minada i false si no ho està
*/
bool Casella::getMinada()
{
	return m_minada;
}


/**
* Permet establir la casella com a minada
* @param minada true si es vol minar la casella i false si es vol desminar
*/
void Casella::setMinada(bool minada)
{
	m_minada = minada;
}


/**
* Ens diu si la casella ha estat marcada pel jugador
* @return true si ha estat marcada i false si no ho ha estat
*/
bool Casella::getMarcada()
{
	return m_marcada;
}


/**
* Permet marcar la casella
* @param marcada true si es vol marcar la casella i false si es vol desmarcar
*/
void Casella::setMarcada(bool marcada)
{
	m_marcada = marcada;
}


/**
* Ens diu si la casella ha estat tapada
* @return true si està tapada i false si no ho està
*/
bool Casella::getTapada()
{
	return m_tapada;
}


/**
* Permet tapar la casella
* @param tapada true si es vol tapar la casella i false si es vol destapar
*/
void Casella::setTapada(bool tapada)
{
	m_tapada = tapada;
}


/**
* Ens diu si la casella ha explotat
* @return true si ha explotat i false si no ho ha fet
*/
bool Casella::getExplotada()
{
	return m_explotada;
}


/**
* Permet marcar la casella com explotada
* @param explotada true si es vol indicar la casella com a explotada i false si es vol indicar com a no explotada
*/
void Casella::setExplotada(bool explotada)
{
	m_explotada = explotada;
}


/**
* Ens diu el nombre de veines minades que té la casella
* @return el nombre de veines minades
*/
int Casella::getVeinesMinades() const
{
	return m_numVeinesMinades;
}


/**
* Permet incrementar en 1 el nombre de caselles veines que estan minades
*/
void Casella::incrementaVeinesMinades()
{
	m_numVeinesMinades++;
}