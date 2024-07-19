# Transaction Simplifier

Transaction Simplifier is a C++ project designed to reduce the complexity of keeping track of transactions between multiple parties. The application allows users to add expenses, check balances, make payments, and simplify (relax) outstanding payments by detecting and resolving cycles of debt.

## Features

- **Add Transaction**: Add a transaction where a payer pays a specific amount to multiple contributors.
- **Check Expense**: View the current outstanding balances between all parties.
- **Make Payment**: Record a payment from one party to another to settle debts.
- **Relax Payments**: Simplify the outstanding payments by detecting and resolving cycles of debt.
- **Save Transactions**: Save the current state of transactions to a file for future use.
- **Load Transactions**: Load the saved transactions from a file to resume tracking.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)
- Standard Template Library (STL)

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/transaction-simplifier.git

2. Navigate to the project directory:
   ```sh
   cd transaction-simplifier

3. Compile the project:
   ```sh
   g++ -o transaction_simplifier transaction_simplifier.cpp


## Options

1. **Add Transaction**

    Enter the payer's name.
    Enter the number of contributors.
    For each contributor, enter their name and the amount they contributed.

2. **Check Expense**

    Displays all outstanding balances between parties.

3. **Make Payment**

    Enter the sender's name.
    Enter the number of receivers.
    For each receiver, enter their name and the amount paid.

4. **Relax Payments**

    Simplifies outstanding payments by detecting and resolving cycles of debt.

5. **Exit**

    Exits the application, saving the current state of transactions.

## Example

```sh
Input -
1 - Add Expense

Arvind 1
Abhay 20

2 - Show Debts

1 - Add Expense
Shivank 1
Arvind 30

2 - Show Debts

1 - Add Expense
Abhay 1
Shivank 40

2 - Show Debts
4 - Relax Transactions
2 - Show Debts
5 - Exit

Output -
Transactions :
Abhay needs to pay Arvind Rs 20.

Transactions :
Arvind needs to pay Shivank Rs 30.
Abhay needs to pay Arvind Rs 20.

Transactions : 
Arvind needs to pay Shivank Rs 30.
Abhay needs to pay Arvind Rs 20.
Shivank needs to pay Abhay Rs 40.

4: Relax payments 
Arvind needs to pay Shivank Rs 10.
Shivank needs to pay Abhay Rs 20.
```

## Contributing

1. Fork the repository.
2. Create a new branch:
    ```sh
    git checkout -b feature-name
    ```
3. Make your changes and commit them:
    ```sh
    git commit -m 'Add some feature'
    ```
4. Push to the branch:
    ```sh
    git push origin feature-name
    ```
5. Submit a pull request.


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

