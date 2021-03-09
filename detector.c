#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TIME      1
#define FS   192000
#define F        20
#define AMPLITUDE_REFERENCE  15000
#define THRESHOLD 10000
#define SHIFT 1
#define V_SIG 5

int main(void)
{
  int16_t reference[TIME * FS];
  double signal[TIME * FS];
  double lock_in_reference[TIME * FS];

  srand(time(NULL));

  int step = TIME * FS / F;
  int half_step = step / 2;

  for (int i = 0; i < F; i++)
  {
    for (int j = 0; j < half_step; j++)
    {
      reference[i * step + j] = 0 + rand() % 1000;
      reference[i * step + half_step + j] = AMPLITUDE_REFERENCE + rand() % 1000;
    }
  }

  // for (int i = 0; i < FS * TIME; i++)
  // {
  //   signal[i] = V_SIG * sin(F * (double) i / FS + SHIFT) + rand() % 100 / 1000;
  // }

  // // // printf("%i\n",(int) (V_SIG * sin(SHIFT)* 10000 + rand() % 100));
  // // printf("%i\n", signal[0]);
  // for (int i = 0; i < F; i++)
  // {
  //   printf("%f\n", signal[i * step + 1]);
  //   printf("%f\n", signal[i * step + half_step + 1]);
  // }

  return 0;
}
