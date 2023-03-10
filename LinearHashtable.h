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
struct bucket{
    T val;
    bool empty = true;
    bool emptySinceStart = true;
};

template <class T>
class LinearHashtable;

template <class T>
std::ostream& operator<<(std::ostream& out, const LinearHashtable<T>& t);

template<class T>
class LinearHashtable{
public:

    //explicit added by IDE? ~Seems to be working...
    explicit LinearHashtable(int capacity = 499);//Constructor, that initializes the hashtable.  It initializes the array for storing the data to size capacity.
    ~LinearHashtable(); //Deallocates memory used from the array pointer.
    void add(T item);  //Adds an item to the array, if a collision occurs, it will try the next position until it finds an empty position.  If the hashtable is at capacity then std::throw runtime_error("Table is full");
    bool contains(T item); //Determines if an item is in the hashtable
    bool remove(T item); //Removes the item from the hashtable
    bool full(); //Determines if the hashtable has reached capacity
    int size(); //Determines the max capacity of the hashtable
    bool empty(); //returns true if the hashtable is empty
    T &operator[] (int ndx); //Using 'T' vs 'Type'
    friend std::ostream& operator<< <>(std::ostream& out, const LinearHashtable<T>& t); //Allows the user to output the hashtable

protected:
    int size_; // current size of the hashtable
    int capacity_; //max size of the hashtable
    bucket<T>* hashtable;
};

//Constructor, that initializes the hashtable.  It initializes the array for storing the data to size capacity.
template<class T>
LinearHashtable<T>::LinearHashtable(int capacity){

    ///Constructor I would like to use here:
    size_ = 0;
    capacity_ = capacity;
    //hashtable = nullptr;
    hashtable = new bucket<T>[capacity_];
    for (int i = 0; i < capacity_; i++) {
        hashtable[i].val = -1; // -1 represents empty space in hashtable
    }
}

//Deallocates memory used from the array pointer.*
template<class T>
LinearHashtable<T>::~LinearHashtable(){
    delete [] hashtable;
}

//Adds an item to the array, if a collision occurs, it will try the next position until it finds an empty position.  If the hashtable is at
template<class T>
void LinearHashtable<T>::add(T item){
    if(full()){
        throw std::runtime_error("Hashtable is full");
    }
    if(!full()){

        int bucketsProbed = 0;
        int bucket = item % capacity_; //starting bucket/key

        ///function I would like to use here;
        while (bucketsProbed < capacity_){
            //If empty, add key.
            if(hashtable[bucket].empty){
                hashtable[bucket].val = item;
                hashtable[bucket].empty = false;
                hashtable[bucket].emptySinceStart = false;
                size_++;
                return;
            }
            //if bucket is not empty find next bucket
            bucket = (bucket + 1) % capacity_;
            bucketsProbed++;
        }
    }
}

//Determines if an item is in the hashtable
template<class T>
bool LinearHashtable<T>::contains(T item){

    if(empty()){
        throw std::runtime_error("table empty");
    }

    int bucket = item % capacity_;
    int bucketsProbed = 0;
    while (bucketsProbed < capacity_) {
        if(hashtable[bucket].val == item){
            return true;
        }
        bucket = (bucket + 1) % capacity_;
        bucketsProbed++;
    }
    return false;
}

//Removes the item from the hashtable
template<class T>
bool LinearHashtable<T>::remove(T item){
    if(empty()){
        throw std::runtime_error("Table empty");
    }

    int bucket = item % capacity_;
    int bucketsProbed = 0;
    while (bucketsProbed < capacity_) {
        if(hashtable[bucket].val == item){
            hashtable[bucket].val = -1;
            hashtable[bucket].empty = true;
            size_--;
            return true;
        }
        bucket = (bucket + 1) % capacity_;
        bucketsProbed++;
    }
    return false;
}

//Determines if the hashtable has reached capacity
template<class T>
bool LinearHashtable<T>::full(){
    return (size_ >= capacity_);
}

//Determines the max capacity of the hashtable
template<class T>
int LinearHashtable<T>::size(){
    return capacity_;
}

//returns true if the hashtable is empty
template<class T>
bool LinearHashtable<T>::empty(){
    return (size_ == 0);
}

//Type &operator[] (int ndx); //returns the value at position ndx
template <class T>
T& LinearHashtable<T>::operator[] (int ndx){
    if(ndx > capacity_ || hashtable[ndx].val < 0){
        throw std::runtime_error("There is nothing at that index");
    }
    return hashtable[ndx].val;
}

//Allows the user to output the hashtable
template<class T>
std::ostream& operator<<(std::ostream& out, const LinearHashtable<T> & t){
    for(int i = 0; i < t.capacity_; i++){
        out << std::setw(0) << i << ": ";
        out << t.hashtable[i].val;
        out << std::endl;
    }
    return out;
}

#endif //INC_05_TRY_IT_OUT_LINEAR_PROBING_LINEARHASHTABLE_H
