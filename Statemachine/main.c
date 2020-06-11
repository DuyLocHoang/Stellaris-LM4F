#include "include.h"
int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	SysTickPeriodSet(SysCtlClockGet()/1000); // period of 1ms
	IntMasterEnable();
	SysTickIntEnable();
	SysTickEnable();
	Config_LED();
	Config_button();
	while (1)
	{
		kiemtrachuyendong();
		DOOR();
		LED();
	}
}
