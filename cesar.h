/**
 * @file cesar.h
 * @author Carl Montpetit (MONC08069000)
 * @brief hearders of a program that provides the functionality to translate
 * texte encrypted with the encryption of Cesar
 * @version 1.0
 * @date 2021-10-20
 *
 * @copyright Copyright (c) 2021
 *
 */
//------------------------------------------------------------------------------
// Preprocessor tasks
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
#define OUTPUT_FILE arguments_list[2]
#define ERR_MSG_NO_ARGS "✗ Error, please insert arguments to the program!…\n"
#define ERR_MSG_FILE_EMPTY "✗ Error, the file passed to the program is empty!…\n"
#define MSG_ORIGINAL_FILE "✦ The original file is :\n"
#define MSG_TRANSLATED_FILE "✦ The translated file is :\n"
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
// ∀functions prototypes (declarations)
//------------------------------------------------------------------------------