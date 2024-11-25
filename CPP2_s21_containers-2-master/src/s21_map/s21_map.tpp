#include "s21_map.hpp"

namespace s21 {
    template <typename Key, typename T>
    Map<Key, T>::Map(std::initializer_list<typename Map<Key, T>::value_type> const &items) {
        
        // for(  auto ptr = items.begin()+1;ptr!=items.end();ptr++){
        //     this->tree_.InsObj(ptr->first,ptr->second);
            
        // }
    }

    template <typename Key, typename T>
    Map<Key, T>::~Map() {
        this->tree_.~Tree();
    }
    
    
    // template <typename Key, typename T>
    // Map<Key, T>::Map(const Map &m) {
    
    // }

    // template <typename Key, typename T>
    // Map<Key, T>::~Map() {
    
    // }
}