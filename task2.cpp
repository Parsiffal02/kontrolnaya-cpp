//Напишите программу для управления аккаунтами пользователей. Используя один указатель на функцию, 
//реализуйте функции для добавления нового аккаунта, удаления существующего аккаунта, обновления информации об аккаунте и 
//вывода информации обо всех аккаунтах. В основной программе предложите пользователю выбрать соответствующее действие и выполните 
//операцию в соответствии с выбором пользователя.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Структура для хранения информации об аккаунте
struct Account {
    string username;
    string email;
};

// Прототипы функций
void addAccount(vector<Account>& accounts);
void deleteAccount(vector<Account>& accounts);
void updateAccount(vector<Account>& accounts);
void displayAccounts(const vector<Account>& accounts);

int main() {
    vector<Account> accounts; // Вектор для хранения аккаунтов
    int choice;

    // Указатель на функцию, который может указывать на любую из функций управления аккаунтами
    void (*accountManager)(vector<Account>&) = nullptr;

    do {
        // Меню для выбора действия
        cout << "Select an action:\\n"
             << "1. Add a new account\\n"
             << "2. Delete an existing account\\n"
             << "3. Update account information\\n"
             << "4. Display information about all accounts\\n"
             << "5. Output\\n"
            << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                accountManager = addAccount; // Установка указателя на функцию добавления аккаунта
                break;
            case 2:
                accountManager = deleteAccount; // Установка указателя на функцию удаления аккаунта
                break;
            case 3:
                accountManager = updateAccount; // Установка указателя на функцию обновления аккаунта
                break;
            case 4:
                accountManager = nullptr; // Сброс указателя на функцию
                displayAccounts(accounts); // Вывод информации обо всех аккаунтах
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0; // Выход из программы
            default:
                cout << "Wrong choice. Please try again.\\n";
                continue; // Возвращаемся к началу цикла
        }

        // Если была выбрана одна из функций управления аккаунтами (не вывод информации)
        if (accountManager != nullptr) {
            accountManager(accounts); // Вызов выбранной функции через указатель
        }
    } while (choice != 5);

    return 0;
}

// Функция для добавления нового аккаунта
void addAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "Enter the user name: ";
    cin >> newAccount.username;
    cout << "Enter your email address: ";
    cin >> newAccount.email;
    accounts.push_back(newAccount); // Добавление нового аккаунта в вектор
    cout << "Account added.\\n";
}

// Функция для удаления существующего аккаунта
void deleteAccount(vector<Account>& accounts) {
    string username;
    cout << "Enter the username to delete: ";
    cin >> username;
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->username == username) {
            accounts.erase(it); // Удаление аккаунта из вектора
            cout << "Account deleted.\\n";
            return;
        }
    }
    cout << "The account was not found.\\n";
}

// Функция для обновления информации об аккаунте
void updateAccount(vector<Account>& accounts) {
    string username;
    cout << "Enter the username for the update: ";
    cin >> username;
    for (auto& account : accounts) {
        if (account.username == username) {
            cout << "Enter a new email address: ";
            cin >> account.email; // Обновление email аккаунта
            cout << "The information has been updated.\\n";
            return;
        }
    }
    cout << "The account was not found.\\n";
}

// Функция для вывода информации обо всех аккаунтах
void displayAccounts(const vector<Account>& accounts) {
    if (accounts.empty()) {
        cout << "There are no accounts.\\n";
        return;
    }
    for (const auto& account : accounts) {
        cout << "Username: " << account.username << ", Email: " << account.email << endl;
    }
}
