#include "s21_AVL_Tree.hpp"

namespace s21 {
    //Constructors
    template <typename Key, typename Value> 
        typename Tree<Key,Value>::Node * Tree<Key,Value>::getNode(){
            return this->root_;
        }
    template <typename Key, typename Value>
    Tree<Key, Value>::Tree(Key key, Value value) {
        this->root_ = new Node;
        this->root_->key_       = key;
        this->root_->value_     = value;
        this->root_->height_    = 1;
    }
    template <typename Key, typename Value>
    Tree<Key, Value>::Tree(const Tree<Key, Value> &obj) {
        RecursiveCopy(&this->root_, obj.root_);
    }
    //End constructors
    // HEIGHT AVL TREE FUNCTIONS FOR HELP
    template<typename Node> int CheckHeightNode(Node * a){
        return a ? a->height_:0;
    }

    template<typename Node> int BalanceFactor (Node * a){ // ?? зачем нужен ? 
        return CheckHeightNode(a->left_)-CheckHeightNode(a->right_);
    }

    template<typename Node> void FixHeight(Node * a){
        a->height_=std::max(CheckHeightNode(a->left_),CheckHeightNode(a->right_))+1;
    }
    // END  HEIGHT AVL TREE FUNCTIONS FOR HELP
    template <typename Node>
    void RecursiveCopy(Node ** first, Node * seconde) {
        if(seconde != nullptr) {
            *first=new Node;
            (*first)->key_ = seconde->key_;
            (*first)->value_ = seconde->value_;
            (*first)->height_ = seconde->height_;
            RecursiveCopy(&(*first)->left_, seconde->left_);
            RecursiveCopy(&(*first)->right_, seconde->right_);
        }
    }
    
    template <typename Node>
    Node * RotateRight(Node * a){ 
        Node * b = a->left_;
        a->left_=b->right_;
        b->right_=a;
        FixHeight(a);
        FixHeight(b);
        return b;
    }

    template <typename Node>
    Node * RotateLeft(Node * a){
        Node * b = a->right_;
        a->right_=b->left_;
        b->left_=a;
        FixHeight(a);
        FixHeight(b);
        return b; 
    }

    template <typename Node>
    Node * RotateNBalance(Node * a){
        FixHeight(a);
        int bf = BalanceFactor(a);
        if(bf==2){ // влево вправо
                // puts("===Rotate 2====");
                // printf("(M)(key %d) h(%d)\n",a->key_, a->height_);
                // printf("(L)(key %d) h(%d)\n",a->left_->key_, a->left_->height_);
                // printf("(R)(key %d) h(%d)\n",a->right_->key_, a->right_->height_);
                // printf("balanceFactore %s\n",BalanceFactor(a->right_)<0?"true":"false");
                // puts("===Rotate ====");
            if(a->left_ != nullptr && BalanceFactor(a->left_)<0) a->left_=RotateLeft(a->left_); //a->right_=RotateRight(a->right_);
            a=RotateRight(a);
        }else if (bf==-2){ // вправо влево 
                // puts("===Rotate -2====");
                // printf("(M)(key %d) h(%d)\n",a->key_, a->height_);
                // printf("(L)(key %d) h(%d)\n",a->left_->key_, a->left_->height_);
                // printf("(R)(key %d) h(%d)\n",a->right_->key_, a->right_->height_);
                // printf("balanceFactore %s\n",BalanceFactor(a->left_)>0?"true":"false");
                // puts("===Rotate ====");
            if(a->right_ != nullptr && BalanceFactor(a->right_)>0)  a->right_=RotateRight(a->right_); //a->left_=RotateLeft(a->left_);
            a=RotateLeft(a);
        }
        return a;
    }

    template <typename Node, typename Key, typename Value>
    Node * MainInsert(Node * a,Key & key,Value & value){
        if (a == nullptr) {
            a=new Node;
            a->key_=key;
            a->value_=value;
        }else {
            if(a->key_ < key) {
                a->right_ =MainInsert(a->right_,key,value);
            }else if(a->key_ > key){
                a->left_  =MainInsert(a->left_,key,value);
            }
        }
        // printf("k(%d)\n",a->key_);
        return RotateNBalance(a);
    }
    template <typename Key, typename Value>
    void Tree <Key, Value>::InsObj(Key key, Value value) {
        this->root_=MainInsert(this->root_,key,value);
    }

    template <typename Node>
    void ReversDelet(Node *a) {
        if (a != nullptr) {
            ReversDelet(a->left_);
            ReversDelet(a->right_);
            delete a;
        }
    }

    template <typename Key, typename Value>
    Tree<Key, Value>::~Tree() {
        if (this->root_ != nullptr) {
            ReversDelet(this->root_);
            this->root_=nullptr;          
        }
    }
};

