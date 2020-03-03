#include "SimpleList.h"
#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"
#include <iostream>
using namespace std;

template <class T>
SimpleList<T>::SimpleList(){
	numElements = 0;
	elements = new T[CAPACITY];
	//elements<T>[CAPACITY];
}
template<class T>
void destroy(T element) {
	//cout << "No *" << endl;
}
template <class T>
void destroy(T* element) {
	// delete the pointer type
	//cout << "Yes *" << endl;
	delete  element;
}
template <class T>
SimpleList<T>::~SimpleList(){
	//cout << "Here 1" << endl;
	//delete [] elements;
	//cout << "Here" << endl;
	//delete [] elements;
            for(int i = 0; i<numElements; i++){
             if( is_pointer<T>::value){
              	//	cout << "Here 1" << endl;
                destroy(elements[i]);
              }
              else{
              ///		cout << "Here 2" << endl;

                 destroy(elements[i]);
               }

            }


        delete [] elements;

	// if(is_pointer<T>::value){
	// 	cout << "Here 2" << endl;
	// 	destroy(elements);
	// }
	// else{
	// 	cout << "Here 3" << endl;
	// 	destroy(elements);
	// }

}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
	if(index >= numElements || index < 0){
		// Throws a InvalidIndexException if there is no element at index
		//throw InvalidIndexException();
		InvalidIndexException x;
		throw x;
	}
	else {
		return elements[index];
	}
}
template <class T>
bool SimpleList<T>::empty() const{
	if(numElements == 0){
		return true;
	}
	else{
		return false;
	}
}
template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
	if(empty()){
		//throw EmptyListException();
		EmptyListException why;
		throw why;
	}
	else {
		return elements[0];
	}
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
	int last = numElements -1;
	if (empty()){
		EmptyListException why;
		throw why;
		
	}
	else {
		return elements[last];
	}
}
template <class T>
int SimpleList<T>::getNumElements() const{
	// int count = 0;
	
	// if(empty()){
	// 	return 0; 
	// }
	// else{
	// 	for(int i = 0; i<CAPACITY;i++){
	// 		if (elements[i] != f){
	// 			count++;
	// 			cout << "here "<< count << endl;
	// 		}
	// 	}
	// }	
	// // cout << "here "<< count << endl;
	// return count;
	return numElements;
 }
template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
	//int size = numElements;
	if(numElements == CAPACITY){
		// throw (FullListException)
		FullListException full;
		throw full;
		
	}
	else {
		elements[numElements++] = item;
		//size++;
		//numElements++;
	}
}
template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
	if(numElements == 0){
		EmptyListException emp;
		throw emp;
	}
	else if(index >= numElements|| index<0){
		// Throws a InvalidIndexException if there is no element at index
		//throw InvalidIndexException();
		InvalidIndexException x;
		throw x;
	}
	else{
		destroy(elements[index]);
		for (int i = index+1 ; i< numElements; i++){
		//	 cout << "here "<< i << endl;
			elements[i-1]=elements[i];
		}
		numElements = numElements - 1;
	}


}






