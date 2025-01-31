/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 
#include "abstractdb.hpp"
#include <algorithm>
#include <vector>
namespace nwen{
    /**
     * VectorDbTable class - represents a database table using a vector
     * @inherits AbstractDbTable
    */
    class VectorDbTable : public AbstractDbTable{
        private:
        int tableRows;
        std::vector<movie> table;
        public:
            int rows() const;
            movie * get(int) const;
            bool add(const movie&);
            bool update(unsigned long, movie&);
            bool remove(unsigned long);
            //default constructer 
            VectorDbTable(): tableRows(0) {}
            //default Destructor
            ~VectorDbTable()=default;
    };
}
