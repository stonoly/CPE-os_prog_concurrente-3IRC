#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void load_image(const char* filepath, unsigned char** image_data, size_t* width, size_t* height);
void save_image(const char* filepath, unsigned char* image, size_t width, size_t height);

struct pixel{
	size_t x;
	size_t y;
};

size_t what_index(struct pixel Pixel, size_t width){
	return (Pixel.y * width + Pixel.x) * 3;
}

void pixels_around(size_t tab[9], struct pixel Pixel, size_t width){
	size_t x = Pixel.x;
	size_t y = Pixel.y;

	struct pixel Pixel_copy;

	Pixel_copy.x = x - 1;
	Pixel_copy.y = y - 1;
	tab[0] = what_index(Pixel_copy, width);

	Pixel_copy.x = x;
	Pixel_copy.y = y - 1;
	tab[1] = what_index(Pixel_copy, width);

	Pixel_copy.x = x + 1;
	Pixel_copy.y = y - 1;
	tab[2] = what_index(Pixel_copy, width);

	Pixel_copy.x = x - 1;
	Pixel_copy.y = y;
	tab[3] = what_index(Pixel_copy, width);

	Pixel_copy.x = x - 1;
	Pixel_copy.y = y - 1;
	tab[4] = what_index(Pixel_copy, width);

}



int main(void)
{
	unsigned char* image = NULL;
	unsigned char* out_image = NULL;
    const char* filename = "image.ppm";
    const char* output_filename = "output.ppm";
	size_t width = 0;
	size_t height = 0;
	
    load_image(filename, &image, &width, &height);
	out_image = malloc((width*height*3) * sizeof(unsigned char));

	printf("Image width: %lu\n", width);
	printf("Image height: %lu\n", height);

	struct pixel Pixel1 = {200, 587};

	

	for (size_t x = 0; x < (width * height) * 3; x++){
			out_image[x] = image[x];
	}

	size_t index = what_index(Pixel1, width);

	size_t tab[9];


	for (short i = 0; i < 3; i++){
		out_image[index + i] = 0;
	}


	save_image(output_filename, out_image, width, height);
	free(image);
    free(out_image);
	return 0;
}

//Vous n'avez pas besoin de comprendre les lignes qui suivent

char* readline(int fd)
{
	int offset = 0;
	size_t size;
	char dummy;
	do {
		size = read(fd,&dummy,1);
		offset += size;
	} while(size != 0 && dummy != '\n' && dummy != EOF);

	char* line = malloc(offset * sizeof(char)+1);
	lseek(fd,-offset,SEEK_CUR);
	read(fd,line,offset);
	line[offset]='\0';
	return line;
}

void load_image(const char* filepath, unsigned char** image_data, size_t* width, size_t* height)
{
	int fd = open(filepath,O_RDONLY);
	if (fd == -1)
	{
		perror("Can't open input file");
		exit(-1);
	}
	char* line = readline(fd);
	if ( strncmp("P6", line, 2) != 0)
	{
		fputs("Input File is not a ppm file\n", stderr);
		free(line);
		exit(-1);
	}
	free(line);
	do {
		line = readline(fd);
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		int success = sscanf(line,"%lu %lu",width,height);
		if (success != 2)
		{
			fputs("Input File is not a valid ppm file\n", stderr);
			free(line);
			exit(-1);
		}
		free(line);
	} while(*width == 0);
	int dummy = 0;
	do {
		line = readline(fd);
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		int success = sscanf(line,"%d",&dummy);
		if (success != 1)
		{
			fputs("Input File is not a valid ppm file\n", stderr);
			free(line);
			exit(-1);
		}
		free(line);
	} while(dummy == 0);

	unsigned data_size = 3 * (*width) * (*height);
	*image_data = malloc(data_size * sizeof(unsigned char));

    read(fd,*image_data,3*(*width)*(*height));
}

void save_image(const char* filepath, unsigned char* image, size_t width, size_t height)
{
	int fd = open(filepath,O_CREAT|O_WRONLY,0644);
	if (fd == -1)
	{
		perror("Can't open output file");
		exit(-1);
	}
	write(fd,"P6\n",3);
	char* size = NULL;
	asprintf(&size,"%lu %lu\n",width, height);
	write(fd,size,strlen(size));
	free(size);
	write(fd,"255\n",4);
    usleep(500000);
    write(fd,image,3*width*height);
	write(fd,"\n",1);
	close(fd);

}

