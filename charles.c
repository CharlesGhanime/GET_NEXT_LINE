#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd = open("42", O_RDONLY);
	int read_return;
	char buffer[] = "adrien sait vraiment plus ce que c'est de coucher...";

	
	read_return = read(fd, buffer, 10);
	buffer[read_return] = '\0';
	printf("%s\n", buffer);
	return (0);
}
