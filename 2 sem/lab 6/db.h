#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

class DB
{
public:
	int CreateDB (const char *path);
	FILE *OpenDB (const char *path);
	void ToList (FILE *fp, LinkedList *myList);
	Trips *FindNearest (FILE *fp, char* finish);
	void CloseDB (FILE *fp);
	void InputTrip (Trips *trip);
};