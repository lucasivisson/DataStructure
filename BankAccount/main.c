#include <stdio.h>
#include <stdlib.h>
#include "BankAccount.h"

int main() {
  int numberOfBankAccount = 12345;
  float initialValue = 5.50;

  BankAccount *account = newBankAccount(numberOfBankAccount, initialValue);

  depositAmount(account, 50.00);
  withdrawAmount(account, 25.00);
  printBalance(account);

  return 0;
}