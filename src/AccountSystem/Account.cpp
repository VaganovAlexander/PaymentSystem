#include "Account.hpp"
#include <iostream>

Card::Card(const std::string& card_number_new, const std::string& cardholder_name_new,
           const std::string& expire_date_new, const std::string& cvv_code_new) noexcept { 
  try {
    card_number = card_number_new;
    cardholder_name = cardholder_name_new;
    expire_date = expire_date_new;
    cvv_code = cvv_code_new;
    if (!IsValid()) {
      throw std::invalid_argument("Card is not valid!");
    }
  } catch (...) {
    this->~Card();
    // In frontend make an error window.
  }
}

Card::Card(std::string&& card_number_new, std::string&& cardholder_name_new,
           std::string&& expire_date_new, std::string&& cvv_code_new) noexcept { 
  try {
    card_number = std::move(card_number_new);
    cardholder_name = std::move(cardholder_name_new);
    expire_date = std::move(expire_date_new);
    cvv_code = std::move(cvv_code_new);
    if (!IsValid()) {
      std::cout << "NOT VALID!" << "\n";
      throw std::invalid_argument("Card is not valid!");
    }
  } catch (...) {
    std::cout << "Catched!" << "\n";
    this->~Card();
    // In frontend make an error window.
  }
}

bool Card::operator==(const Card& other) const {
  return card_number == other.card_number&& 
         cardholder_name == other.cardholder_name&& 
         expire_date == other.expire_date&&  cvv_code == other.cvv_code;
}

bool Card::IsValid() const {
  int sum = 0;
  int parity = card_number.size() % 2;
  for (int i = 0; i < card_number.size(); ++i) {
    if (i % 2 != parity) {
      sum += (card_number[i] - '0');
    } else if ((card_number[i] - '0') > 4) {
      sum += 2 * (card_number[i] - '0') - 9;
    } else {
      sum += 2 * (card_number[i] - '0');
    }
  }
  return card_number[card_number.size() - 1] == (10 - (sum % 10));
}

std::string Card::get_number() const {
  return card_number;
}

std::string Card::get_name() const {
  return cardholder_name;
}

std::string Card::get_date() const {
  return expire_date;
}

std::string Card::get_cvv() const {
  return cvv_code;
}

Account::Account(const std::string& username, const std::string& password,
                 const std::string& first_name, const std::string& second_name,
                 const std::vector<Card>& cards) noexcept
    : username(username),
      password(password),
      first_name(first_name),
      second_name(second_name),
      cards(cards) {}

Account::Account(std::string&& username, std::string&& password,
                 std::string&& first_name, std::string&& second_name,
                 std::vector<Card>&& cards) noexcept
    : username(std::move(username)),
      password(std::move(password)),
      first_name(std::move(first_name)),
      second_name(std::move(second_name)),
      cards(std::move(cards)) {}

void Account::AddCard(const Card& card) {
  if (!card.IsValid()) {
    return;
  }
  try {
    for (auto iter = cards.begin(); iter < cards.end(); ++iter) {
      if (*iter == card) {
        throw std::runtime_error("There is such card!");
      }
    }
    cards.push_back(card);
  } catch (...) {
    // In frontend make some error window.
  }
}

void Account::DeleteCard(const Card& card) {
  try {
    for (auto iter = cards.begin(); iter < cards.end(); ++iter) {
      if (*iter == card) {
        cards.erase(iter);
        return;
      }
    }
    throw std::runtime_error("There is no such card!");
  } catch (...) {
    // In frontend make some error window.
  }
}