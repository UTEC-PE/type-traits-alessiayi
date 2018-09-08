#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
          this -> current=this -> current -> next;
          return *this;
        };
        DListIterator<T> operator--(){
          this -> current=this -> current -> prev;
          return *this;
        };
};

template <typename Tr>
class DList {
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;

    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T value) {
          Node<T> *Tmp= new Node<T>(value);
          if (!head){
            Tmp -> next=nullptr;
            Tmp -> prev=nullptr;
            head=tail=Tmp;
          }
          else{
            Tmp -> next=head;
            head -> prev=Tmp;
            head=Tmp;
          }
        }

        void push_back(T value) {
          Node<T> *Tmp= new Node<T>(value);
          if (!head){
            Tmp -> next=nullptr;
            Tmp -> prev=nullptr;
            head=tail=Tmp;
          }
          else{
            tail -> next=Tmp;
            Tmp -> prev=tail;
            Tmp -> next=nullptr;
            tail=Tmp;
          }
        }

        void pop_front() {
          if (!head){
            throw "NO";
          }
          if (!head -> next){
            delete head;
            head=nullptr;
          }
          else{
            Node<T> *Tmp=head -> next;
            Tmp -> prev=nullptr;
            head=nullptr;
            delete head;
            head=Tmp;
          }
        }

        void pop_back() {
          if (!head){
            throw "NO";
          }
          if (!head -> next){
            delete head;
            head=nullptr;
          }
          else{
            Node<T> *Tmp=tail -> prev;
            tail=nullptr;
            Tmp -> next=nullptr;
            delete tail;
            tail=Tmp;
          }
        }

        iterator begin() {
          return iterator(head);
        }

        iterator end() {
          return iterator(tail);
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
