#include "s21_map.hpp"

namespace s21 {
    template <typename Key, typename T>
    Map<Key,T>::Map(const Map<Key,T> &m){
        this->tree_ = m.tree_;
    }

    template <typename Key, typename T>
    Map<Key,T>::Map(Map<Key,T> &&m){
        this->tree_ = m.tree_;
        m.tree_ = nullptr;
    }
    template <typename Key, typename T>
    Map<Key,T>::~Map(){
        this->tree_.~Tree();
    }
}