#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "bank.hpp"

using std::cout;
using std::endl;

void processA(Bank &bank, Mailbox<std::pair<size_t, double>> &mailbox);
void processB(Bank &bank, Mailbox<std::pair<size_t, double>> &mailbox);

int main() {
	try {
		Bank bank(Balance(790, 112, 51, 33, 26, 24, 14));
		bank.addClient(1011, 10505.0);
		bank.addClient(1017, 5841.0);
		bank.addClient(1015, 100000.0);
		bank.addClient(1013, 7432.0);
		bank.addClient(1012, 7789.0);

		cout << "Initial amount of denominations in the bank" << endl;
		cout << bank.getBalance();
		cout << "All bank clients, their cards and money" << endl;
		bank.printClients();
		cout << endl;

		Mailbox<std::pair<size_t, double>> mail(3);

		std::thread procA(processA, std::ref(bank), std::ref(mail));
		std::thread procB(processB, std::ref(bank), std::ref(mail));

		if (procA.joinable())
			procA.join();
		if (procB.joinable())
			procB.join();

		cout << endl;
		cout << "Final amount of denominations in the bank" << endl;
		if (bank.getBalance().isBalanceEmpty())
			cout << "Bank is empty" << endl;
		else
			cout << bank.getBalance();
		cout << "All bank clients, their cards and money" << endl;
		bank.printClients();
		cout << endl;
		return 0;
	}
	catch (const std::exception &ex) {
		std::cerr << "main error: " << ex.what() << endl;
		return 1;	
	}
}

void processA(Bank &bank, Mailbox<std::pair<size_t, double>> &mailbox) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> sizeDist(1011, 1017);
	std::uniform_real_distribution<double> doubleDist(0.0, 500.0);
	while (true) {
		size_t randomCard = sizeDist(gen);
		double randomMoney = doubleDist(gen);
		cout << "Process |A|:" << endl;
		bool flag = bank.checkWithdraw(randomCard, randomMoney);
		if (flag)
			mailbox.send(std::make_pair(randomCard, randomMoney));
		if (bank.getBalance().isBalanceEmpty()) {
			cout << "Process |A| is finished" << endl;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void processB(Bank &bank, Mailbox<std::pair<size_t, double>> &mailbox) {
	while (true) {
		auto client = mailbox.receive();
		size_t withdraw = bank.withdrawMoney(client.first, client.second);
		cout << "Process |B|:" << endl;
		if (withdraw <= 0)
			cout << "At the moment the bank does not have the required banknote" << endl;
		else
			cout << "The amount was successfully paid: " << withdraw << endl;
		cout << "card: " << client.first << ";\tamount: " << withdraw << endl;
		cout << "The rest of money: " << endl;
		bank.printClients();
		cout << bank.getBalance();
		if (bank.getBalance().isBalanceEmpty()) {
			cout << "Process |B| is finished" << endl;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
