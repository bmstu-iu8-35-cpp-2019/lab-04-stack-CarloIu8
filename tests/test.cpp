// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

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
