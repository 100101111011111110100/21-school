#ifndef S21_AVL_TREE_H_
#define S21_AVL_TREE_H_

// #include "../s21_containers.h"
#include <iostream>
namespace s21 {
    template <class Key,class Value>
        class Tree{
            public:
                using key_type = Key;
                using mapped_type = Value;
                using value_type = std::pair<const key_type, mapped_type>;
                
                struct Node; 
                Node *getNode();
                void InsObj(Key key, Value value);
                void Remove(Key key);
                
                #ifdef DEBUG
                void Print(Node * root);
                void PrintTree();
                #endif

                class Iterator{
                    public:
                    Iterator() = default;
                    Iterator(Node * a){
                        this->address_ = a;
                        Node * tmpPtr =this->address_;
                        while(tmpPtr->parent_!=nullptr){
                            tmpPtr=tmpPtr->parent_;
                        }
                        while(tmpPtr->left_ !=nullptr ){
                            tmpPtr=tmpPtr->left_;
                        }
                        this->first_elem_=tmpPtr;
                        while(tmpPtr->parent_!=nullptr){
                            tmpPtr=tmpPtr->parent_;
                        }
                        while(tmpPtr->right_!=nullptr){
                            tmpPtr=tmpPtr->right_;
                        }
                        this->last_elem_=tmpPtr;
                    }
                    Iterator(const Iterator & a){
                        this->address_=a.address_;
                        this->first_elem_=a.first_elem_;
                        this->last_elem_= a.last_elem_;
                    }
                    ~Iterator(){
                        if(this->address_ != nullptr) this->address_=nullptr;
                        if(this->first_elem_ != nullptr) this->first_elem_ = nullptr;
                        if(this->last_elem_ != nullptr) this->last_elem_ = nullptr;
                    }

                    Node * get(){ return this->address_; } // tempFunction
                    
                    Iterator &operator++(){
                        if(this->address_->right_ != nullptr){
                            this->address_=this->address_->right_;
                            while((this->address_!=nullptr)&&(this->address_->left_ != nullptr)){
                                this->address_=this->address_->left_;
                            }
                        }else if(this->address_!=this->last_elem_){
                            Node * frstPtr = this->address_;
                            this->address_  = this->address_->parent_;
                            while (this->address_->parent_ != nullptr&& (frstPtr == this->address_->right_)){
                                frstPtr=this->address_;
                                this->address_=this->address_->parent_;
                            }
                            
                        }
                        return * this;
                    }
                    Iterator &operator--(){
                        if(this->address_->right_ != nullptr){
                            this->address_=this->address_->left_;
                            while((this->address_!=nullptr)&&(this->address_->right_ != nullptr)){
                                this->address_=this->address_->right_;
                            }
                        }else if(this->address_!=this->first_elem_){
                            Node * frstPtr = this->address_;
                            this->address_  = this->address_->parent_;
                            while (this->address_->parent_ != nullptr&& (frstPtr == this->address_->left_)){
                                frstPtr=this->address_;
                                this->address_=this->address_->parent_;
                            }
                        }
                        return * this;
                    }
                    bool operator==(const Iterator &other){
                        return this->address_==other.address_;
                    }
                    bool operator!=(const Iterator &other){
                        return this->address_!=other.address_;
                    }
                    /*
                    bool operator==(const Iterator &other) {
                        bool result = true;
                        Iterator tmp_first = *this;
                        Iterator tmp_second = other;
                        bool break_flag=true;
                        while(break_flag && result){
                            // printf("(K)%d %d\n (V)%d %d\n",
                            // tmp_first.address_->key_,
                            // tmp_second.address_->key_,
                            // tmp_first.address_->value_,
                            // tmp_second.address_->value_);
                            if(tmp_first.address_==tmp_first.last_elem_ && 
                            tmp_second.address_==tmp_second.last_elem_){
                               break_flag=false;
                            }else if((tmp_first.address_==tmp_first.last_elem_ && 
                            tmp_second.address_!=tmp_second.last_elem_)||
                            (tmp_first.address_!=tmp_first.last_elem_ && 
                            tmp_second.address_==tmp_second.last_elem_)){
                                result =false;
                                break_flag=false;
                            }
                            if(
                                tmp_first.address_->key_!=tmp_second.address_->key_ ||
                                tmp_first.address_->value_!=tmp_second.address_->value_
                            ){  result = false;  }
                            else{
                                tmp_first=tmp_first.operator++();
                                tmp_second=tmp_second.operator++();
                                // tmp_first++;
                                // tmp_second++;
                            }
                        }
                        return result;
                    }
                    bool operator!=(const Iterator &other) { 
                        bool result = false;
                        Iterator tmp_first = *this;
                        Iterator tmp_second = other;
                        bool break_flag=true;
                        while(break_flag){
                            
                            if(tmp_first.address_==tmp_first.last_elem_ && 
                            tmp_second.address_==tmp_second.last_elem_){
                               break_flag=false;
                            }else if((tmp_first.address_==tmp_first.last_elem_ && 
                            tmp_second.address_!=tmp_second.last_elem_)||
                            (tmp_first.address_!=tmp_first.last_elem_ && 
                            tmp_second.address_==tmp_second.last_elem_)){
                                result = true;
                                break_flag=false;
                            }
                            if(
                                tmp_first.address_->key_!=tmp_second.address_->key_ ||
                                tmp_first.address_->value_!=tmp_second.address_->value_
                            ){  result = true;  }
                                tmp_first=tmp_first.operator++();
                                tmp_second=tmp_second.operator++();
                                // tmp_first++;
                                // tmp_second++;
                        }
                        return result;
                    }
                    */
                    private:
                    Node * address_ = nullptr;
                    Node * first_elem_ = nullptr;
                    Node * last_elem_ = nullptr;
                    friend class Tree;
                }; // End Iterator
                Iterator begin(){
                    Node * tmpPtr = this->root_;
                    while(tmpPtr->left_ !=nullptr ){
                        tmpPtr=tmpPtr->left_;
                    }
                    Iterator a(tmpPtr);
                    return a;
                }
                Iterator end(){
                    Node * tmpPtr = this->root_;
                    while(tmpPtr->right_ !=nullptr ){
                        tmpPtr=tmpPtr->right_;
                    }
                    return Iterator(tmpPtr);
                }
                class  ConstIterator{
                    public:
                    ConstIterator() = default;
                    ConstIterator(const Node * a){
                        this->address_ = a;
                        this->first_elem=this->address_;;
                        while(this->first_elem->parent_!=nullptr){
                            this->first_elem=this->first_elem->parent_;
                        }
                        while(this->first_elem->left_!=nullptr){
                            this->first_elem=this->first_elem->left_;
                        }
                        this->last_elem=this->address_;
                        while(this->last_elem->parent_!=nullptr){
                            this->last_elem=this->last_elem->parent_;
                        }
                        while(this->last_elem->right_!=nullptr){
                            this->last_elem=this->last_elem->right_;
                        }
                    }
                    ConstIterator(const Iterator & a){
                        this->address_=a.address_;
                        this->first_elem=a.first_elem;
                        this->last_elem = a.last_elem;
                    }
                    ~ConstIterator(){
                        if(this->address_ != nullptr) this->address_=nullptr;
                        if(this->first_elem != nullptr) this->first_elem = nullptr;
                        if(this->last_elem != nullptr) this->last_elem = nullptr;
                    }

