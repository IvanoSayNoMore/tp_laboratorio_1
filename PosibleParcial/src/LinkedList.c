#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = RETORNONEGATIVO;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node * punteroANode = NULL;

	if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this))
	{
		punteroANode = this->pFirstNode;

		for(int i=0 ; i<nodeIndex ; i++)
		{
			punteroANode = punteroANode->pNextNode;
		}

	}
    return punteroANode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = RETORNONEGATIVO;
    Node * pNodoPrevio;
    Node * pNodoNuevo;

    if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this))
    {
    	pNodoNuevo = (Node*)malloc(sizeof(Node*));
    	if(pNodoNuevo != NULL)
    	{
    		pNodoNuevo->pElement = pElement;
    		if(nodeIndex == 0 )
    		{
    			pNodoNuevo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNodoNuevo;
    		}
    		else
    		{
    			pNodoPrevio=getNode(this, nodeIndex-1);
    			if(pNodoPrevio != NULL)
    			{
        			pNodoNuevo->pNextNode = pNodoPrevio->pNextNode;
        			pNodoPrevio->pNextNode = pNodoNuevo;
    			}
    		}
    		this->size++;
    		returnAux=RETORNOPOSITIVO;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = RETORNONEGATIVO;
    int len;
    if(this != NULL )
    {
    	len=ll_len(this);
    	returnAux=addNode(this, len, pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNodo = getNode(this, index);
    	if(pNodo != NULL)
    	{
    		returnAux = pNodo->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = RETORNONEGATIVO;
    Node* pNode;
    if(this != NULL && index > -1 && index<ll_len(this))
    {
    	pNode=getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement=pElement;
    		returnAux=RETORNOPOSITIVO;
    	}
    }
    return returnAux;

}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = RETORNONEGATIVO;
    Node* pNode;
    Node* pNodoAnterior;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode=getNode(this, index);
    	if(pNode != NULL)
    	{
    		if(index==0)
    		{
    			this->pFirstNode=pNode->pNextNode;
    			returnAux=RETORNOPOSITIVO;
    		}
    		else
    		{
    			pNodoAnterior=getNode(this, index-1);
    			if(pNodoAnterior != NULL)
    			{
    				pNodoAnterior->pNextNode = pNode->pNextNode;
    			}
    		}
			free(pNode);
			this->size--;
			returnAux = RETORNOPOSITIVO;

    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = RETORNONEGATIVO;
    if(this != NULL)
    {
    	for(int i = 0; i <ll_len(this);i++)
		{
    		if(ll_remove(this, i)==RETORNOPOSITIVO)
    		{
    			returnAux = RETORNOPOSITIVO;
    		}
    		else
    		{
    			returnAux = RETORNONEGATIVO;
    			break;
    		}
		}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = RETORNONEGATIVO;

    if(this!=NULL && ll_clear(this)==RETORNOPOSITIVO)
    {
		free(this);
		returnAux = RETORNOPOSITIVO;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = RETORNONEGATIVO;
    int len;
   // void* pAuxiliarElemento;
    if(this != NULL)
    {
    	len=ll_len(this);
    	for(int i=0;i<len;i++)
    	{
    		if(pElement == ll_get(this, i))
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_len(this)>0)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = RETORNONEGATIVO;

    if(this != NULL && index<=ll_len(this) && index > -1 )
    {
    		returnAux = addNode(this, index, pElement);    	//Agrega enlaza un elemento a la lista
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index<ll_len(this) && index > -1 )
    {
    	returnAux=ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(ll_indexOf(this, pElement)!=-1)
    	{
    		returnAux = 1 ;
    	}
    	else
    	{
    		returnAux = 0 ;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void* pElement;
    if(this != NULL && this2 != NULL)
    {
    	len=ll_len(this2);
    	returnAux = 1;
    	for(int i = 0; i<len ; i++)
    	{
    		pElement = ll_get(this2, i);
    		if(ll_contains(this, pElement)==0)
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;
    void* auxElement = NULL;
    int len;
    len=ll_len(this);
    if(this!=NULL && from >-1 && from < len && to > -1 && to <= len && to > from )
    {
    	subList = ll_newLinkedList();
    	if(subList != NULL)
    	{
    		for(int i=from; i<to ;i++)
    		{
    			auxElement = ll_get(this, i);
    			ll_add(subList, auxElement);
    		}
    	}
    }

    return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clone  = NULL;
    if(this!=NULL)
    {
    	clone = ll_subList(this, 0, ll_len(this));
    }
    return clone;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int estaOrdenado;
    void* pElementA;
    void* pElementB;
    int criterio;
    if(this!=NULL &&(order==0 || order ==1) && pFunc != NULL)
    {
		do
		{
			estaOrdenado = 0;
			for (int i = 0; i < ll_len(this)- 1; i++)
			{
				pElementA = ll_get(this,i);
				pElementB = ll_get(this,i+1);
				criterio = pFunc(pElementA,pElementB);
				if ((order == 1 && criterio == 1) || (order == 0 && criterio == -1))
				{
					ll_set(this,i,pElementB);
					ll_set(this,i+1,pElementA);
					estaOrdenado = 1;
				}
			}
		}while (estaOrdenado);
		returnAux = 0;
    }

    return returnAux;

}

