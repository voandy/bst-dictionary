#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"

typedef enum {M, F} gender_t;
typedef enum {Summer, Winter} season_t;
typedef enum {Gold, Silver, Bronze, Na} medal_t;

typedef struct entry_t {
  char name[MAX_STR];
  int ID;

  gender_t gender;
  int age;
  int height;
  int weight;

  char team[MAX_STR];
  char noc[NOC_LEN];

  char games[MAX_STR];
  int year;
  season_t season;
  char host_city[128];

  char sport[128];
  char event[128];
  medal_t medal;
} entry_t;

/**
* reads a row of input and formats it
* @param a string of comma seperate values
* @return an entry_t*
*/
entry_t* read_row(char* row){
  entry_t* entry = malloc(sizeof(entry_t));
  char* token;
  token = strtok(row, ",");

  while(token != NULL){
    printf("%s\n", token);
    token = strtok(NULL, ",");
  }

  return entry;
}

void print_data(entry_t data){
}
