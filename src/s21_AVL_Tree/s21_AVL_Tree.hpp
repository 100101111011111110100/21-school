#ifndef S21_AVL_TREE_H_
#define S21_AVL_TREE_H_

#include <iostream>

namespace s21 {
    template <class Key,class Value>
        class Tree{
            public:
            struct Node;
            //Get
            Node *getNode();
            //
            //Set
            //void setNode(Node *a);
            //          
            void InsObj(Key key, Value value) ;

            void PrintTree(Node * root){
                printf("(M)(key %d) h(%d)\n",root->key_, root->height_);
                if(root->left_ != nullptr)printf("(L)(key %d) h(%d)\n",root->left_->key_, root->left_->height_);
                else printf("(L)%p\n",root->left_);
                if(root->right_ != nullptr)printf("(R)(key %d) h(%d)\n",root->right_->key_, root->right_->height_);
                else printf("(R)%p\n",root->right_);
                puts("====================================");
                if(root->left_ != nullptr){
                    PrintTree(root->left_);
                } 
                if(root->right_ != nullptr){
                    PrintTree(root->right_);
                } 
            }

            Tree() = default;
            Tree(Key key, Value value);
            Tree(const Tree<Key, Value> &obj);
            ~Tree();
            protected:
            
            private:
            typedef struct Node{
                Node *left_ = nullptr;
                Node *right_ = nullptr;
                // Node *parent_ = nullptr;
                int height_ = 0;
                Key key_;
                Value value_;
            }Node;
            Node * root_ = nullptr;
        };    
};

#include "s21_AVL_Tree.tpp"
#endif