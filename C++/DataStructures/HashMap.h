#ifndef HASH_MAP_H
#define HASH_MAP_H
#include <cstdlib>
#include <string>
#include <exception>
#include <iostream>

class ElementNotFoundException : public std::exception
{
  public:
    std::string what()
    {
        return "Element not found in hashmap";
    }
};

template <typename K, typename V>
class HashMap
{
    int size;
    int numOfElements;
    V *values;
    K *keys;
    bool *hasValue;

  public:
    HashMap(int initSize = 16)
    {
        this->size = initSize;
        this->numOfElements = 0;
        this->values = new V[this->size];
        this->keys = new K[this->size];
        this->hasValue = new bool[this->size];
        for (int i = 0; i < this->size; i++)
            this->hasValue[i] = false;
    }

    HashMap(const HashMap &map)
    {
        this->size = map.size;
        this->numOfElements = map.numOfElements;
        this->values = new V[this->size];
        this->keys = new K[this->size];
        this->hasValue = new bool[this->size];
        for (int i = 0; i < this->size; i++)
        {
            if (map.hasValue[i])
            {
                this->keys[i] = map.keys[i];
                this->hasValue[i] = map.hasValue[i];
                this->values[i] = map.values[i];
            }
        }
    }

    ~HashMap()
    {
        if (this->keys != NULL)
            delete[] keys;
        if (this->values != NULL)
            delete[] values;
        if (this->hasValue != NULL)
            delete[] hasValue;
    }

    void insert(K key, V value)
    {
        if (this->numOfElements == this->size)
        {
            this->reHashTable(); //if max size is reached rehashing table and also doubling its size
            this->insert(key, value);
        }
        else
        {
            int location = this->hash(key);
            while (this->hasValue[location]) //performing linear probing
            {
                location = (location + 1) % this->size;
            }
            this->keys[location] = key;
            this->values[location] = value;
            this->hasValue[location] = true;
        }
    }

    V get(K key) throw(std::exception)
    {
        int location = this->hash(key);
        while (hasValue[location])
        {
            if (this->keys[location] == key)
                return this->values[location];
            location = (location + 1) % this->size;
        }
        ElementNotFoundException e;
        throw e;
    }

    void traverse()
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->hasValue[i])
            {
                std::cout << "Hash: " << i
                          << " Key: " << this->keys[i]
                          << " Value: " << this->values[i]
                          << std::endl;
            }
        }
    }

  protected:
    void reHashTable() //rehashing all the elements in the table and also doubling the size of the table
    {
        int tempSize = this->size;
        K *tempKeys = this->keys;
        V *tempValues = this->values;
        bool *tempHasValues = this->hasValue;
        this->size = this->size * 2;
        this->values = new V[this->size];
        this->keys = new K[this->size];
        this->hasValue = new bool[this->size];
        this->numOfElements = 0;
        for (int i = 0; i < this->size; i++)
            this->hasValue[i] = false;
        for (int i = 0; i < tempSize; i++)
        {
            this->insert(tempKeys[i], tempValues[i]);
        }
        delete[] tempKeys;
        delete[] tempValues;
        delete[] tempHasValues;
    }
    int hash(std::string key) //simple mod size hash function for strings
    {
        long total = 0;
        for (int i = 0; i < key.length(); i++)
            total += key[i];
        return total % this->size;
    }
    int hash(long key) //simple mod size hash function for int or long
    {
        return key % this->size;
    }
};

#endif