#include <stdio.h>

int main()
{
	FILE *fd;
	char c;
	char str[100];
	char arr[20];
	fd = fopen("./note.txt","w+");
	if(fd == NULL)
	{
		printf("Failed to create or open file\n");
		return -1;
	}
	printf("Enter something:\n");
	fgets(str,100,stdin);
	fprintf(fd,"%s",str);
	fseek(fd,0,SEEK_SET);
	while((c = fgetc(fd)) != EOF)
	{
		printf("%c",c);
	}
	fseek(fd,0,SEEK_SET);
	//scan from file
	fscanf(fd,"%s",arr);
	printf("\n%s",arr);
	fclose(fd);
	return 0;


}


