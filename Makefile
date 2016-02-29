
S2H_INTERFACES = LedControllerRequest:LedController.request
BSVFILES = LedController.bsv
CPPFILES= testleds.cpp
NUMBER_OF_MASTERS =0

PIN_TYPE = LEDS
PIN_TYPE_INCLUDE = Leds
PINOUT_FILE = pinout.json
AUTOTOP = --interface pins:LedController.leds

include $(CONNECTALDIR)/Makefile.connectal
