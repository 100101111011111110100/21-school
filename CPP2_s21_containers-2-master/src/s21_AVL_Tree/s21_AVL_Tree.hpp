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
            Tree() = default;
            Tree(Key key, Value value);
            Tree(const Tree<Key, Value> &obj);
            ~Tree();
            protected:
            
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