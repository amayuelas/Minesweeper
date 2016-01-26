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
* Ens diu el valor de la llista de puntuació 
* @return el valor de la llista
*/
LlistaPuntuacio& Node::getValor()
{
	return m_valor;
}


/**
 * Ens diu el node següent
 * @return el següent node
 */
Node* Node::getNext()
{
	return m_next;
}


/**
* Retorna el valor de la llista en la què apunta el node
* @param valor llista de puntuació
*/
void Node::setValor(LlistaPuntuacio valor)
{
	m_valor = valor;
}


/**
* Permet determinar quin és el següent node
*/
void Node::setNext(Node* next)
{
	m_next = next;
}