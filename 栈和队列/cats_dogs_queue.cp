#include <iostream>
#include <string>
#include<queue>
#include <vector>
using namespace std;

/*
 题目描述：
    实现猫狗队列
*/

// 类 Pet, Dog, Cat 的实现如下:
class Pet{
private:
    string type;
public:
    Pet(string type) {
        this->type = type;
    }
    
    string get_type() {
        return this->type;
    }
};

class Dog: public Pet {
public:
    Dog():Pet("dog") {}
    
};

class Cat: public Pet {
public:
    Cat(): Pet("cat") {}
};

class PetQueue {
private:
    Pet* pet = new Pet("pet");
    long count;
    
/*---------------------------------------------------------------------------*/

public:
    PetQueue(Pet* pet, long count) {
        this->pet = pet;
        this->count = count;
    }
    
    Pet* get_pet() {
        return this->pet;
    }
    
    long get_count() {
        return this->count;
    }
    
    string get_pet_type() {
        return this->pet->get_type();
    }
};


class CatDogQueue {
private:
    queue<PetQueue*> dogs;
    queue<PetQueue*> cats;
    long count;
    
public:
    CatDogQueue() {
        this->count = 0;
    }
    
    void add(Pet* pet) {
        if (pet->get_type() == "dog") {
            this->dogs.push(new PetQueue(pet, this->count++));
        } else if (pet->get_type() == "cat") {
            this->cats.push(new PetQueue(pet, this->count++));
        } else {
            return;
        }
    }
    
    bool is_empty() {
        return this->dogs.empty()&& this->cats.empty();
    }
    
    bool is_dogs_empty() {
        return this->dogs.empty();
    }
    
    bool is_cats_empty() {
        return this->cats.empty();
    }
    
    
    Dog* poll_dogs() {
        if (this->dogs.empty()) {
            return new Dog();
        } else {
            return static_cast<Dog*>(this->dogs.front()->get_pet());
        }
    }
    
    Cat* poll_cats() {
        if (this->dogs.empty()) {
            return new Cat();
        } else {
            return static_cast<Cat*>(this->cats.front()->get_pet());
        }
    }
    
    vector<Pet*> poll_all() {
        vector<Pet*> res;
        if (this->cats.empty() && this->dogs.empty()) {
            return res;
        }
        
        while (!this->cats.empty() || ! this->dogs.empty()) {
            if (this->cats.empty()) {
                while (!this->dogs.empty()) {
                    res.push_back(this->dogs.front()->get_pet());
                }
                break;
            }
            
            if (this->dogs.empty()) {
                while (!this->cats.empty()) {
                    res.push_back(this->cats.front()->get_pet());
                }
                break;
            }
            
            if (this->dogs.front()->get_count() < this->cats.front()->get_count()) {
                res.push_back(this->dogs.front()->get_pet());
            } else {
                res.push_back(this->cats.front()->get_pet());
            }
            
        }
        
        return res;
    }
};


