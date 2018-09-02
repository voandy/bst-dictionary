#ifndef ENTRY_H
#define ENTRY_H

#define NUM_FIELDS 16
#define MAX_LINE 128
#define MAX_STR 128
#define NOC_LEN 3

typedef struct entry_t entry_t;

entry_t* read_row(char* row);

#endif
