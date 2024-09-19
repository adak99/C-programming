#include <stdio.h>

struct day {
  int date;
  int month;
  int year;
};

int calDate(struct day birthDate, struct day preDate) {
  int total_days = 0;

  int year = preDate.year - birthDate.year;
  int month = preDate.month - birthDate.month;
  int day = preDate.date - birthDate.date;

  total_days = year * 365 + month * 30 + day;

  return total_days;
}

int main() {
  struct day birthDate, preDate;

  printf("DD: ");
  scanf("%d", &birthDate.date);
  printf("MM: ");
  scanf("%d", &birthDate.month);
  printf("YY: ");
  scanf("%d", &birthDate.year);

  preDate.date = 22;
  preDate.month = 8;
  preDate.year = 2024;

  int totalDate = calDate(birthDate, preDate);

  printf("Total days: %d\n", totalDate);

  return 0;
}

/*
output->

DD: 15
MM: 6
YY: 2000
Total days: 8847

*/