#include <iostream>

#include "Account.hpp"

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts();
  std::cout << ";total:" << getTotalAmount();
  std::cout << ";deposits:" << getNbDeposits();
  std::cout << ";withdrawals:" << getNbWithdrawals();
  std::cout << '\n';
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {

  ++_nbAccounts;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << '\n';
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << '\n';
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();

  std::cout << "index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  std::cout << ";deposit:" << deposit;

  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;

  std::cout << ";amount:" << _amount;
  std::cout << ";nb_deposits:" << _nbDeposits;
  std::cout << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount << ";withdrawal:";

  if (_amount < withdrawal) {
    std::cout << "refused\n";
    return false;
  }

  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;

  std::cout << withdrawal << ";amount:";
  std::cout << _amount << ";nb_withdrawals:";
  std::cout << _nbWithdrawals;
  std::cout << '\n';

  return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";deposits:" << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals;
  std::cout << '\n';
}

void Account::_displayTimestamp(void) { std::cout << "[20150406_153629] "; }

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {}
