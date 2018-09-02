#ifndef ENTRY_H
#define ENTRY_H

#define NUM_FIELDS 16
#define MAX_LINE 512
#define MAX_STR 128
// 3 characters + 1 to store null byte
#define NOC_LEN 4

#define NA "NA"

typedef struct entry_t entry_t;

entry_t* read_row(char* row);
void print_data(entry_t* data);

#endif
