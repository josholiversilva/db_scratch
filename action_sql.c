#include "action_sql.h"
#include <string.h>
#include <stdio.h>

void action(char *buffer){
	// strstr -> contains
	// do the functionality later
	if (strstr(buffer, "CREATE") != NULL || strstr(buffer, "create") != NULL) {
		printf("Going to create..");
	}
	else if (strstr(buffer, "DELETE") != NULL || strstr(buffer,"delete") != NULL) {
		printf("Going to delete..");
	}
	else if (strstr(buffer, "SELECT") != NULL || strstr(buffer,"select") != NULL) {
		printf("Going to select..");
	}
	else if (strstr(buffer, "INSERT") != NULL || strstr(buffer,"insert") != NULL) {
		printf("Going to insert..");
	}
	else if (strstr(buffer, "UPDATE") != NULL || strstr(buffer,"update") != NULL) {
		printf("Going to update..");
	}
}

// Create the item here i.e. CREATE TABLE (TABLE being the item)
//void create(char *item) {
//	
//}
