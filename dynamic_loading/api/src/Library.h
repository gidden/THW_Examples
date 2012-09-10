#include <string>

class Library {
 public:
  Library();
  virtual ~Library();

  void setName(std::string name);

  std::string name();

  static std::string public_str;

 protected:
  static std::string protected_str_;

 private:
  static std::string private_str_;
  std::string name_;
};
