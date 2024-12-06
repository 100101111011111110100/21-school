#include "s21_map.hpp"

namespace s21 {
    #ifdef DEBUG
    template <typename Key, typename T>
    void Map<Key,T>::PrintMap(){
        tree_.PrintTree();
    }
    #endif
    template <typename Key, typename T>
    Map<Key,T>::~Map(){
        tree_.~Tree();
    }
    template <typename Key, typename T>
    Map<Key,T>::Map(Map &&m){
        tree_=std::move(m.tree_);
    }
}