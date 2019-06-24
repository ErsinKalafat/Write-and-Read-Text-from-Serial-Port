#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"

void init_UARTstdio(){
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	ROM_GPIOPinConfigure(0x00000001);
	ROM_GPIOPinConfigure(0x00000401);
	ROM_GPIOPinTypeUART(0x40004000, 0x00000001 | 0x00000002);
	UARTStdioInit(0);
}

int main(void){
	int i;
	init_UARTstdio();

	UARTprintf("test!\n");

	for(i=0; ;i++){
		UARTprintf("deneme: %d\n",i);
	}
}
