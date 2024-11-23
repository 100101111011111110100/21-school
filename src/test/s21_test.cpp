#include "s21_test.h"





TEST(s21_AVL_Tree, default_constructor_01) {
    s21::Tree<int, int> a;
    EXPECT_EQ(a.getNode(), nullptr);
}

TEST(s21_AVL_Tree, default_constructor_02) {
    s21::Tree<int, int> a(1,2);
    EXPECT_EQ(a.getNode()->key_, 1);
    EXPECT_EQ(a.getNode()->value_, 2);
    EXPECT_EQ(a.getNode()->height_, 1);
    EXPECT_EQ(a.getNode()->left_, nullptr);
    EXPECT_EQ(a.getNode()->right_, nullptr);
    // EXPECT_EQ(a.getNode()->parent_, nullptr);
    a.~Tree();
    EXPECT_EQ(a.getNode(), nullptr);
}

TEST(s21_AVL_Tree, default_constructor_03) {
    s21::Tree<int, int> a(1,2);
    // s21::Tree<int, int> b(2,3);
    EXPECT_EQ(a.getNode()->key_, 1);
    EXPECT_EQ(a.getNode()->value_, 2);
    EXPECT_EQ(a.getNode()->height_, 1);
    EXPECT_EQ(a.getNode()->left_, nullptr);
    EXPECT_EQ(a.getNode()->right_, nullptr);
    // EXPECT_EQ(a.getNode()->parent_, nullptr);

    a.InsObj(2, 3);
    // EXPECT_EQ(a.getNode(), a.getNode()->right_->parent_);
    a.~Tree();
    EXPECT_EQ(a.getNode(), nullptr);
}
TEST(s21_AVL_TREE, copy_constructor_01) {
    s21::Tree<int, int> a(1,2);
    s21::Tree<int, int> b(a);
    EXPECT_EQ(b.getNode()->key_, 1);
    EXPECT_EQ(b.getNode()->value_, 2);
    EXPECT_EQ(b.getNode()->height_, 1);
    EXPECT_EQ(b.getNode()->left_, nullptr);
    EXPECT_EQ(b.getNode()->right_, nullptr);
    // EXPECT_EQ(b.getNode()->parent_, nullptr);
    a.~Tree();
    EXPECT_EQ(a.getNode(), nullptr);
    b.~Tree();
    EXPECT_EQ(b.getNode(), nullptr);
}

TEST(s21_AVL_TREE, InsertObject_01) {
    s21::Tree<int, int> a(1,2);
    for(int i=1;i<8;i++){
        a.InsObj(i, 3);
        // a.PrintTree(a.getNode());
        // puts("```");   
    }
    EXPECT_EQ(a.getNode()->key_,4);
    EXPECT_EQ(a.getNode()->left_->key_,2);
    EXPECT_EQ(a.getNode()->left_->left_->key_,1);
    EXPECT_EQ(a.getNode()->left_->right_->key_,3);
    EXPECT_EQ(a.getNode()->right_->key_,6);
    EXPECT_EQ(a.getNode()->right_->left_->key_,5);
    EXPECT_EQ(a.getNode()->right_->right_->key_,7);
    a.~Tree();
    EXPECT_EQ(a.getNode(), nullptr);
}

TEST(s21_AVL_TREE, InsertObject_02) {
    s21::Tree<int, int> a(9,2);
    int array[]={17,20,16,12,21,6};
    for(int i=0;i<6;i++){
        a.InsObj(array[i], 3);
        // a.PrintTree(a.getNode());
        // puts("```");   
    }
    EXPECT_EQ(a.getNode()->key_,17);
    EXPECT_EQ(a.getNode()->left_->key_,12);
    EXPECT_EQ(a.getNode()->right_->key_,20);
    EXPECT_EQ(a.getNode()->left_->left_->key_,9);
    EXPECT_EQ(a.getNode()->left_->right_->key_,16);
    EXPECT_EQ(a.getNode()->left_->left_->left_->key_,6);
    EXPECT_EQ(a.getNode()->right_->right_->key_,21);
    a.~Tree();
    EXPECT_EQ(a.getNode(), nullptr);
}

TEST(s21_AVL_TREE, DeleteObject_01) {
    s21::Tree<int, int> a(1,2);
    for(int i=2;i<9;i++){
        a.InsObj(i, 3);
        // a.PrintTree(a.getNode());
        // puts("```");   
    }
    a.PrintTree(a.getNode());
        puts("```");  
    a.Remove(6);
    a.PrintTree(a.getNode());
        puts("```");  
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}