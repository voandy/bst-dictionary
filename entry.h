#ifndef ENTRY_H
#define ENTRY_H

#define NUM_FIELDS 16
#define MAX_LINE 512
#define MAX_STR 128
// 3 characters + 1 to store null byte
#define NOC_LEN 4

#define NA "NA"

typedef enum {M, F} gender_t;
typedef enum {Summer, Winter} season_t;
typedef enum {Gold, Silver, Bronze, NoMedal} medal_t;

struct entry {
  int id;
  char *name;

  gender_t gender;
  int age;
  int height;
  int weight;

  char *team;
  char noc[NOC_LEN];

  char *games;
  int year;
  season_t season;
  char *host_city;

  char *sport;
  char *event;
  medal_t medal;
};

struct entry* read_row(char* row);
void print_data(struct entry *data);
void free_entry(struct entry *entry);

#endif
