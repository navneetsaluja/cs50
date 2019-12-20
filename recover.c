#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    char *image = argv[1];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *inptr = fopen(image, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", image);
        return 2;
    }

    unsigned char buffer[512];

    int trackopen = 0;
    int trackjpeg = 0;

    char filename[10];
    FILE *img_file;


    while (fread(&buffer, 512, 1, inptr))
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

        if (trackopen)
            {
                fclose(img_file);

                trackopen = 0;

                sprintf(filename, "%03d.jpg", trackjpeg);

                img_file = fopen(filename, "a");

                trackopen = 1;

                trackjpeg++;
            }

            if (!trackopen)
            {
                sprintf(filename, "%03d.jpg", trackjpeg);
                img_file = fopen(filename, "w");

                trackopen = 1;

                trackjpeg++;
            }

            fwrite(&buffer, 512, 1, img_file);
        }

        else
        {
            if (trackopen)
            {
                fwrite(&buffer, 512, 1, img_file);
            }
        }

    }

    fclose(inptr);
    fclose(img_file);

    return 0;
}