/**
 * \file compress.c
 * \brief  tecent computer
 * \author MailG <gomailgm@gmail.com>
 * \date  Thursday, February 20, 2014 04:53:41 CST
 * 
 */
/* $Id */

#include <stdio.h>

void compress(const char *src)
{
	int counter = 0;
	char last_char = 0;
	char p = 0;

	while (p = *src++) {
		if (p == last_char) {
			counter++;	
		} else {
			if (counter) {
				fprintf(stderr, "%c%d", last_char, counter);
			}
			last_char = p;
			counter = 1;	
		}
	}

	if (counter) {
		fprintf(stderr, "%c%d", last_char, counter);	
	}
}

int main(int argc, char* argv[])
{
	const int bufsize = 1024;
	char s[bufsize];
	while (scanf("%s", s)) {
		if (*s == '0' && !*(s+1)) {
			return 0;
		}
		compress(s);
		fprintf(stderr, "\n");
	}
}
