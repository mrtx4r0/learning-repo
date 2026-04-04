#include <iostream>
#include "PrinterDevice.h"

int main (int argc, char* argv[])
{
	PrinterDevice printer("Desk Printer", "SN-PRN-2001");
	printer.initialize();
	printer.shutdown();
	return 0;
}