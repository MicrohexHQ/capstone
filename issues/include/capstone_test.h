#ifndef CAPSTONE_TEST_H
#define CAPSTONE_TEST_H

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>
#include <capstone/capstone.h>
#include "helper.h"

#define cs_assert_err(expect, err)									\
do {																\
    cs_err __err = err;												\
    if (__err != expect) {											\
        fail_msg("%s",cs_strerror(__err));							\
    }																\
} while (0)


#define cs_assert_success(err) cs_assert_err(CS_ERR_OK, err)


#define cs_assert_fail(err)											\
do {																\
    cs_err __err = err;												\
    if (__err == CS_ERR_OK) {										\
        fail_msg("%s",cs_strerror(__err));							\
    }																\
} while (0)

#define NUMARCH 9
#define NUMMODE 24
#define NUMOPTION 40

typedef struct {
	const char *str;
	unsigned int value;
} single_dict;

typedef struct {
	const char *str;
	unsigned int first_value;
	unsigned int second_value;
} double_dict;

extern single_dict arches[];
extern single_dict modes[];
extern double_dict options[];

int getIndex(double_dict d[], unsigned size, const char *str);
int getValue(single_dict d[], unsigned size, const char *str);
void test_single(csh *handle, char *line);
int setFunction(char (*function)(csh *, cs_insn *), int arch);

#endif /* CAPSTONE_TEST_H */