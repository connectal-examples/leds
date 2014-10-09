
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "LedControllerRequestProxy.h"
#include "GeneratedTypes.h"

int main(int argc, const char **argv)
{
  LedControllerRequestProxy *device = new LedControllerRequestProxy(IfcNames_LedControllerRequestPortal);

  printf("Starting LED test");

  portalExec_start();

#ifdef BSIM
  // BSIM does not run very many cycles per second
  int blinkinterval = 10;
#else
  int blinkinterval = 100000000;
#endif
  int blinkon = 10;
  int blinkoff = 5;
  int sleepinterval = 4;
  for (int i = 0; i < 20; i++) {
    printf("blink %d", blinkon);
    device->setLeds(blinkon, blinkinterval);
    sleep(sleepinterval);
    printf("blink off %d", blinkoff);
    device->setLeds(blinkoff, blinkinterval);
    sleep(sleepinterval);
  }
  printf("Done.\n");
}
