#include "../projects/lib42/_inc/lib42.h"
#include <strings.h>


typedef struct elf {
	int *calorie;
} elf;

int main (int argc, char **argv)
{
	int c;
	char *s;
	size_t len;
	char *input = argv[1];
	FILE *input_file;
	int calorie;
	elf elf[calorie];

	input_file = fopen(input, "r");

	if (input_file == 0){
		perror("Canot open input file\n");
		exit(-1);
	}
	else{
		int found_word = 0;
		while ((s = fgetln(input_file, &len))){
			char *p = strchr(line_buf, ' ');
			p = strchr(p+1, ' ');//second space
			*p = '\0';
			int i = 0;
			for (int i = 0; i < )
			elf[i];.ca - = strdup(atoi(p));
//			char *tmp = strdup(s);
//			int n = atoi(tmp);

			printf("%c", c);
//			if (c == '\n'){
//				if (c == '\n'){
//
//
//				}
//
//				putchar(c);
//			}
//			else {
//				if (found_word) {
//					putchar('\n');
//					found_word=0;
//				}
			}

		}


	fclose(input_file);


	return 0;
}