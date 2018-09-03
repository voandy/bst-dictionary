#ifndef RECORD_H
#define RECORD_H

#define NUM_FIELDS 16
#define MAX_LINE 512
#define MAX_STR 128
// 3 characters + 1 to store null byte
#define NOC_LEN 4

#define NA "NA"

typedef enum {M, F} gender_t;
typedef enum {Summer, Winter} season_t;
typedef enum {Gold, Silver, Bronze, NoMedal} medal_t;

struct record {
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

struct record * read_row(char* row);
void write_result(FILE *file, struct record* result);
void free_record(struct record *record);

#endif
