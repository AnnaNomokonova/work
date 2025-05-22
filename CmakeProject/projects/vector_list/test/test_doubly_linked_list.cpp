#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using mbr::DoublyLinkedList;

TEST(DoublyLinkedListTest, Destruction) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.get_size(), 0);
}

TEST(DoublyLinkedListTest, PushBack) {
    DoublyLinkedList<int> list;
    
    list.push_back(10);
    EXPECT_EQ(list.get_size(), 1);
    
    list.push_back(20);
    EXPECT_EQ(list.get_size(), 2);
    
    list.push_back(30);
    EXPECT_EQ(list.get_size(), 3);
}

TEST(DoublyLinkedListTest, HasItem) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    EXPECT_TRUE(list.has_item(10));
    EXPECT_TRUE(list.has_item(20));
    EXPECT_TRUE(list.has_item(30));
    EXPECT_FALSE(list.has_item(40));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(20);

    EXPECT_TRUE(list.remove_first(20));
    EXPECT_EQ(list.get_size(), 3);
    EXPECT_TRUE(list.has_item(20));
    
    EXPECT_TRUE(list.remove_first(10));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(10));
    
    EXPECT_TRUE(list.remove_first(30));
    EXPECT_EQ(list.get_size(), 1);
    EXPECT_FALSE(list.has_item(30));
    
    EXPECT_FALSE(list.remove_first(100));
    EXPECT_EQ(list.get_size(), 1);
}

TEST(DoublyLinkedListTest, RemoveAll) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    list.remove_first(10);
    list.remove_first(20);
    list.remove_first(30);
    
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(10));
    EXPECT_FALSE(list.has_item(20));
    EXPECT_FALSE(list.has_item(30));
}

TEST(DoublyLinkedListTest, RemoveFromEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_FALSE(list.remove_first(10));
    EXPECT_EQ(list.get_size(), 0);
}

TEST(DoublyLinkedListTest, RemoveSingleElement) {
    DoublyLinkedList<int> list;
    list.push_back(42);
    
    EXPECT_TRUE(list.remove_first(42));
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(42));
}

TEST(DoublyLinkedListTest, Print) {
    DoublyLinkedList<int> list;
    
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[]");

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    testing::internal::CaptureStdout();
    list.print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[10, 20, 30]\n");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
