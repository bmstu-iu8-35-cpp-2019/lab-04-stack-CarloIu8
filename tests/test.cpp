// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>
#include <vector>
TEST(stack, one) {
  stack<int> arr;
  arr.push(0);
  EXPECT_EQ(0, arr.head());
  arr.push(11);
  EXPECT_EQ(11, arr.head());
  arr.pop();
  EXPECT_EQ(0, arr.head());
  int a = 5;
  arr.push(a);
  EXPECT_EQ(5, arr.head());
}

TEST(stack2, two) { Stack<std::vector<int>> arr;
  std::vector<int> m;
  arr.push_emplace(4, 5);
  EXPECT_EQ(arr.head()[0], 5);
  EXPECT_EQ(arr.head()[3], 5);
  arr.push_emplace(3, 8);
  EXPECT_EQ(arr.head()[0], 8);
  EXPECT_EQ(arr.head()[2], 8);
  m = arr.pop();
  EXPECT_EQ(arr.head()[0], 5);
  EXPECT_EQ(arr.head()[3], 5);
}
