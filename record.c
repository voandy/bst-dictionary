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

// writes the details of a single record to the outputfile
void write_result(FILE *file, struct record* result){
  // print id
  fprintf(file, "ID: %i || ", result->id);

  // print gender
  fprintf(file, "Sex: %s || ", get_gender(result->gender));

  // print age
  if(result->age == 0){
    fprintf(file, "Age: NA || ");
  } else {
    fprintf(file, "Age: %i || ", result->age);
  }

  // print height
  if(result->height == 0){
    fprintf(file, "Height: NA || ");
  } else {
    fprintf(file, "Height: %i || ", result->height);
  }

  // print weight
  if(result->weight == 0){
    fprintf(file, "Weight: NA || ");
  } else {
    fprintf(file, "Weight: %i || ", result->weight);
  }

  // print team
  fprintf(file, "Team: %s || ", result->team);

  // print noc
  fprintf(file, "NOC: %s || ", result->noc);

  // print games
  fprintf(file, "Games: %s || ", result->games);

  // print year
  fprintf(file, "Year: %i || ", result->year);

  // print season
  fprintf(file, "Season: %s || ", get_season(result->season));

  // print host city
  fprintf(file, "City: %s || ", result->host_city);

  // print sport
  fprintf(file, "Sport: %s || ", result->sport);

  // print event
  fprintf(file, "Event: %s || ", result->event);

  // print medal
  fprintf(file, "Medal: %s || ", get_medal(result->medal));

  fprintf(file, "\n");
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