                    const Node * get(){
                        return this->address_;
                    }
                    ConstIterator &operator++(){
                        if(this->address_->right_ != nullptr){
                            this->address_=this->address_->right_;
                            while((this->address_!=nullptr)&&(this->address_->left_ != nullptr)){
                                this->address_=this->address_->left_;
                            }
                        }else if(this->address_!=this->last_elem){
                            Node * frstPtr = this->address_;
                            this->address_  = this->address_->parent_;
                            while (this->address_->parent_ != nullptr&& (frstPtr == this->address_->right_)){
                                frstPtr=this->address_;
                                this->address_=this->address_->parent_;
                            }
                        }
                        return * this;
                    }
                    ConstIterator & operator--(){
                        if(this->address_->right_ != nullptr){
                            this->address_=this->address_->left_;
                            while((this->address_!=nullptr)&&(this->address_->right_ != nullptr)){
                                this->address_=this->address_->right_;
                            }
                        }else if(this->address_!=this->first_elem){
                            Node * frstPtr = this->address_;
                            this->address_  = this->address_->parent_;
                            while (this->address_->parent_ != nullptr&& (frstPtr == this->address_->left_)){
                                frstPtr=this->address_;
                                this->address_=this->address_->parent_;
                            }
                        }
                        return * this;
                    }
                    bool operator==(const ConstIterator &other){
                        return this->address_==other.address_;
                    }
                    bool operator!=(const ConstIterator &other){
                        return this->address_!=other.address_;
                    }
                    private:
                    const Node * address_ = nullptr;
                    const Node * first_elem = nullptr;
                    const Node * last_elem = nullptr;
                    friend class Tree;

                };//End const iterator
                ConstIterator begin() const{
                    Node * tmpPtr = this->root_;
                    while(tmpPtr->left_ !=nullptr ){
                        tmpPtr=tmpPtr->left_;
                    }
                    ConstIterator a(tmpPtr);
                    return a;
                }
                ConstIterator end() const{
                    Node * tmpPtr = this->root_;
                    while(tmpPtr->right_ !=nullptr ){
                        tmpPtr=tmpPtr->right_;
                    }
                    ConstIterator a(tmpPtr);
                    return a;
                }
                
                // bool operator==(Tree<Key, Value> &obj){
                //     Iterator it1 = this->begin();
                //     Iterator it2 = obj.begin();
                //     return it1==it2;
                // }
                // bool operator!=(Tree<Key, Value> &obj){
                //     Iterator it1 = this->begin();
                //     Iterator it2 = obj.begin();
                //     return it1!=it2;
                // }
                Tree & operator=(const Tree<Key, Value> &obj);

                Tree();
                Tree(std::initializer_list<value_type> const &items);
                Tree(const Tree<Key, Value> &obj);
                ~Tree();
            protected:
                Node * findNode(const Key &key);
            private:
                typedef struct Node{
                    Node * left_    = nullptr;
                    Node * right_   = nullptr;
                    Node * parent_  = nullptr;
                    int height_ = 0;
                    Key key_;
                    Value value_;
                }Node;
                Node * root_=nullptr;
        };    

};

#include "s21_AVL_Tree.tpp"
#endif