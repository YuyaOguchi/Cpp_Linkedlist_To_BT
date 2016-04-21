/* Yuya Oguchi */
/* list.cpp */

#include "list.h"
#include <iostream>
using namespace std;

template <typename T>
List<T>::List() {
	cursor = NULL;
	N = 0;
}

template <typename T>
List<T>::~List(){
	while(N !=0){
		remove_current();
	}
}

template <typename T>
List<T>::List(const List& source){
	cursor = NULL;
	N = 0;
	operator=(source);
}
template <typename T>
void List<T>::start(){
	if(cursor!= NULL){
		while (cursor ->prev != NULL){
			cursor = cursor -> prev;
		}
	}
}

template <typename T>
void List<T>::end(){
	if(cursor!= NULL){
		while (cursor ->next != NULL){
			cursor = cursor -> next;
		}
	}
}

template <typename T>
void List<T>::advance(){
	if(cursor!= NULL){
	if (cursor -> next != NULL){
		cursor = cursor -> next;
	}
	}
}

template <typename T>
void List<T>::insert(T value){
	if(cursor == NULL){
		Node * temp = new Node(value, NULL, NULL);
		cursor = temp;
    }else if (cursor -> next == NULL){
        Node * temp = new Node(value, cursor, NULL);
        cursor -> next = temp;
    }else if (cursor->prev == NULL){
		Node * temp = new Node(value, NULL, cursor);
		cursor -> prev = temp;
    }else{
		Node * temp = new Node(value, cursor->prev, cursor);
		if(cursor == NULL){
			cursor = temp;
		}else{
			if(cursor ->prev != NULL){
				cursor->prev->next = temp;
			}
			cursor->prev = temp;
		}
	}
	N++;

}
template <typename T>
void List<T>::attach(T value){
	cout <<"Value in attach: " << value << endl;
	if(cursor == NULL){
		Node * temp = new Node(value, NULL,NULL);
		cursor = temp;
	}else if(cursor->next == NULL){
		Node * temp = new Node(value, cursor, NULL);
		cursor->next = temp;
	}else{
		Node * temp = new Node(value, cursor, cursor->next);
		cursor->next->prev = temp;
		cursor->next = temp;
	}
	N++;
}

template <typename T>
void List<T>::remove_current(){
	Node *temp = cursor;
	if(cursor->next == NULL){
		cursor = cursor ->prev;
		if (cursor !=NULL){
			cursor->next = NULL;
		}
		delete temp;
	}else if (cursor->prev ==NULL){
		cursor = cursor ->next;
		cursor->prev = NULL;
		delete temp;
	}else{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	N--;
}

template <typename T>
int List<T>::size()const{
	return N;
}

template <typename T>
T List<T>::current()const{
	return cursor->data;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& source){
	//start();
	if(this == &source){
	return *this;
	}
	while(N !=0){
		remove_current();
	}
	Node *temp = source.cursor;
	while(temp ->prev != NULL){
	temp = temp->prev;
	}
	while(temp != NULL){
		attach(temp->data);
		advance();
		temp = temp->next;
	}
	start();
	return *this;
}
