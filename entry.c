#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"

typedef enum {M, F} gender_t;
typedef enum {Summer, Winter} season_t;
typedef enum {Gold, Silver, Bronze, NoMedal} medal_t;

char* get_gender(gender_t gender);
char* get_season(season_t season);
char* get_medal(medal_t medal);

struct entry_t {
  int id;
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
* creates an entry and reads a row of data into it
* @param a string of comma seperate values
* @return a pointer to the newly read entry
*/
entry_t* read_row(char* row){
  entry_t* entry = malloc(sizeof(entry_t));
  char* token;
  token = strtok(row, ",");

  // reads ID
  entry->id = atoi(token);
  token = strtok(NULL, ",");

  // reads name
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
  switch (token[0]) {
    case 'S': entry->season = Summer;
    break;

    case 'W': entry->season = Winter;
    break;
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
void print_data(entry_t* data){
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

// returns the string associated with the enum value in gender_t
char* get_gender(gender_t gender){
  switch (gender) {
    case M: return "M";
    case F: return "F";
  }
}

// returns the string associated with the enum value in season_t
char* get_season(season_t season){
  switch (season) {
    case Summer: return "Summer";
    case Winter: return "Winter";
  }
}

// returns the string associated with the enum value in medal_t
char* get_medal(medal_t medal){
  switch (medal) {
    case Gold: return "Gold";
    case Silver: return "Silver";
    case Bronze: return "Bronze";
    case NoMedal: return "NA";
  }
}
