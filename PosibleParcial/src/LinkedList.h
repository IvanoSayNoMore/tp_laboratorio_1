/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);//ok controller_buscaIdMaximo
int ll_add(LinkedList* this, void* pElement);//ok parser_PassengerFromText
void* ll_get(LinkedList* this, int index);//ok parser_guardaPasajerosCsv
int ll_set(LinkedList* this, int index,void* pElement);// ok ll_sort
int ll_remove(LinkedList* this,int index);//okcontroller_removePassenger
int ll_clear(LinkedList* this);//ok ll_deleteLinkedList
int ll_deleteLinkedList(LinkedList* this);//ok Main
int ll_indexOf(LinkedList* this, void* pElement);//ok ll_contains
int ll_isEmpty(LinkedList* this);//ok controller_saveAsBinary
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);//ok ll_containsAll
int ll_containsAll(LinkedList* this,LinkedList* this2);//main
LinkedList* ll_subList(LinkedList* this,int from,int to);//ll_clone
LinkedList* ll_clone(LinkedList* this);//main
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//okc ontroller_sortPassenger
