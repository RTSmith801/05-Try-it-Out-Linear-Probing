/**
 * @file: LinearHashtable.h
 * @assignment_name: 05 Try it Out: Linear Probing
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 01/20/2023
 * @brief: Implementing linear hashing on a fixed size hashtable.
 *
 */

#ifndef INC_05_TRY_IT_OUT_LINEAR_PROBING_LINEARHASHTABLE_H
#define INC_05_TRY_IT_OUT_LINEAR_PROBING_LINEARHASHTABLE_H

#include <iostream>
#include <iomanip>


template <class T>
struct Node{
    T info;
    Node<T>*link;
};

template <class T>
class LinearHashtable;

template <class T>
std::ostream& operator<<(std::ostream& out, const LinearHashtable<T>& t);

template<class T>
class LinearHashtable{
public:

    //explicit added by intellisense?
    explicit LinearHashtable(int capacity = 499);//Constructor, that initializes the hashtable.  It initializes the array for storing the data to size capacity.
    ~LinearHashtable(); //Deallocates memory used from the array pointer.
    void add(T item);  //Adds an item to the array, if a collision occurs, it will try the next position until it finds an empty position.  If the hashtable is at capacity then std::throw runtime_error("Table is full");
    bool contains(T item); //Determines if an item is in the hashtable
    bool remove(T item); //Removes the item from the hashtable
    bool full(); //Determines if the hashtable has reached capacity
    int size(); //Determines the max capacity of the hashtable
    bool empty(); //returns true if the hashtable is empty
    //Type &operator[] (int ndx); //returns the value at position ndx
    T &operator[] (int ndx); //Using 'T' vs 'Type'
    friend std::ostream& operator<< <>(std::ostream& out, const LinearHashtable<T>& t); //Allows the user to output the hashtable

protected:
    //int capacity;
    Node<T>** htable; //list of pointers
};

//Constructor, that initializes the hashtable.  It initializes the array for storing the data to size capacity.
template<class T>
LinearHashtable<T>::LinearHashtable(int capacity){

}

//Deallocates memory used from the array pointer.*
template<class T>
LinearHashtable<T>::~LinearHashtable(){
    delete [] htable;
};

//Adds an item to the array, if a collision occurs, it will try the next position until it finds an empty position.  If the hashtable is at
template<class T>
void LinearHashtable<T>::add(T item){

}

//Determines if an item is in the hashtable
template<class T>
bool LinearHashtable<T>::contains(T item){
    return true;
}

//Removes the item from the hashtable
template<class T>
bool LinearHashtable<T>::remove(T item){
    return true;
}

//Determines if the hashtable has reached capacity
template<class T>
bool LinearHashtable<T>::full(){
    return true;
}

//Determines the max capacity of the hashtable
template<class T>
int LinearHashtable<T>::size(){
    return 0;
}

//returns true if the hashtable is empty
template<class T>
bool LinearHashtable<T>::empty(){
    return true;
}

//Not yet sure how to impliment this.
//Type &operator[] (int ndx); //returns the value at position ndx
//T &operator[] (int ndx); //Using 'T' vs 'Type'

//Allows the user to output the hashtable
template<class T>
std::ostream& operator<<(std::ostream& out, LinearHashtable<T> & t){
//    for(int i = 0; i < t.capacity; i++){
//        out <<std::setw(0) << i << ": ";
//
//        auto curr = t.htable[i];
//        while(curr){
//            out << curr->info << " " ;
//            if(curr->link){
//                out << "->";
//            }
//            curr = curr->link;
//        }
//        out << std::endl;
//    }
}

#endif //INC_05_TRY_IT_OUT_LINEAR_PROBING_LINEARHASHTABLE_H
