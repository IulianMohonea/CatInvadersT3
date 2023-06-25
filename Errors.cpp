#include "Errors.h"
playerErrors::playerErrors(std::string& mesaj) :
Errors( std::string ("Miscare invalida: ") + mesaj + '\n') {}

fireErrors::fireErrors(std::string& mesaj) :
Errors(std::string("Timp prea putin intre gloante: ") + mesaj + '\n') {}