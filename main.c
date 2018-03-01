#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	
	FILE *fp, *out;
	
	char ip[20], prev_ip[20];
	int count, prev_count = 0;

	fp = fopen("o_source", "rt");
	if (fp == NULL) {
		printf("file cannot open.\n");
		return -1;
	}

	out = fopen("filtered", "wt");
	if (out == NULL) {
		printf("file cannot open\n");
		return -2;
	}
	
	while (fscanf(fp, "%s\t%d", ip, &count) != EOF) {
		printf("%s\n", ip);
		printf("%d\n", count);
		if (strcmp(ip, prev_ip) == 0) {
			prev_count += count;
		} else {
			if (prev_ip != NULL) {
				fprintf(out, "%s %d\n", prev_ip, prev_count);
			}
			strcpy(prev_ip, ip);
			prev_count = count;
		}
	}
	
	fclose(fp);
	fclose(out);
}
