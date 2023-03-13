typedef struct bankAccount BankAccount;

BankAccount* newBankAccount(int numberOfBankAccount, float initialValue);

void depositAmount(BankAccount *account, float value);

void withdrawAmount(BankAccount *account, float value);

void printBalance(BankAccount *account);