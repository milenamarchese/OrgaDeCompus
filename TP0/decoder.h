#ifndef DECODER_H
#define DECODER_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

/*
 * Function for decoding or encoding the `char*` into the `FILE*`
 */
typedef void (*convert_string_t) (char*, int, FILE*);

/*
 * Reads the input `in` and transforms its buffer
 * acording to the `convert` function
 */
int process_file(char* in_file, char* out_file, convert_string_t convert);

/*
 * Decodes the contents of `string` from Base64 to ASCII
 * and prints the output to `out_file`
 */
void decode_string(char* string, int string_len, FILE* out_file);

/*
 * Decodes the contents of the four bytes `in` from Base64 to ASCII
 * into the three bytes `out`
 */
void decode_chars(char in[4], int n_in, char out[3]);

/*
 * Encodes the contents of `string` from ASCII to Base64
 * and prints the output to `out_file`
 */
void encode_string(char* string, int string_len, FILE* out_file);

/*
 * Encodes the contents of the three bytes `in` from ASCII to Base64
 * into the four bytes `out`.
 * If `in` has less than three bytes, the remainder of bytes in the
 * output will be filled with '='
 */
void encode_chars(char in[3], int n_in, char out[4]);

#endif
