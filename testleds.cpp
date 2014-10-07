
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "LedControllerRequestProxy.h"
#include "GeneratedTypes.h"

int main(int argc, const char **argv)
{
  LedControllerRequestProxy *device = new LedControllerRequestProxy(IfcNames_LedControllerRequestPortal);

  portalExec_start();

#ifdef BSIM
  // BSIM does not run very many cycles per second
  int blink = 10;
#else
  int blink = 100000000;
#endif

  while (true) {
    device->setLeds(10, blink);
    sleep(2);
    device->setLeds(5, blink);
    sleep(2);
  }
}
