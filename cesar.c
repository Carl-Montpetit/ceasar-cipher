/**
 * @file cesar.c
 * @author Carl Montpetit (MONC08069000)
 * @brief implementation of a program that provides the functionality to
 * translate texte encrypted with the encryption of Cesar (with a shift of +3
 * for the TP)
 * @version 1.0
 * @date 2021-10-20
 * @date remise: 14 novembre 2021 avant 23:59
 *
 * @copyright Copyright (c) 2021
 * TODO [x] 3 white spaces indent
 * TODO [x] max 10 lines functions
 * TODO [x] follow the modulation standard (.h & .c)
 * TODO [] system error gestion (io, try/catch, etc)
 * TODO [x] function & variables ➡︎ snake_case
 * TODO [] cover well the code with tests (bats)
 * TODO [] code lisibility = amazing!
 * TODO [x] CI integration wih gitlab
 * TODO [] no compilation error at start-up (-Wall)
 * TODO [] test on Uqam server ➡︎ ssh java.labunix.uqam.ca
 * TODO [] complete the make file
 * TODO [] README.md is completed
 *
 */

#include "cesar.h"
//------------------------------------------------------------------------------
// ∀functions definitions
//
// ASCII code of A-Z ➡︎ [65,90] & a-z ➡︎ [97,122]
// +3 for cesar encryption of the TP
//------------------------------------------------------------------------------
bool is_letter(char cesar_character) {
  bool is_letter = false;

  if ((cesar_character >= 65 && cesar_character <= 90) ||
      (cesar_character >= 97 && cesar_character <= 122)) {
    is_letter = true;
  }

  return is_letter;
}

//------------------------------------------------------------------------------
// ☆ STARTING POINT FOR PROGRAM EXECUTION ☆
// Exit code value = 0 if there's no error
// otherwise, exit code value takes a value → x∈ℕ\{0}
//
//------------------------------------------------------------------------------
int main(int argumentsNumber, char *argumentsList[]) { 
  // argumentsList[0] ➡︎ executable
  // argumentsList[1] ➡︎ intput_file
  // argumentsList[2] ➡︎ output_file

  return 1; 
  }