#ifndef VECTOR_LABOR_H
#define VECTOR_LABOR_H

#include"vector.h"
#include<stdio.h>

#define VCT_TEST_STR_SIZE 1
#define VCT_TEST_CHAR_GEN(char_value)((char_value)%26+65)
//---------------------------------------------------------------------------//
// Generator of arbitrary str values
void generate_str(char**str_ref,size_t init_value);
void fill_str(char*str_ref,size_t str_size,size_t init_value);
// Fill vector with arbitrary str values
void vct_fill_str(struct Vector*vct_ref,size_t amount_str);
void vct_insert_str(struct Vector*vct_ref,size_t amount_str,size_t index);
// Display vector functions
void vct_str_display(struct Vector*vct_ref);
void vct_set_display(struct Vector*vct_ref);

#endif
