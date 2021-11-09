/**
 * @file cesar.c
 * @author Carl Montpetit (MONC08069000)
 * @brief Implementation of a program that provides the functionality to
 * translate text encrypted with the encoding of Cesar (with a shift of +3).
 * It takes a file encrypted and write the translation in an other file
 * @see https://en.wikipedia.org/wiki/Caesar_cipher
 * @version 1.0
 * @date 2021-10-20
 * @date Remise ⟾ 14 novembre 2021 avant 23:59
 *
 * @copyright Copyright (c) 2021
 *
 * ☆ ✅ TODO-LIST FOR THE PROJECT ⬇︎ ☆
 * TODO [x] 3 white spaces indent
 * TODO [x] max 10 lines functions
 * TODO [x] follow the modulation standard (.h & .c)
 * TODO [x] function & variables ➡︎ snake_case🐍
 * TODO [x] code lisibility = amazing!
 * TODO [x] CI integration wih gitlab
 * TODO [x] no compilation error at start-up (-Wall)
 * TODO [x] 80 characters maximum in file translation
 * TODO [] test on Uqam server ➡︎ ssh java.labunix.uqam.ca
 * TODO [] complete the make file
 * TODO [] README.md is completed
 * TODO [] cover well the code with tests (bats)
 * TODO [] system error gestion (io, try/catch, etc)
 */
//------------------------------------------------------------------------------
// ☆ INCLUSION(S) ☆
//------------------------------------------------------------------------------
#include "cesar.h"
//------------------------------------------------------------------------------
// ☆ ∀FUNCTIONS DEFINITIONS ☆
//
// ASCII code of A-Z ⇋ [65,90] & a-z ⇋ [97,122] ⟿ Inclusive intervals
// +3 for cesar cypher encoding of the TP ⇋ -3 for translation of cesar cypher
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

bool file_is_empty(char *input_file) {
  bool is_empty = false;
  if (get_size_file(input_file) == 0) {
    fprintf(stderr, ERR_MSG_FILE_EMPTY, input_file);
    is_empty = true;
  } else {
    fprintf(stdout, MSG_SIZE, get_size_file(input_file));
  }
  return is_empty;
}

bool is_letter(const char character) {
  bool is_letter = false;
  if ((character >= 65 && character <= 90) ||
      (character >= 97 && character <= 122)) {
    is_letter = true;
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
}

unsigned int get_size_file(char *file_name) {
  unsigned int size = 0;
  FILE *file = fopen(file_name, "r");
  if (file != NULL) {
    fseek(file, 0, SEEK_END);
    size = ftell(file);
  }
  fclose(file);
  return size;
}
//------------------------------------------------------------------------------
// ☆ STARTING POINT FOR PROGRAM EXECUTION ☆
//
// Exit code value = 0 if there's no error
// Otherwise, exit code value takes a value in x ∈ ℕ\{0}, where x is the code
// error
//------------------------------------------------------------------------------
int main(int number_of_arguments, char *list_of_arguments[]) {
  print_welcome_msg();
  if (number_of_arguments <= 2) {
    fprintf(stderr, ERR_MSG_NO_ARGS);
    exit(ERR_NO_ARGS);
  }
  char line[MAX_CHARACTERS_FOR_LINE];
  FILE *file_input, *file_output;

  file_input = fopen(INPUT_FILE, "r");
  file_output = fopen(OUTPUT_FILE, "w");

  if (file_input == NULL) {
    print_end_err_msg_doesnt_exist(INPUT_FILE, OUTPUT_FILE);
    exit(ERR_FILE_DOESNT_EXIST);
  }

  if (file_is_empty(INPUT_FILE)) {
    print_end_err_msg_empty(INPUT_FILE, OUTPUT_FILE);
    exit(ERR_FILE_EMPTY);
  }
  print_success_msg();

  translate_cesar_file(file_input, file_output, line);

  fclose(file_input);
  fclose(file_output);

  print_end_success_msg(INPUT_FILE, OUTPUT_FILE);

  exit(OK);
}
//------------------------------------------------------------------------------
// ☆ END OF IMPLEMENTATION ☆
//------------------------------------------------------------------------------