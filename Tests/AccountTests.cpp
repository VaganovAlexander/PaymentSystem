#include "AccountTests.hpp"

TEST(AccountTest, Card_Test) {
  Card card("123", "Abc", "08/08", "123");
  ASSERT_EQ(card.get_number(), "123");
  ASSERT_EQ(card.get_name(), "Abc");
  ASSERT_EQ(card.get_date(), "08/08");
  ASSERT_EQ(card.get_cvv(), "123");
  ASSERT_FALSE(card.IsValid());
}

TEST(AccountTest, Account_Test) {
  Account account("abc", "123", "A", "Bc", {});
  account.AddCard({"123", "Abc", "08/08", "123"});
  account.AddCard({"", "", "", ""});
  account.DeleteCard({"", "", "", ""});
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}