#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "../s21_AVL_Tree/s21_AVL_Tree.hpp"
#include "../s21_containers.hpp"

namespace s21 {

    template < class Key, class T>
    class Map : public Tree<Key,T> { 
        public:
            //Map Member type
            using key_type = Key;
            using mapped_type = T;
            using value_type = std::pair<const key_type, mapped_type>;
            using reference = value_type&;
            using const_reference = const value_type&;
            using iterator = typename Tree<Key, T>::Iterator;
            using const_iterator = typename Tree<Key, T>::ConstIterator;
            // using size_type = std::size_t;
            //End Map Member type

            
            // Map Member functions /Constructors
            Map(): tree_(){};//default constructor
            Map(std::initializer_list<value_type> const &items): tree_(items){};//	initializer list constructor, creates the map initizialized using std::initializer_list
            Map(const Map<Key,T> &m): tree_(m.tree_){};//copy constructor
            Map(Map &&m):tree_(std::move(m.tree_)){};//	move constructor
            ~Map();//destructor
            // End Map Member functions / Constructors

            // Operators
            Map &operator=(Map &m);
            Map &operator=(Map &&m);//	assignment operator overload for moving object
            T& at(const Key& key);//	access specified element with bounds checking
            T& operator[](const Key& key); //access or insert specified element
                          
            #ifdef DEBUG
            void PrintMap();
            #endif
        private :    
            s21::Tree<Key,T> tree_;   
    };
}




#include "s21_map.tpp"
#endif
