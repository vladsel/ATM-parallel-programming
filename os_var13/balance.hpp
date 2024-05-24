#pragma once

#include <vector>
#include <array>
#include <ostream>

enum moneyDenomination {
	MONEY1 = 1,
	MONEY2 = 2,
	MONEY5 = 5,
	MONEY10 = 10,
	MONEY20 = 20,
	MONEY50 = 50,
	MONEY100 = 100,
};
const std::array <moneyDenomination, 7> denominations {
	MONEY100, MONEY50, MONEY20, MONEY10, MONEY5, MONEY2, MONEY1 };

class Balance { // class to store and manipulate money
public:
	Balance() = default;
	~Balance() = default;
	Balance(const Balance &other) : money1(other.money1), money2(other.money2), money5(other.money5),
		money10(other.money10), money20(other.money20), money50(other.money50), money100(other.money100) {}
	Balance(const size_t _money1, const size_t _money2, const size_t _money5,
		 const size_t _money10, const size_t _money20, const size_t _money50, const size_t _money100
	) : money1(_money1), money2(_money2), money5(_money5), money10(_money10),
		money20(_money20), money50(_money50), money100(_money100) {}

	Balance &operator=(const Balance &other);

	void setMoney1(const size_t _money1) { money1 = _money1; }
	void setMoney2(const size_t _money2) { money2 = _money2; }
	void setMoney5(const size_t _money5) { money5 = _money5; }
	void setMoney10(const size_t _money10) { money10 = _money10; }
	void setMoney20(const size_t _money20) { money20 = _money20; }
	void setMoney50(const size_t _money50) { money50 = _money50; }
	void setMoney100(const size_t _money100) { money100 = _money100; }

	size_t getMoney1() const { return money1; }
	size_t getMoney2() const { return money2; }
	size_t getMoney5() const { return money5; }
	size_t getMoney10() const { return money10; }
	size_t getMoney20() const { return money20; }
	size_t getMoney50() const { return money50; }
	size_t getMoney100() const { return money100; }

	void setMoneyByDenomination(const size_t _money, const size_t denomination);
	size_t getMoneyByDenomination(const size_t denomination) const;

	bool isBalanceEmpty() const;
	void printBalance(std::ostream &out) const;

	friend std::ostream &operator<<(std::ostream &out, const Balance &bank);
	Balance &operator+=(const Balance &other);

private: // money amount
	size_t money1 = 0;
	size_t money2 = 0;
	size_t money5 = 0;
	size_t money10 = 0;
	size_t money20 = 0;
	size_t money50 = 0;
	size_t money100 = 0;
};
