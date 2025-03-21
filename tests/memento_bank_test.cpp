#include "bank/memento_bank.hpp"
#include "gtest/gtest.h"
#include <memory>

struct States
{
  int initial_balance;
  std::vector<int> deposits;
};

struct MementoBankTest : public testing::TestWithParam<States>
{
  std::unique_ptr<BankAccount> ba;
};

TEST_P(MementoBankTest, UndoRedoTest)
{
  auto as = GetParam();
  ba = std::make_unique<BankAccount>(as.initial_balance);
  for (const auto& deposit : as.deposits) {
    ba->deposit(deposit);
  }

  ba->undo();
  ba->undo();
  ba->redo();

  EXPECT_EQ(ba->enquire(), as.initial_balance + as.deposits.front());
}

INSTANTIATE_TEST_SUITE_P(Default, MementoBankTest,
    testing::Values(
      States{100, {50, 25}}
    ));
