#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
	struct student rec;
	FILE *fp;
	if (argc != 2)
	{
		fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
		return 1;
	}
	if((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "파일 열기 오류\n");
		return 2;
	}
	printf("--------------------------------\n");
	printf("%-9s %-7s %-4s\n","학번", "이름", "점수");
	printf("--------------------------------\n");

	while(fread(&rec, sizeof(rec), 1, fp) > 0)
		if(rec.id != 0)
			printf("%10d %6s %6d\n", rec.id, rec.name, rec.score);
	printf("--------------------------------\n");
	fclose(fp);
	exit(0);
}
