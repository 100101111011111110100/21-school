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
    a.InsObj(2, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(3, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(4, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(5, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(6, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(7, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(8, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(9, 3);
    a.PrintTree(a.getNode());
    puts("```");
    a.InsObj(10, 3);
    a.PrintTree(a.getNode());
    puts("```");
    // a.InsObj(3, 3);
    // EXPECT_EQ(a.getNode()->key_, 1);
    // EXPECT_EQ(a.getNode()->value_, 2);
    // EXPECT_EQ(a.getNode()->height_, 1);
    // EXPECT_EQ(a.getNode()->left_, nullptr);
    // EXPECT_EQ(a.getNode()->right_->key_,2);
    // EXPECT_EQ(a.getNode()->right_->value_,3);
    // EXPECT_EQ(a.getNode()->right_->right_->key_,3);
    // EXPECT_EQ(a.getNode()->right_->right_->value_,3);
    // a.~Tree();
    // EXPECT_EQ(a.getNode(), nullptr);
}

// TEST(s21_AVL_TREE, copy_constructor_02) {
//     s21::Tree<int, int> a(1,2);
//     a.InsObj(2, 3);
//     a.InsObj(3, 3);
//     s21::Tree<int, int> b(a);
//     EXPECT_EQ(b.getNode()->key_, 1);
//     EXPECT_EQ(b.getNode()->value_, 2);
//     EXPECT_EQ(b.getNode()->height_, 1);
//     EXPECT_EQ(b.getNode()->left_, nullptr);
//     EXPECT_EQ(b.getNode()->right_->key_,2);
//     EXPECT_EQ(b.getNode()->right_->value_,3);
//     EXPECT_EQ(b.getNode()->right_->right_->key_,3);
//     EXPECT_EQ(b.getNode()->right_->right_->value_,3);
//     a.~Tree();
//     EXPECT_EQ(a.getNode(), nullptr);
//     b.~Tree();
//     EXPECT_EQ(b.getNode(), nullptr);
// }

// TEST(s21_AVL_TREE,rebalance) {
//     s21::Tree<int, int> a(2,2);
//     a.PrintTree(a.getNode());
//     a.InsObj(1, 3);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(8, 4);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(6, 5);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(5, 3);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(7, 3);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(9, 3);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.~Tree();
//     EXPECT_EQ(a.getNode(), nullptr);
// }

// TEST(s21_AVL_TREE,rebalance) {
//     s21::Tree<int, int> a(2,2);
//     a.PrintTree(a.getNode());
//     a.InsObj(1, 3);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(4, 4);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(3, 5);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.InsObj(5, 3);
//     printf("========\n");
//     a.PrintTree(a.getNode());
//     a.~Tree();
//     EXPECT_EQ(a.getNode(), nullptr);
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}