#include "Library.h"

std::string Library::public_str = "public string";
std::string Library::protected_str_ = "protected string";
std::string Library::private_str_ = "private string";

Library::Library() : name_("") {}

Library::~Library() {}

void Library::setName(std::string name) {name_ = name;}

std::string Library::name() {return name_;}
