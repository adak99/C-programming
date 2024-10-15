#include <stdio.h>
struct distance {
  int feet;
  int inch;
};

struct distance addDistance(struct distance dis1, struct distance dis2) {
  struct distance sum;

  sum.feet = dis1.feet + dis2.feet;
  sum.inch = dis2.inch + dis2.inch;

  if (sum.inch >= 12) {
    sum.inch -= 12;
    sum.feet++;
  }

  return sum;
}

int main() {
  struct distance dis1, dis2, sum;

  printf("Enter first distance: \n");
  printf("Enter first feet: ");
  scanf("%d", &dis1.feet);
  printf("Enter first inch: ");
  scanf("%d", &dis1.inch);

  printf("\n");

  printf("Enter second distance: \n");
  printf("Enter second feet: ");
  scanf("%d", &dis2.feet);
  printf("Enter second inch: ");
  scanf("%d", &dis2.inch);

  sum = addDistance(dis1, dis2);

  printf("Total distance: %d feet %d inch", sum.feet, sum.inch);

  return 0;
}

/* output->

Enter first distance:
Enter first feet: 5
Enter first inch: 9

Enter second distance:
Enter second feet: 3
Enter second inch: 6
Total distance: 9 feet 12 inch
*/