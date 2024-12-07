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
    Map<Key,T> &Map<Key,T>::operator=(Map<Key,T> &m){
        this->tree_=m.tree_;
        return *this;
    }
    template <typename Key, typename T>
    Map<Key,T> &Map<Key,T>::operator=(Map<Key,T> &&m){
        tree_.~Tree();
        Map<Key,T> tmp(*m);
        this->tree_ = std::move(tmp.tree_);
        return *this;
    }
    
    template <typename Key, typename T>
    T & Map<Key,T>::at(const Key &key){
        auto it = tree_.begin();
        bool exception = true;
        bool break_falg=true;
        while(it != tree_.end() && break_falg){
            if(it.get()->key_==key){
                exception=false;
                break_falg=false;
            }else{it=it.operator++();}
        }
        if(exception) throw std::out_of_range("Out of range");
        return it.get()->value_;
    }

    template <typename Key, typename T>
    T & Map<Key,T>::operator[](const Key &key){
        auto result;
        
        return result;
    }
}