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

    int openFileTracker = 0;
    int jpegTracker = 0;

    char filename[10];
    FILE *img_file;


    while (fread(&buffer, 512, 1, inptr))
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

        if (openFileTracker)
            {
                fclose(img_file);

                openFileTracker = 0;

                sprintf(filename, "%03d.jpg", jpegTracker);

                img_file = fopen(filename, "a");

                openFileTracker = 1;

                jpegTracker++;
            }

            if (!openFileTracker)
            {
                sprintf(filename, "%03d.jpg", jpegTracker);
                img_file = fopen(filename, "w");

                openFileTracker = 1;

                jpegTracker++;
            }

            fwrite(&buffer, 512, 1, img_file);
        }

        else
        {
            if (openFileTracker)
            {
                fwrite(&buffer, 512, 1, img_file);
            }
        }

    }

    fclose(inptr);
    fclose(img_file);

    return 0;
}