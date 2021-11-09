/**
 * @file cesar.h
 * @author Carl Montpetit (MONC08069000)
 * @brief hearders of a program that provides the functionality to translate
 * texte encrypted with the encryption of Cesar
 * @version 1.0
 * @date 2021-10-20
 *
 * @copyright Copyright (c) 2021
 */
//------------------------------------------------------------------------------
// ☆ Preprocessor tasks ☆
//------------------------------------------------------------------------------
// Provides many standard library functions for file input and output
#include <stdio.h>
// Provides functions involving memory allocation, process control, conversions
// and others
#include <stdlib.h>
// Provides the boolean type
#include <stdbool.h>
// Provides various functions for manipulating characters
#include <ctype.h>
// Provides various functions for manipulating arrays of characters
#include <string.h>
// Provides macros for reporting and retrieving error conditions using the
// symbol errno
#include <errno.h>
//------------------------------------------------------------------------------
// ☆ Constants declarations ☆
//------------------------------------------------------------------------------
#define EXECUTABLE list_of_arguments[0]
#define INPUT_FILE list_of_arguments[1]
#define OUTPUT_FILE list_of_arguments[2]
#define LINE_SEPARATOR                                                         \
  "==========================================================================" \
  "======\n"
#define ERR_MSG_NO_ARGS                                                        \
  "✗ Error, please insert arguments to the program!…\nEx: ./cesar "        \
  "file_to_translate file_append_result\n"
#define ERR_MSG_FILE_EMPTY                                                     \
  "✗ Error, the file ☞ %s passed to the program is empty!…\n"
#define ERR_MSG_OUTPUT_FILE_DOESNT_EXIST                                       \
  "✗ Error, the output file doesn't exist!…\n"
#define ERR_MSG_DOESNT_EXIST "✗ Error, the input file ☞ %s doesn't exist!…\n"
#define ERR_MSG_NOT_TRANSLATED                                                 \
  "✔︎ The translation of %s was NOT writen in the %s!…\nPlease, enter "  \
  "valid arguments! Ex: ./cesar input.txt output.txt\n"
#define ERR_MSG_END "❥ End of the program!…\n"
#define MSG_WELCOME                                                            \
  "★ Welcome, this program will translate a file encrypted with Cesar "      \
  "cypher!\n"
#define MSG_SUCCESS "✔︎ Success, the result is the follow ⬇︎\n"
#define MSG_IS_TRANSLATED                                                      \
  "✔︎ The translation of %s was writen in the %s!…\n"
#define MSG_ORIGINAL_FILE "✦ The original line #%d is :\n"
#define MSG_TRANSLATED_FILE "✦ The translated line #%d is :\n"

#define MSG_SIZE "ℹ️ The file contains %d characters!…\n"
#define MSG_END "❤︎ End of the program!…\n"
#define MAX_CHARACTERS_FOR_LINE 80
#define ALPHABET_NUMBER 26
//------------------------------------------------------------------------------
// ☆ ∀ TYPES DECLARATIONS ☆
//------------------------------------------------------------------------------
enum Error {
  OK,
  ERR_NO_ARGS,
  ERR_FILE_EMPTY,
  ERR_FILE_DOESNT_EXIST,
};
//------------------------------------------------------------------------------
// ☆ ∀ FUNCTIONS PROTOTYPES (declarations) ☆
//------------------------------------------------------------------------------
/**
 * @brief Translate an encrypted file with a shift of +3 (cesar encryption)
 */
void translate_cesar_file(FILE *file_input, FILE *file_output, char *line);

/**
 * @brief Print the content of a string to stdout
 *
 * @param line : a string
 * @param count : the number of a line
 */
void print_line(char *line, unsigned int count);

/**
 * @brief Print a line to separate things on the terminal
 */
void print_separator(void);

/**
 * @brief Print a welcome message for the program execution to stdout
 */
void print_welcome_msg(void);

/**
 * @brief Print a success message to stdout when program execute without any
 * problem
 */
void print_success_msg(void);

/**
 * @brief Print an end of program message to stdout when there's no problem
 *
 * @param input_file
 * @param output_file
 */
void print_end_success_msg(char *input_file, char *output_file);

/**
 * @brief Print an end of program message to stderr when the input file doesn't
 * exist
 *
 * @param input_file
 * @param output_file
 */
void print_end_err_msg_doesnt_exist(char *input_file, char *output_file);

/**
 * @brief Print an end of program message to stderr when the input file is empty
 *
 * @param input_file
 * @param output_file
 */
void print_end_err_msg_empty(char *input_file, char *output_file);

/**
 * @brief Delete all '\n' (line jump) from a string and replace it for a white
 * space
 *
 * @param line : a string
 */
void destroy_line_jump(char *line);

/**
 * @brief Validate if a file is empty
 *
 * @param file
 * @return true : if empty
 * @return false : if not empty
 */
bool file_is_empty(char *file);

/**
 * @brief Validate if a character is a letter (including capital &
 * non-capital)
 *
 * @param character
 * @return true : if the character is a letter
 * @return false  : if the character is not a letter
 */
bool is_letter(char character);

/**
 * @brief Translate a line of 80 characters of a cesar encrypted file
 *
 * @param buffer
 * @return char* : the array of characters translated
 */
char *translate_cesar_line(char buffer[]);

/**
 * @brief Return the size of a file
 *
 * @param file_name
 * @return int : the size
 */
unsigned int get_size_file(char *file_name);
//------------------------------------------------------------------------------
// ☆ END OF THE HEADER ☆
//------------------------------------------------------------------------------