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
void translate_cesar_file(FILE *file_input, FILE *file_output, char *line) {
  unsigned int count = 1;
  while (fgets(line, MAX_CHARACTERS_FOR_LINE * sizeof(char), file_input)) {
    destroy_line_jump(line);
    print_line(line, count);
    translate_cesar_line(line);
    fputs(line, file_output);
    if (line)
      fputc('\n', file_output);
    fprintf(stdout, "%s\n", line);
    ++count;
  }
}

void print_line(char *line, unsigned int count) {
  fprintf(stdout, MSG_ORIGINAL_FILE, count);
  fprintf(stdout, "%s\n", line);
  fprintf(stdout, MSG_TRANSLATED_FILE, count);
}

void print_separator(void) { fprintf(stdout, LINE_SEPARATOR); }

void print_welcome_msg(void) {
  print_separator();
  fprintf(stdout, MSG_WELCOME);
  print_separator();
}

void print_success_msg(void) {
  fprintf(stdout, MSG_SUCCESS);
  print_separator();
}

void print_end_success_msg(char *input_file, char *output_file) {
  print_separator();
  fprintf(stdout, MSG_IS_TRANSLATED, input_file, output_file);
  print_separator();
  fprintf(stdout, MSG_END);
  print_separator();
}

void print_end_err_msg_doesnt_exist(char *input_file, char *output_file) {
  print_separator();
  fprintf(stderr, ERR_MSG_DOESNT_EXIST, input_file);
  fprintf(stderr, ERR_MSG_NOT_TRANSLATED, input_file, output_file);
  print_separator();
  fprintf(stderr, ERR_MSG_END);
  print_separator();
}

void print_end_err_msg_empty(char *input_file, char *output_file) {
  print_separator();
  fprintf(stderr, ERR_MSG_NOT_TRANSLATED, input_file, output_file);
  print_separator();
  fprintf(stderr, ERR_MSG_END);
  print_separator();
}

void destroy_line_jump(char *line) {
  for (unsigned int i = 0; i < strlen(line); i++) {
    if (line[i] == '\n')
      line[i] = ' ';
  }
}

  }

  return is_letter;
}

char *translate_cesar_line(char line[]) {
  for (unsigned int i = 0; i < strlen(line); i++) {
    if (is_letter(line[i]) && is_letter(line[i] - 3)) {
      line[i] = line[i] - 3;
    } else if (is_letter(line[i]) && !is_letter(line[i] - 3)) {
      line[i] = (line[i] - 3) + ALPHABET_NUMBER;
    }
  }
  return line;

  return buffer;
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