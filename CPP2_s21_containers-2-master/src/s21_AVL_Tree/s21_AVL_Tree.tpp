#include "s21_AVL_Tree.hpp"

namespace s21 {

    
    // Print
    #ifdef DEBUG
    template<typename Key, typename Value>
      void Tree<Key,Value>::Print(Node * root){
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
            Print(root->left_);
        } 
        if(root->right_ != nullptr){
            Print(root->right_);
        } 
    }
    template<typename Key, typename Value>
        void Tree<Key,Value>::PrintTree(){
            Print(this->root_);
        }
    #endif
    //Constructors
    template <typename Key, typename Value> 
        typename Tree<Key,Value>::Node * Tree<Key,Value>::getNode(){
            return this->root_;
        }
    // template <typename Key, typename Value>
    // Tree<Key, Value>::Tree(Key key, Value value) {

    // }
    template <typename Key, typename Value>
    Tree<Key, Value>::Tree(){
        this->root_ = nullptr;
    }
    template <typename Key,typename Value>
    Tree<Key, Value>::Tree(std::initializer_list<value_type> const &items){
        for(auto it=items.begin();it!=items.end();it++){
            InsObj(it->first, it->second);
        }
    }
    template <typename Key, typename Value>
    Tree<Key, Value>::Tree(const Tree<Key, Value> &obj) { //copy constructor
        RecursiveCopy(&this->root_, obj.root_);
    }
    //End constructors
    template <typename Key, typename Value>
    Tree<Key,Value> & Tree<Key,Value>::operator=(const Tree<Key,Value> & obj){
        this->~Tree();
        RecursiveCopy(&this->root_, obj.root_);
        return *this;
    }

    //HEIGHT AVL TREE FUNCTIONS FOR HELP
    template<typename Node> int CheckHeightNode(Node * a){
        return a ? a->height_:0;
    }

    template<typename Node> int BalanceFactor (Node * a){ 
        return CheckHeightNode(a->left_)-CheckHeightNode(a->right_);
    }

    template<typename Node> void FixHeight(Node * a){
        a->height_=std::max(CheckHeightNode(a->left_),CheckHeightNode(a->right_))+1;
    }
    //END  HEIGHT AVL TREE FUNCTIONS FOR HELP
    
    template <typename Node>
    void RecursiveCopy(Node ** first, Node * seconde) {
        if(seconde != nullptr) {
            *first=new Node;
            (*first)->key_ = seconde->key_;
            (*first)->value_ = seconde->value_;
            (*first)->height_ = seconde->height_;
            RecursiveCopy(&(*first)->left_, seconde->left_);
            if((*first)->left_ != nullptr) (*first)->left_->parent_ = *first;
            RecursiveCopy(&(*first)->right_, seconde->right_);
            if((*first)->right_ != nullptr) (*first)->right_->parent_ = *first;
        }
    }
    
    template <typename Node>
    void RotateParent(Node * a, Node * b){
        if(b != nullptr) {
            Node * temp = a->parent_;
            b->parent_=temp;
            a->parent_=b;
        }
    }

    template <typename Node>
    Node * RotateRight(Node * a){ 
        Node * b = a->left_;
        a->left_=b->right_;
        if(b->right_ != nullptr) b->right_->parent_=&(*a);
        b->right_=a;
        RotateParent(a,b);
        FixHeight(a);
        FixHeight(b);
        return b;
    }

    
    template <typename Node>
    Node * RotateLeft(Node * a){
        Node * b = a->right_;
        a->right_=b->left_;
        if(b->left_ != nullptr) b->left_->parent_=&(*a);
        b->left_=a;
        RotateParent(a,b);
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
            a             = new Node;
            a->key_       = key;
            a->value_     = value;
            a->height_    = 1;
            a->left_      = nullptr;
            a->right_     = nullptr;
            a->parent_    = nullptr;
        }else {
            if(a->key_ < key) {
                a->right_ =MainInsert(a->right_,key,value);
                a->right_->parent_=a;
            }else if(a->key_ > key){
                a->left_  =MainInsert(a->left_,key,value);
                a->left_->parent_=a;
            }
        }
        return RotateNBalance(a);
    }
    template <typename Key, typename Value>
    void Tree <Key, Value>::InsObj(Key key, Value value) {
        this->root_=MainInsert(this->root_,key,value);
    }
    template <typename Node>
    Node * FindMin(Node * a){
        return a->left_?FindMin(a->left_):a;
    }
    template <typename Node>
    Node * RemoveMin(Node * a){
        if(a->left_ == nullptr){
            return a->right_;
        }else{
            a->left_=RemoveMin(a->left_);
        }
        return RotateNBalance(a);
    }
    template <typename Node,typename Key>
    Node * MainRemove(Node * a,Key key){
        if(a == nullptr)     return nullptr;
        if(key<a->key_){
            a->left_=MainRemove(a->left_,key);
        }else if (key > a->key_){
            a->right_=MainRemove(a->right_,key);
        }else{
            Node * b = a->left_;
            Node * c = a->right_;
            Node * a_parent=a->parent_;
            delete a;
            a = FindMin(c);
            a->right_= RemoveMin(c);
            a->parent_=a_parent;
            if(a->right_ != nullptr) a->right_->parent_=&(*a);
            a->left_ = b;
            if(a->left_ != nullptr) a->left_->parent_=&(*a);
        }
        return RotateNBalance(a);
    }
    template <typename Key,typename Value>
    void Tree <Key, Value>::Remove(Key key){
        this->root_ = MainRemove(this->root_,key);
    }

    template <typename Node>
    void ReversDelete(Node *a) {
        if (a != nullptr) {
            ReversDelete(a->left_);
            ReversDelete(a->right_);
            delete a;
        }
    }

    template <typename Key, typename Value>
    Tree<Key, Value>::~Tree() {
        if (this->root_ != nullptr) {
            ReversDelete(this->root_);
            this->root_=nullptr;          
        }
    }

    template <typename Key, typename Value, typename Node>
    Node * Tree<Key,Value>::findNode(const Key & key){
        Node * tmpPtr = this->root_;
        while (tmpPtr != nullptr && tmpPtr->key_ != key) {
            if(tmpPtr->key_ < key) tmpPtr=tmpPtr->right_;
            else tmpPtr=tmpPtr->left_;
        }
        return tmpPtr;
    }

};

