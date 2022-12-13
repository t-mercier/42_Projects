#include "../projects/lib42/_inc/lib42.h"
#include <strings.h>

#define LEN 500

struct user{
	char B;
	char A;
	char C;
};

typedef struct data{
	int n;
	char c;
	char *input[LEN];
}data;

int main (int argc, char **argv)
{
	int c;
	char *s;
	size_t len;
	char *input = argv[1];
	FILE *file;
	file = fopen(input, "r");

	char *tab[LEN];
	for (int i = 0; (s = fgetln(file, &len)); i++){
		tab[i] = strtok(s, "\n");
		printf("%s", tab[i]);

	}
	fclose(file);


	return 0;
}