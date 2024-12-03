#ifndef S21_AVL_TREE_H_
#define S21_AVL_TREE_H_

// #include "../s21_containers.h"
#include <iostream>
namespace s21 {
    template <class Key,class Value>
        class Tree{
            public:
            struct Node;
            Node *getNode();        
            void InsObj(Key key, Value value);
            void Remove(Key key);
            #ifdef DEBUG
            void PrintTree(Node * root){
                if(this->root_ != nullptr)printf("(M)(key %d) h(%d) %p\n",root->key_, root->height_,root);
                else printf("(M)%p\n",root);
                if(root->left_ != nullptr)printf("(L)(key %d) h(%d)\n",root->left_->key_, root->left_->height_);
                else printf("(L)%p\n",root->left_);
                if(root->right_ != nullptr)printf("(R)(key %d) h(%d)\n",root->right_->key_, root->right_->height_);
                else printf("(R)%p\n",root->right_);
                if(root->parent_ != nullptr)printf("(P) (parent_key %d) %p\n",root->parent_->key_,root->parent_);
                else printf("(P)%p\n",root->parent_);
                puts("====================================");
                if(root->left_ != nullptr){
                    PrintTree(root->left_);
                } 
                if(root->right_ != nullptr){
                    PrintTree(root->right_);
                } 
            }
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
                    this->first_elem=tmpPtr;
                    while(tmpPtr->parent_!=nullptr){
                        tmpPtr=tmpPtr->parent_;
                    }
                    while(tmpPtr->right_!=nullptr){
                        tmpPtr=tmpPtr->right_;
                    }
                    this->last_elem=tmpPtr;
                }
                Iterator(const Iterator & a){
                    this->address_=a.address_;
                    this->first_elem=a.first_elem;
                    this->last_elem = a.last_elem;
                }
                ~Iterator(){
                    if(this->address_ != nullptr) this->address_=nullptr;
                    if(this->first_elem != nullptr) this->first_elem = nullptr;
                    if(this->last_elem != nullptr) this->last_elem = nullptr;
                }

                Node * get(){
                    return this->address_;
                }
                Iterator &operator++(){
                    if(this->address_->right_ != nullptr){
                        this->address_=this->address_->right_;
                        while((this->address_!=nullptr)&&(this->address_->left_ != nullptr)){
                            this->address_=this->address_->left_;
                        }
                    }else if(this->address_!=this->last_elem){
                        static bool flag_root =false;
                        Node * frstPtr = this->address_;
                        this->address_  = this->address_->parent_;
                        while (this->address_->parent_ != nullptr&& (frstPtr == this->address_->right_)){
                            frstPtr=this->address_;
                            this->address_=this->address_->parent_;
                        }
                        
                    }
                    return * this;
                }
                Iterator & operator--(){
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
                private:
                Node * address_ = nullptr;
                Node * first_elem = nullptr;
                Node * last_elem = nullptr;
                friend class Tree;
            };
            // class  ConstIterator{
            //     public:

            //     private:

            // }

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
            Tree() = default;
            Tree(Key key, Value value);
            Tree(const Tree<Key, Value> &obj);
            ~Tree();
            private:
            typedef struct Node{
                Node * left_    = nullptr;
                Node * right_   = nullptr;
                Node * parent_  = nullptr;
                int height_ = 0;
                Key key_;
                Value value_;
            }Node;
            Node * root_ = nullptr;
        };    
};

#include "s21_AVL_Tree.tpp"
#endif