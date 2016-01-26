#include "Node.h"

/**
* Constructor per defecte de la classe Node
*/
Node::Node()
{

}


/**
* Destructor per defecte de la classe Node
*/
Node::~Node()
{

}



/**
* Ens diu el valor de la llista de puntuaci� 
* @return el valor de la llista
*/
LlistaPuntuacio& Node::getValor()
{
	return m_valor;
}


/**
 * Ens diu el node seg�ent
 * @return el seg�ent node
 */
Node* Node::getNext()
{
	return m_next;
}


/**
* Retorna el valor de la llista en la qu� apunta el node
* @param valor llista de puntuaci�
*/
void Node::setValor(LlistaPuntuacio valor)
{
	m_valor = valor;
}


/**
* Permet determinar quin �s el seg�ent node
*/
void Node::setNext(Node* next)
{
	m_next = next;
}