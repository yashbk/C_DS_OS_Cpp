
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main()
{
	int fd;
	char write_data[400] = "This is the data written";
	char buffer[400] = "";
	
	//open
	fd = open("/dev/bk_device",O_RDWR);
	if(fd == -1)
		printf("Failed to open device\n");
	else
	{
		//system call for writing 
		if(write(fd,write_data,strlen(write_data)) == -1)
		{
			printf("Write failed\n");
			close(fd);
			return -1;
		}
		else
			printf("The written data is %s\n",write_data);

		if(read(fd,buffer,sizeof(buffer)-1) == -1)
		{
			printf("Device read failed\n");
			close(fd);
			return -1;
		}
		else
			printf("The read data is %s\n",buffer);
	}

	close(fd);
	return 0;
}



		
