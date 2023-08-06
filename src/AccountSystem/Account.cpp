#include "Account.hpp"

Card::Card(const std::string& card_number, const std::string& cardholder_name,
           const std::string& expire_date, const std::string& cvv_code)
    : card_number(card_number),
      cardholder_name(cardholder_name),
      expire_date(expire_date),
      cvv_code(cvv_code) {}

Card::Card(std::string&& card_number, std::string&& cardholder_name,
           std::string&& expire_date, std::string&& cvv_code)
    : card_number(std::move(card_number)),
      cardholder_name(std::move(cardholder_name)),
      expire_date(std::move(expire_date)),
      cvv_code(std::move(cvv_code)) {}

bool Card::operator==(const Card& other) const {
  return card_number == other.card_number&& 
         cardholder_name == other.cardholder_name&& 
         expire_date == other.expire_date&&  cvv_code == other.cvv_code;
}

Account::Account(const std::string& username, const std::string& password,
                 const std::string& first_name, const std::string& second_name,
                 const std::vector<Card>& cards)
    : username(username),
      password(password),
      first_name(first_name),
      second_name(second_name),
      cards(cards) {}

Account::Account(std::string&& username, std::string&& password,
                 std::string&& first_name, std::string&& second_name,
                 std::vector<Card>&& cards)
    : username(std::move(username)),
      password(std::move(password)),
      first_name(std::move(first_name)),
      second_name(std::move(second_name)),
      cards(std::move(cards)) {}

void Account::AddCard(const Card& card) {
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