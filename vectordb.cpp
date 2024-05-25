/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 

#include "vectordb.hpp"
#include <algorithm>
#include <vector>
#include <functional>

int nwen::VectorDbTable::rows() const{
    return this->tableRows;
}

 nwen::movie *  nwen::VectorDbTable::get(int row) {
    if(row >= this->tableRows){
        return nullptr;
    }
    return &this->table.at(row);
}

bool nwen::VectorDbTable::add(const nwen::movie& mv){
   // auto checkFound = std::find_if(this->table.begin(), this->table.end(), [mv](const movie& m) { return m.id == mv.id; });
    for(auto& m : this->table){
        if(m.id == mv.id){
            return false;
        }
    }
      //if ( checkFound != this->table.end()) return false;
      this->tableRows++;
      this->table.push_back(mv);
      return true;
}


bool nwen::VectorDbTable::remove(unsigned long id){
    //auto check = std::remove_if(this->table.begin(), this->table.end(), [id](const movie& r) { return r.id == id; });
    for(auto it = this->table.begin(); it != this->table.end(); it++){
        if(it->id == id){
            this->table.erase(it);
            this->tableRows--;
            return true;
        }
    }
    //f(check == this->table.end()) return false;
    
    return false;
}
bool nwen::VectorDbTable::update(unsigned long id, movie& mv) {
    for(auto& m : this->table){
        if(m.id == id){
            m = mv;
            return true;
        }
    }
    return false;
}



