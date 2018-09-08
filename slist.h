#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {
    public:
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
          this -> current=this -> current -> next;
          return *this;
        };
};

template <typename Tr>
class SList {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;

    private:
        Node<T>* head;
        Operation cmp;

    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
          while (*pointer){
            if (cmp(search,(*pointer) -> data)){
              return (*pointer) -> data==search;
            }
            pointer = &((*pointer) -> next);
          }
          return false;
        }

        bool insert(T value) {
          Node<T> *Val=new Node<T>(value);
          if(!head){//nada
            head=Val;
            Val -> next=nullptr;
            return true;
          }
          Node<T> **Puntero=&head;
          if (find(value,Puntero)){//ya hay
            return false;
          }
          else if (*Puntero==head){//principio
            Val -> next=head;
            head=Val;
            return true;
          }
          else if(!*Puntero){//final
            *Puntero=Val;
            return true;
          }
          else{//medio
            Val -> next=*Puntero;
            *Puntero=Val;
            return true;
          }
        }

        bool remove(T value) {
          Node<T> **Puntero=&head;
          if (!find(value,Puntero)){
            return false;
          }
          delete *Puntero;
          *Puntero = (*Puntero) -> next;
          return true;
        }

        iterator begin() {
          return iterator(head);
        }

        iterator end() {
          return iterator(nullptr);
        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
