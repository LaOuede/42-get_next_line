<p align="center">
  <img src="https://github.com/LaOuede/42-project-badges/blob/main/badges/get_next_linee.png" />
</p>

<h1 align=center>get_next_line</h1>

<p align=center>
  The <b>get_next_line</b> project is a programming exercise focused on reading and manipulating text from files or standard input.
  The goal is to create a function that reads a line from a file descriptor and returns it as a string, while handling different file sizes and line termination characters.
  It is required to implement a solution that is efficient, handles edge cases, and adheres to the project's specific requirements and constraints.
</p>

<div align="center">

Go to [42 Québec](https://42quebec.com/) to discover the course ! 👈
</div>

---

<h3 align="left">What I've learned 📚</h3>

I've acquired a lot of basic knowledge on C programming :
- String manipulation
- File handling and file descriptors
- Static variables
- Memory management
- Problem-solving and efficiency
- Edge case handling
- Coding standards and requirements
- Testing and debugging

---

<h3 align="left">If I had to do it all over again 🗒</h3>

- I would improve my memory handling by minimizing memory allocation
- I would use free_null instead of free to set pointers to NULL to prevent accidental access to freed memory

---

<h3 align="left">Usage 🛠</h3>

- main.c :
```c
#include "get_next_line.h"
# include <unistd.h> //write
# include <stdio.h>  //open ; printf
# include <fcntl.h>  //O_RDONLY
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test3", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		if (line)
			free(line);
	}
	close (fd);
	return (0);
}
```
- compilation :
```bash
gcc main.c get_next_line.c get_next_line_utils.c
```
- buffer :
```bash
gcc -D BUFFER_SIZE=<nbr> main.c get_next_line.c get_next_line_utils.c
```
- execution :
```bash
./a.out <filename>
```
- return value :
```bash
The output diplays the whole file
```
---

<div align="center">

To look at [my next 42 project](https://github.com/LaOuede/Born2BeRoot) !
</div>
