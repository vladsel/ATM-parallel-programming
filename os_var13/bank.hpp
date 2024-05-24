#pragma once
#include "balance.hpp"
#include "mailbox.hpp"
#include <unordered_map>

class Bank {
public:
	Bank() = default;
	~Bank() = default;
	Bank(const Balance &_balance) : balance(_balance) {}
	bool addClient(const size_t card, const double money);
	void setBalance(const Balance &_balance) { balance = _balance; }
	Balance getBalance() const { return balance; }
	void printClients() const;
private:
	friend void processA(Bank &bank, Mailbox<std::pair<size_t, double>> &mailbox);
	friend void processB(Bank &bank, Mailbox<std::pair<size_t, double>> &mailbox);
	bool checkWithdraw(const size_t card, const double money);
	size_t withdrawMoney(const size_t card, const double money);
	std::unordered_map<size_t, double> clients;
	Balance balance;
};
