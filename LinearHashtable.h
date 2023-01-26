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


///I'm having trouble getting this to work...
///This would create a bucket that allows for holding the value as well as bools for empty and emptySinceStart
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
    //Type &operator[] (int ndx); //returns the value at position ndx
    T &operator[] (int ndx); //Using 'T' vs 'Type'
    friend std::ostream& operator<< <>(std::ostream& out, const LinearHashtable<T>& t); //Allows the user to output the hashtable

protected:
    int size_; // current size of the hashtable
    int capacity_; //max size of the hashtable

    ///hashtable I would like to use here:
    //bucket<T>* hashtable;

    ///working pointer here...
    T* hashtable; //list of pointers
};

//Constructor, that initializes the hashtable.  It initializes the array for storing the data to size capacity.
template<class T>
LinearHashtable<T>::LinearHashtable(int capacity){

    ///Constructor I would like to use here:
//    size_ = 0;
//    capacity_ = capacity;
//    hashtable = nullptr;

    ///Working constructor here...
    size_ = 0;
    capacity_ = capacity;
    hashtable = new T[capacity_];
    for (int i = 0; i < capacity_; i++) {
        hashtable[i] = -1; // -1 represents empty space in hashtable
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
//
//        while (bucketsProbed < capacity_){
//            //If empty, add key.
//            if(hashtable[bucket].empty){
//                hashtable[bucket].val = item;
//                hashtable[bucket].empty = false;
//                hashtable[bucket].emptySinceStart = false;
//                size_++;
//                return;
//            }
//            //if bucket is not empty find next bucket
//            bucket = (bucket + 1) % capacity_;
//            bucketsProbed++;
//        }

        ///Working function that I don't much care for..
        while (bucketsProbed < capacity_) {
            if (hashtable[bucket] == -1) // if open, add key.
            {
                hashtable[bucket] = item;
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

        ///function I would like to use:
//        if(hashtable[bucket].val == item){
//            return true;
//        }

        ///working function
        if (hashtable[bucket] == item) // if open, add key.
        {
            return true;
        }

        //if bucket is not empty find next bucket
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

        ///function I would like to use:
//        if(hashtable[bucket].val == item){
//            hashtable[bucket].val = null;
//            hashtable[bucket].empty = true;
//            return true;
//        }

        ///working function
        if (hashtable[bucket] == item)
        {
            hashtable[bucket] = -1; //set bucket to -1 to show empty
            size_--;
            return true;
        }

        //if target bucket did not match item, move to next bucket.
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

//Not yet sure how to impliment this.
//Type &operator[] (int ndx); //returns the value at position ndx
template <class T>
T& LinearHashtable<T>::operator[] (int ndx){
    if(ndx > capacity_ || hashtable[ndx] < 0){
        throw std::runtime_error("There is nothing at that index");
    }
    ///preferred method
//    return hashtable[ndx].val;

    ///working...
    return hashtable[ndx];
}

//Allows the user to output the hashtable
template<class T>
std::ostream& operator<<(std::ostream& out, const LinearHashtable<T> & t){

    ///Printing seems to be the crux of why I can't get my preferred hashtable to work...

    for(int i = 0; i < t.capacity_; i++){
        out << std::setw(0) << i << ": ";
        out << t.hashtable[i];
        out << std::endl;
    }
    return out;
}

#endif //INC_05_TRY_IT_OUT_LINEAR_PROBING_LINEARHASHTABLE_H
