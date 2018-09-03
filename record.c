#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

char* get_gender(gender_t gender);
char* get_season(season_t season);
char* get_medal(medal_t medal);

/**
* creates an record and reads a row of data into it
* @param a string of comma seperate values
* @return a pointer to the newly created and read record
*/
struct record* read_row(char* row){
  struct record* record = malloc(sizeof(struct record));
  char* token;
  token = strtok(row, ",");

  // reads ID
  record->id = atoi(token);
  token = strtok(NULL, ",");

  // reads name
  record->name = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(record->name, token);
  token = strtok(NULL, ",");

  // reads gender
  switch (token[0]) {
    case 'M': record->gender = M;
    break;

    case 'F': record->gender = F;
    break;
  }
  token = strtok(NULL, ",");

  // reads age
  record->age = atoi(token);
  token = strtok(NULL, ",");

  // reads height, 0 when no data is available
  record->height = atoi(token);
  token = strtok(NULL, ",");

  // read weight
  record->weight = atoi(token);
  token = strtok(NULL, ",");

  // read team
  record->team = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(record->team, token);
  token = strtok(NULL, ",");

  // read NOC
  strcpy(record->noc, token);
  token = strtok(NULL, ",");

  // read games
  record->games = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(record->games, token);
  token = strtok(NULL, ",");

  // read year
  record->year = atoi(token);
  token = strtok(NULL, ",");

  // read season
  switch (token[0]) {
    case 'S': record->season = Summer;
    break;

    case 'W': record->season = Winter;
    break;
  }
  token = strtok(NULL, ",");

  // read host host_city
  record->host_city = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(record->host_city, token);
  token = strtok(NULL, ",");

  // read sport
  record->sport = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(record->sport, token);
  token = strtok(NULL, ",");

  // read event
  record->event = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(record->event, token);
  token = strtok(NULL, ",");

  // read medal
  switch (token[0]) {
    case 'N': record->medal = NoMedal;
    break;

    case 'G': record->medal = Gold;
    break;

    case 'S': record->medal = Silver;
    break;

    case 'B': record->medal = Bronze;
    break;
  }

  return record;
}

// prints name and id from a record
void print_name_id(struct record* record){
  printf("%s −−> ID: %i ", record->name, record->id);
}

// prints data from a record
void print_record(struct record* record){
  // print gender
  printf("Sex: %s || ", get_gender(record->gender));

  // print age
  if(record->age == 0){
    printf("Age: NA || ");
  } else {
    printf("Age: %i || ", record->age);
  }

  // print height
  if(record->height == 0){
    printf("Height: NA || ");
  } else {
    printf("Height: %i || ", record->height);
  }

  // print weight
  if(record->weight == 0){
    printf("Weight: NA || ");
  } else {
    printf("Weight: %i || ", record->weight);
  }

  // print team
  printf("Team: %s || ", record->team);

  // print noc
  printf("NOC: %s || ", record->noc);

  // print games
  printf("Games: %s || ", record->games);

  // print year
  printf("Year: %i || ", record->year);

  // print season
  printf("Season: %s || ", get_season(record->season));

  // print host city
  printf("City: %s || ", record->host_city);

  // print sport
  printf("Sport: %s || ", record->sport);

  // print event
  printf("Event: %s || ", record->event);

  // print medal
  printf("Medal: %s || ", get_medal(record->medal));

  printf("\n");
}

// frees a record from memory
void free_record(struct record *record){
  free(record->name);
  free(record->team);
  free(record->games);
  free(record->host_city);
  free(record->sport);
  free(record->event);
  free(record);
}

// returns the string associated with the enum value in gender_t
char* get_gender(gender_t gender){
  switch (gender) {
    case M: return "M";
    case F: return "F";
    default: exit(EXIT_FAILURE);
  }
}

// returns the string associated with the enum value in season_t
char* get_season(season_t season){
  switch (season) {
    case Summer: return "Summer";
    case Winter: return "Winter";
    default: exit(EXIT_FAILURE);
  }
}

// returns the string associated with the enum value in medal_t
char* get_medal(medal_t medal){
  switch (medal) {
    case Gold: return "Gold";
    case Silver: return "Silver";
    case Bronze: return "Bronze";
    case NoMedal: return "NA";
    default: exit(EXIT_FAILURE);
  }
}
