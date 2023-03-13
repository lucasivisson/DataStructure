#include <stdio.h>
#include "BankAccount.h"

struct bankAccount {
  int numberOfBankAccount;
  float balance;
};

BankAccount* newBankAccount(int numberOfBankAccount, float initialValue) {
  BankAccount *account = (BankAccount *) malloc(sizeof(BankAccount));
  if(account != NULL) {
    account->balance = initialValue;
  }
  return account;
}

void depositAmount(BankAccount *account, float value) {
  account->balance += value;
}

void withdrawAmount(BankAccount *account, float value) {
  account->balance -= value;
}

void printBalance(BankAccount *account) {
  printf("%.2f\n", account->balance);
}