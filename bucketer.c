#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  
  
  int ratedCapacity = 120; 
  
  for (int i = 0; i < nBatteries; i++) {
   
    float sohPercentage = ((float)presentCapacities[i] / ratedCapacity) * 100;
    if (sohPercentage > 80) {
      counts.healthy++;
    } else if (sohPercentage >= 65 && sohPercentage <= 80) {
      counts.exchange++;
    } else {
      counts.failed++;
    }
  }
  
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 77};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
