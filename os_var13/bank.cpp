#include "bank.hpp"
#include <iostream>

using std::cout;
using std::endl;

bool Bank::addClient(const size_t card, const double money) {
	if (money < 0.0 || clients.find(card) != clients.end())
		return false;
	clients.insert(std::make_pair(card, money));
	return true;
}

void Bank::printClients() const {
	for (const auto &val : clients)
		cout << "card: " << val.first << ";\tbalance: " << val.second << endl;
}

bool Bank::checkWithdraw(const size_t card, const double money) {
	auto client = clients.find(card);
	if (client == clients.end())
		cout << "There is no client with a card: " << card << endl;
	else if (balance.isBalanceEmpty())
		cout << "There is no money in the bank" << endl;
	else if (money > (*client).second)
		cout << "There is not enough money on your card: " << card << endl;
	else if (money <= 0.0)
		cout << "You cannot withdraw an amount less than or equal to zero" << endl;
	else {
		cout << "Your request has been submitted for processing" << endl
			<< "card: " << card << ";\tamount: " << money << endl;
		return true;
	}
	return false;
}

size_t Bank::withdrawMoney(const size_t card, const double money) {
	size_t amount = 0;
	double countMoney = money;
	for (const auto &it : denominations)
		while (balance.getMoneyByDenomination(it) > 0 && countMoney >= static_cast<double>(it)) {
			amount += static_cast<size_t>(it);
			countMoney -= static_cast<double>(it);
			balance.setMoneyByDenomination(balance.getMoneyByDenomination(it) - 1, it);
		}
	(*clients.find(card)).second -= money - countMoney;
	return amount;
}
