# ATM
1. Develop a program that simulates the operation of a given object, using means for process access to shared resources 
synchronization. The device being modeled and the means of synchronizing processes are determined by the task.
2. Provide visualization of the model's operation with a visual demonstration results.
3. Analyze and explain the obtained results. For results work to provide conclusions about the used synchronization tools.

Model object: ATM.
The ATM accepts an application for payment of money in the amount of X, compares it with 
by the amount of money in the client's Y account and, if X<Y, makes a withdrawal attempt 
certain banknotes in denominations of 1, 2, 5, 10, 20, 50, 100 hryvnias. The values of X and Y are
random numbers The initial number of bills of different denominations in the ATM 
given by the student. If amount X is to be disbursed, the program determines whether 
you can pay this amount with currently available bills. If so -
money is issued (the number of bills available in the ATM is also adjusted 
of the corresponding denomination), if not - the ATM reports a refusal.
Requests to withdraw money arrive at the ATM one after another 
customer service (or failure).

The number of terminals and processes: The model of the automaton should be presented in the form 
two interacting processes A and B.
Process A determines the receipt of a payment claim and the opportunity 
payment of the required amount, fixes the possibility of payment.
Process B waits for the moment when it becomes necessary to make a payment and, if 
payment is possible, the required number of bills of each denomination is determined
for payment, the client's account and the amount of cash in the ATM are adjusted, leaving 
payout If payment is not possible, the client is notified.

Synchronization tools: To organize access to shared resources use mailboxes.
