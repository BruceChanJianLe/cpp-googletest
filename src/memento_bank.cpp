#include "bank/memento_bank.hpp"

BankAccount::BankAccount(const int balance)
  : balance{balance}
  , changes{}
  , current{0}
{
  changes.emplace_back(std::make_shared<Memento>(balance));
}

std::shared_ptr<Memento> BankAccount::deposit(const int amount)
{
  balance += amount;
  auto m = std::make_shared<Memento>(balance);
  changes.push_back(m);
  ++current; // Increment index of changes
  return m;
}

int BankAccount::enquire() const
{
  return balance;
}

void BankAccount::restore(const std::shared_ptr<Memento> m)
{
  if (m) {
    balance = m->balance;
    changes.emplace_back(m);
    current = changes.size() - 1;
  }
}

std::shared_ptr<Memento> BankAccount::undo()
{
  // Sanity check
  if (current > 0) {
    --current;;
    auto m = changes[current];
    balance = m->balance;
    return m;
  }
  return nullptr;
}

std::shared_ptr<Memento> BankAccount::redo()
{
  if (current + 1 < changes.size()) {
    ++current;
    auto m = changes[current];
    balance = m->balance;
    return m;
  }
  return nullptr;
}
