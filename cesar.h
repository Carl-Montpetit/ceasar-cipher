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

// Constants declarations
#define EXECUTABLE arguments_list[0]
#define INPUT_FILE arguments_list[1]
#define OUTPUT_FILE arguments_list[2]
#define ERR_MSG_NO_ARGS "✗ Error, please insert arguments to the program!…\n"
#define ERR_MSG_FILE_EMPTY "✗ Error, the file passed to the program is empty!…\n"
#define MSG_ORIGINAL_FILE "✦ The original file is :\n"
#define MSG_TRANSLATED_FILE "✦ The translated file is :\n"
#define ALPHABET_NUMBER 26
//------------------------------------------------------------------------------
// Declarations of ∀types with docstrings
//------------------------------------------------------------------------------
enum Error {
  OK,
  ERR_NO_ARGS,
  ERR_FILE_EMPTY,
};
//------------------------------------------------------------------------------
// ∀functions prototypes (declarations)
//------------------------------------------------------------------------------