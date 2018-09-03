#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"

char* get_gender(gender_t gender);
char* get_season(season_t season);
char* get_medal(medal_t medal);

/**
* creates an entry and reads a row of data into it
* @param a string of comma seperate values
* @return a pointer to the newly read entry
*/
struct entry* read_row(char* row){
  struct entry* entry = malloc(sizeof(struct entry));
  char* token;
  token = strtok(row, ",");

  // reads ID
  entry->id = atoi(token);
  token = strtok(NULL, ",");

  // reads name
  entry->name = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(entry->name, token);
  token = strtok(NULL, ",");

  // reads gender
  switch (token[0]) {
    case 'M': entry->gender = M;
    break;

    case 'F': entry->gender = F;
    break;
  }
  token = strtok(NULL, ",");

  // reads age
  entry->age = atoi(token);
  token = strtok(NULL, ",");

  // reads height, 0 when no data is available
  entry->height = atoi(token);
  token = strtok(NULL, ",");

  // read weight
  entry->weight = atoi(token);
  token = strtok(NULL, ",");

  // read team
  entry->team = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(entry->team, token);
  token = strtok(NULL, ",");

  // read NOC
  strcpy(entry->noc, token);
  token = strtok(NULL, ",");

  // read games
  entry->games = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(entry->games, token);
  token = strtok(NULL, ",");

  // read year
  entry->year = atoi(token);
  token = strtok(NULL, ",");

  // read season
  switch (token[0]) {
    case 'S': entry->season = Summer;
    break;

    case 'W': entry->season = Winter;
    break;
  }
  token = strtok(NULL, ",");

  // read host host_city
  entry->host_city = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(entry->host_city, token);
  token = strtok(NULL, ",");

  // read sport
  entry->sport = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(entry->sport, token);
  token = strtok(NULL, ",");

  // read event
  entry->event = (char *) malloc(strlen(token) * sizeof(char) + 1);
  strcpy(entry->event, token);
  token = strtok(NULL, ",");

  // read medal
  switch (token[0]) {
    case 'N': entry->medal = NoMedal;
    break;

    case 'G': entry->medal = Gold;
    break;

    case 'S': entry->medal = Silver;
    break;

    case 'B': entry->medal = Bronze;
    break;
  }

  return entry;
}

// prints an entry
void print_data(struct entry* data){
  // print name and id
  printf("%s −−> ID: %i ", data->name, data->id);

  // print gender
  printf("Sex: %s || ", get_gender(data->gender));

  // print age
  if(data->age == 0){
    printf("Age: NA || ");
  } else {
    printf("Age: %i || ", data->age);
  }

  // print height
  if(data->height == 0){
    printf("Height: NA || ");
  } else {
    printf("Height: %i || ", data->height);
  }

  // print weight
  if(data->weight == 0){
    printf("Weight: NA || ");
  } else {
    printf("Weight: %i || ", data->weight);
  }

  // print team
  printf("Team: %s || ", data->team);

  // print noc
  printf("NOC: %s || ", data->noc);

  // print games
  printf("Games: %s || ", data->games);

  // print year
  printf("Year: %i || ", data->year);

  // print season
  printf("Season: %s || ", get_season(data->season));

  // print host city
  printf("City: %s || ", data->host_city);

  // print sport
  printf("Sport: %s || ", data->sport);

  // print event
  printf("Event: %s || ", data->event);

  // print medal
  printf("Medal: %s || ", get_medal(data->medal));

  printf("\n");
}

void free_entry(struct entry *entry){
  free(entry->name);
  free(entry->team);
  free(entry->games);
  free(entry->host_city);
  free(entry->sport);
  free(entry->event);
  free(entry);
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
