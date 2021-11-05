#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


struct pop_entry {
    int year;
    int population;
    char boro[15];
};

char * read_csv(char * filename/*struct pop_entry*/) {
	int r = open(filename, O_RDONLY);
	char ra[];
	if (r < 0) {
		printf("error, read in no bytes");
	} else {
		read(r, ra, sizeof(ra));
	}
	close(r);
	return &ra;
}

struct pop_entry * make_pop_entry(int y, int p/*, char b*/) {
	struct pop_entry *pop_e = malloc(sizeof(struct pop_entry));
	pop_e->year = y;
	pop_e->population = p;
	//pop_e->boro = b;
	return pop_e;
}

int find_index_of_char(char c, char * s) {
	int index;
	char * substring = strchr(s, c);
	index = (int)(substring - s);
	return index;
}

int main() {
	
	char filetext[1000] = read_csv("nyc_pop.csv");

	//int x = find_index_of_char(',', filetext);
	//printf("%d\n", filetext[x]);

	//struct pop_entry p_e = make_pop_entry()

	int x = find_index_of_char('e', "hello");
	printf("%d\n", x);

}
