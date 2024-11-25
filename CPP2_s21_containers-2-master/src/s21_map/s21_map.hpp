#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "../s21_AVL_Tree/s21_AVL_Tree.hpp"
#include "../s21_containers.h"

namespace s21 {

    template < class Key, class T>
    class Map :public Tree<Key,T> {
        public:
            using key_type = Key;
            using mapped_type = T;
            using value_type = std::pair<const Key, T>;
            using reference = value_type&;
            using const_reference = const value_type&;
            // using iterator = typename Tree<Key, T>::iterator;
            // using const_iterator = typename Tree<Key, T>::const_iterator;
            using size_type = std::size_t;
            // Constructors
            Map()=default;	//default constructor, creates empty map
            Map(std::initializer_list<value_type> const &items);//	initializer list constructor, creates the map initizialized using std::initializer_list
            // Map(const map &m);//copy constructor
            // Map(map &&m);//	move constructor
            ~Map();//	destructor
            // // Operators
            // operator=(Map &&m);//	assignment operator overload for moving object
        private : 
            s21::Tree<Key,T> tree_;
    };
}




#include "s21_map.tpp"
#endif
