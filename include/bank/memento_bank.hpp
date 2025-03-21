#pragma once

#include <memory>
#include <vector>
#include <iostream>

class Memento
{
public:
  explicit Memento(const int balance) : balance{balance} {};

private:
  int balance;

  friend class BankAccount; // Can choose to use inner class
};

class BankAccount
{
public:
  explicit BankAccount(const int balance);

  std::shared_ptr<Memento> deposit(const int amount);
  int enquire() const;
  void restore(const std::shared_ptr<Memento> m);
  std::shared_ptr<Memento> undo();
  std::shared_ptr<Memento> redo();

  friend std::ostream& operator<<(std::ostream& os, const BankAccount& obj) {
    return os << "balance: " << obj.balance;
  }

private:
  int balance;
  std::vector<std::shared_ptr<Memento>> changes;
  int current;
};

