//
// Created by Ebuka Onyeka on 2021-11-23.
//

#ifndef ASSIGNMENT4_PLIST_H
#define ASSIGNMENT4_PLIST_H

template <class T>
class Plist{
private:
    int capacity;
    int size = 0;
    int current = -1;
    T *myarray;
    T get();
    inline void start(){if(current != -1)current = -1;}
    inline void next(){current+=1;}
    bool isLast();
    int getCurrent();
public:
    Plist(){
        capacity = 0;
        size = 0;
        current = -1;
        myarray = new T[capacity];
    }
    inline Plist(int cap) : size(0), current(-1), capacity(cap), myarray(new T[capacity]){};
    Plist(const Plist& tar) :  capacity(tar.capacity), size(0), current(-1){
        Plist val = const_cast<Plist>(&tar);
        myarray = new T[capacity];
        if(val.size>0){
            start();
            do{
                myarray[current+1] =  val.getItem(current+1);
                size++;
                next();
            }while(!val.isLast());
        }
        else{
            myarray = new T[capacity];
        }
    }
    Plist& operator=(const Plist& rhs){
        if(this== &rhs){
            start();
            T* tmp = new T[rhs.capacity];
            while(!rhs.isLast()){
                tmp[getCurrent()+1] = rhs.myarray[getCurrent()+1];
                next();
            }
            myarray = tmp;
            return *this;
        }
        start();
        delete myarray;
        T tmp = new T[capacity];
        while(!rhs.isLast()){
            tmp[getCurrent()+1] = rhs.myarray[getCurrent()+1];
            next();
        }
        myarray = tmp;
        return *this;
    }


//    Plist(T& copy){
//
//    }
    virtual ~Plist(){
        delete[] myarray; myarray = nullptr;
    }
    void add(T item){
        if(myarray == NULL)myarray = new T[capacity];
        if(isFull()){
            throw std::out_of_range("No Space");
        }
        else{
            myarray[size] = item;
            size++;
        }
    };
    bool remove(T item){
        start();
        if(size > 0){
            int location = -1;
            do{
                if(get() == item){
                    location = current+1;
                    break;
                }
                else{
                    next();
                }
            }while(!isLast());  // Iterating without for(int i = 0;....)
            if(location>-1){
                if(size-1 != location){
                    myarray[location] = myarray[size - 1];
                }
                T *tmp = new T[capacity];

                start();
                do{
                    tmp[current+1] = myarray[current+1];
                    next();
                }while(!isLast()); // Iterating without for(int i = 0;....)


                delete[] myarray;

                myarray = tmp;
                size--;
                return true;
            }
            else{
                throw std::domain_error("Does not exist");
            }
        }
        else{
            throw std::domain_error("Array not initialized");
        }
    };
    T getItem(int i);
    bool isFull();
    int getSize();

    int getCapacity();
};
#endif //ASSIGNMENT4_PLIST_H


