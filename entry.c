#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"

typedef enum {M, F} gender_t;
typedef enum {Summer, Winter} season_t;
typedef enum {Gold, Silver, Bronze, NoMedal} medal_t;

struct entry_t {
  int ID;
  char name[MAX_STR];

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
};

/**
* reads a row of input and formats it
* @param a string of comma seperate values
* @return an entry_t*
*/
entry_t* read_row(char* row){
  entry_t* entry = malloc(sizeof(entry_t));
  char* token;
  token = strtok(row, ",");

  // reads ID
  entry->ID = atoi(token);
  token = strtok(NULL, ",");

  // reads name
  strcpy(entry->name, token);
  token = strtok(NULL, ",");

  // reads gender
  if(strcmp(token, "M") == 0){
    entry->gender = M;
  } else {
    entry->gender = F;
  }
  token = strtok(NULL, ",");

  // reads age
  entry->age = atoi(token);
  token = strtok(NULL, ",");

  // reads height, 0 when no data is available
  if(strcmp(token, NA) == 0){
    entry->height = 0;
  } else {
    entry->height = atoi(token);
  }
  token = strtok(NULL, ",");

  // read weight
  if(strcmp(token, NA) == 0){
    entry->weight = 0;
  } else {
      entry->weight = atoi(token);
  }
  token = strtok(NULL, ",");

  // read team
  strcpy(entry->team, token);
  token = strtok(NULL, ",");

  // read NOC
  strcpy(entry->noc, token);
  token = strtok(NULL, ",");

  // read games
  strcpy(entry->games, token);
  token = strtok(NULL, ",");

  // read year
  entry->year = atoi(token);
  token = strtok(NULL, ",");

  // read season
  if(strcmp(token, "Summer") == 0){
    entry->season = Summer;
  } else {
    entry->season = Winter;
  }
  token = strtok(NULL, ",");

  // read host host_city
  strcpy(entry->host_city, token);
  token = strtok(NULL, ",");

  // read sport
  strcpy(entry->sport, token);
  token = strtok(NULL, ",");

  // read event
  strcpy(entry->event, token);
  token = strtok(NULL, ",");

  // read medal
  if(strcmp(token, "Gold") == 0){
    entry->medal = Gold;
  } else if(strcmp(token, "Silver") == 0) {
    entry->medal = Silver;
  } else if(strcmp(token, "Bronze") == 0) {
    entry->medal = Bronze;
  } else {
    entry->medal = NoMedal;
  }

  return entry;
}

void print_data(entry_t data){
}
