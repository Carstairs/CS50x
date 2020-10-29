#include <stdio.h>

int main(int argc, char *argv[])
{
	//two inputs are required
	if (argc != 2)
	{
		return 1;
	}

	//opened file
	//second input's value
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		return 1;
	}

	//Read 3 bytes from file
	unsigned char bytes[3]; //unsinged means number from 0-255
	fread(bytes, 3, 1, file);

	// check if those three bytes are 0xff 0xd8 0xff
	if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
	{
		printf("Prolly jpeg\n");
	}
	else
	{
		printf("Not jpeg\n");
	}
}
