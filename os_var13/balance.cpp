#include "balance.hpp"
#include <iostream>

#pragma warning( disable : 26812 ) // to disable enum warning

Balance &Balance::operator=(const Balance &other) {
	money1 = other.money1;
	money2 = other.money2;
	money5 = other.money5;
	money10 = other.money10;
	money20 = other.money20;
	money50 = other.money50;
	money100 = other.money100;
	return *this;
}

void Balance::setMoneyByDenomination(const size_t _money, const size_t denomination) {
	switch (denomination) {
		case MONEY100:
			setMoney100(_money);
			break;
		case MONEY50:
			setMoney50(_money);
			break;
		case MONEY20:
			setMoney20(_money);
			break;
		case MONEY10:
			setMoney10(_money);
			break;
		case MONEY5:
			setMoney5(_money);
			break;
		case MONEY2:
			setMoney2(_money);
			break;
		case MONEY1:
			setMoney1(_money);
			break;
		default:
			break;
	}
}

size_t Balance::getMoneyByDenomination(const size_t denomination) const {
	switch (denomination) {
		case MONEY100:
			return getMoney100();
		case MONEY50:
			return getMoney50();
		case MONEY20:
			return getMoney20();
		case MONEY10:
			return getMoney10();
		case MONEY5:
			return getMoney5();
		case MONEY2:
			return getMoney2();
		case MONEY1:
			return getMoney1();
		default:
			break;
	}
	return 0;
}

bool Balance::isBalanceEmpty() const {
	return money1 == 0 && money2 == 0 && money5 == 0 && money10 == 0
		&& money20 == 0 && money50 == 0 && money100 == 0;
}

void Balance::printBalance(std::ostream &out) const {
	size_t val = 0;
	for (const auto &it : denominations) {
		val = getMoneyByDenomination(it);
		if (val > 0)
			out << "Denomination is: " << it << ";\tamount is: " << val << std::endl;
	}
	out << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Balance &bank) {
	bank.printBalance(out);
	return out;
}

Balance &Balance::operator+=(const Balance &other) {
	money1 += other.money1;
	money2 += other.money2;
	money5 += other.money5;
	money10 += other.money10;
	money20 += other.money20;
	money50 += other.money50;
	money100 += other.money100;
	return *this;
}
