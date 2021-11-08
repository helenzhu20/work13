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

struct pop_entry * make_pop_entry(int y, int p, char * b) {
    struct pop_entry *pop_e = malloc(sizeof(struct pop_entry));
    pop_e->year = y;
    pop_e->population = p;
    strcpy(pop_e->boro, b);
    return pop_e;
}

int find_index_of_char(char c, char * s) {
    int index;
    char * substring = strchr(s, c);
    index = (int)(substring - s);
    return index;
}

void read_csv(char * filename) {
	char ra[1000];
    int r = open(filename, O_RDONLY);
    if (r < 0) {
		printf("error, read in no bytes\n");
    } else {
		read(r, ra, sizeof(ra));
    }
    close(r);

    char data[1000];
    strncpy(data, &ra[50], strlen(ra)-50);

    struct pop_entry p_e[23*5];
    int count = 0;
    int i, j;
    for (i=0; i<23; i++) {
        int x = find_index_of_char(',', data);

        char d[15];

        int y;
        strncpy(d, data, x);
        sscanf(d, "%d", &y);
        //boroughs = {Manhattan,Brooklyn,Queens,Bronx,Staten Island}

        char temp[1000];
        strncpy(data, &data[5], strlen(data)-5);
        x = find_index_of_char(',', data);
        int p;
        strncpy(d, data, x);
        sscanf(d, "%d", &p);

        p_e[1] = make_pop_entry(y, p, "Manhattan");
        printf("%d, %d, %s\n", p_e[1]->year, p_e[1]->population, p_e[1]->boro);

        char temp[1000];
        strncpy(data, &data[5], strlen(data)-5);
        x = find_index_of_char(',', data);
        strncpy(d, data, x);
        sscanf(d, "%d", &p);

        p_e[2] = make_pop_entry(y, p, "Brooklyn");
        printf("%d, %d, %s\n", p_e[2]->year, p_e[2]->population, p_e[2]->boro);

        char temp[1000];
        strncpy(data, &data[5], strlen(data)-5);
        x = find_index_of_char(',', data);
        strncpy(d, data, x);
        sscanf(d, "%d", &p);

        p_e[3] = make_pop_entry(y, p, "Queens");
        printf("%d, %d, %s\n", p_e[3]->year, p_e[3]->population, p_e[3]->boro);

        p_e[4] = make_pop_entry(y, p, "Bronx");
        printf("%d, %d, %s\n", p_e[4]->year, p_e[4]->population, p_e[4]->boro);

        p_e[5] = make_pop_entry(y, p, "Staten Island");
        printf("%d, %d, %s\n", p_e[5]->year, p_e[5]->population, p_e[5]->boro);
    }

    int debug = 1;
    if (debug) {
        //printf("%s\n", ra);
        //printf("%s\n", data);
        //printf("%d\n", x);
        //printf("%c\n", data[x]);
    }

}

int main(int argc, char *argv[]) {
    printf("argc: %d argv[1]: %s\n", argc, argv[1]);
    if (strcmp(argv[1], "-read_csv") == 0) {
        read_csv("nyc_pop.csv");
    }
    
    //struct pop_entry * p_e = make_pop_entry(2030, 290343, "Manhattan");
    //printf("%d, %d, %s\n", p_e->year, p_e->population, p_e->boro);

}
