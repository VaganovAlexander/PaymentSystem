#include <string>
#include <vector>
#include <stdexcept>

class Card {
 private:
  std::string card_number;
  std::string cardholder_name;
  std::string expire_date;
  std::string cvv_code;

 public:
  Card() noexcept = default;
  ~Card() = default;
  Card(const std::string& card_number, const std::string& cardholder_name,
       const std::string& expire_date, const std::string& cvv_code) noexcept;
  Card(std::string&& card_number, std::string&& cardholder_name,
       std::string&& expire_date, std::string&& cvv_code) noexcept;
  Card(const Card& other) noexcept = default;
  Card(Card&& other) noexcept = default;
  Card& operator=(const Card& other) noexcept = default;
  Card& operator=(Card&& other) noexcept = default;
  bool operator==(const Card& other) const;
};

class Account {
 public:
  Account() noexcept = default;
  ~Account() = default;
  Account(const std::string& username, const std::string& password,
          const std::string& first_name, const std::string& second_name,
          const std::vector<Card>& cards) noexcept;
  Account(std::string&& username, std::string&& password,
          std::string&& first_name, std::string&& second_name,
          std::vector<Card>&& cards) noexcept;
  Account(const Account& other) noexcept = default;
  Account(Account&& other) noexcept = default;
  Account& operator=(const Account& other) noexcept = default;
  Account& operator=(Account&& other) noexcept = default;
  void AddCard(const Card& card);
  void DeleteCard(const Card& card);

 private:
  std::string username;
  std::string password;
  std::string first_name;
  std::string second_name;
  std::vector<Card> cards;
};