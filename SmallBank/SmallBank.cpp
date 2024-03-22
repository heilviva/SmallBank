#include <iostream>
#include <cctype>

class BankAccount {
private:
	int accountNumber;
	double balance;
	double interestRate;

public:
	BankAccount(int accNum, double initialBalance) {
		accountNumber = accNum;
		balance = initialBalance;
		interestRate = 0.0;
	}

		void deposit(double amount) {
		balance += amount;
	}

	bool withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
			return true;
		}
		else {
			std::cout << "Ошибка: Недостаточно средств" << std::endl;
			return false;
		}
	}

	double getBalance() {
		return balance;
	}

	double getInterest() {
		return balance * interestRate * (1.0 / 12);
	}

	void setInterestRate(double rate) {
		interestRate = rate;
	}

	int getAccountNumber() {
		return accountNumber;
	}

	friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
	if (from.balance >= amount) {
		from.balance -= amount;
		to.balance += amount;
		return true;
	}
	else {
		std::cout << "Ошибка: Недостаточно средств для перевода" << std::endl;
		return false;
	}
}

bool onlyDigits(const std::string& input) {//эту функцию я не использовала для проверки ошибки на дурака, потому что много писать, но оставлю здесь чтобы Вы посмотрели как пример
	for (char c : input) {
		if (std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main() {
	int accNum1, accNum2;
	double initialBalance1, initialBalance2, interestRate1, interestRate2;
	
	std::cout << "Введите номер счета для Счета 1: ";
	std::cin >> accNum1;
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Введите начальный баланс для Счета 1:  ";
	std::cin >> initialBalance1;
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Введите номер счета для Счета 2: ";
	std::cin >> accNum2;
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Введите начальный баланс для Счета 2: ";
	std::cin >> initialBalance2;
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	BankAccount acc1(accNum1, initialBalance1);
	BankAccount acc2(accNum2, initialBalance2);

	double depositAmount, withdrawAmount;
	std::cout << "Введите сумму для внесения на Счет 1: ";
	std::cin >> depositAmount;
	acc1.deposit(depositAmount);
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Введите сумму для снятия со Счета 2: ";
	std::cin >> withdrawAmount;
	acc2.withdraw(withdrawAmount);
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Баланс Счета 1: " << acc1.getBalance() << std::endl;
	std::cout << "Баланс Счета 2: " << acc2.getBalance() << std::endl;

	std::cout << "Введите процентную ставку для аккаунта 2: ";
	std::cin >> interestRate2;
	acc2.setInterestRate(interestRate2);
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Проценты аккаунта 1: " << acc1.getInterest() << std::endl;
	std::cout << "Проценты ставка аккаунта 2: " << acc2.getInterest() << std::endl;


	double transferAmount;
	std::cout << "Введите сумму для перевода со счета 1 на счет 2: ";
	std::cin >> transferAmount;
	transfer(acc1, acc2, transferAmount);
	if (std::cin.fail()) {
		std::cout << "Ошибка. Введите пожалуйста только цифры." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::cout << "Аккаунт 1 после перевода: " << acc1.getBalance() << std::endl;
	std::cout << "Аккаунт 2 после перевода: " << acc2.getBalance() << std::endl;

	return 0;
}