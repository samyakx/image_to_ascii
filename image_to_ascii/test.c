#include <stdio.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include</Users/apple/stb/stb_image.h>

int main(int agrc, char *argv[])
{
    char Chars[] = " !#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    int CharsLen = strlen(Chars);

    int Width, Height, PixelSize;
    unsigned char *ImageData = stbi_load(argv[1], &Width, &Height, &PixelSize, 0);

    if(ImageData)
    {
        unsigned char *Pixels =ImageData;
        for(int RowIndex =0;
            RowIndex < Height;
            RowIndex++)
        {
            for(int ColumnIndex = 0;
                ColumnIndex < Width;
                ColumnIndex++)
            {
                unsigned char R = *Pixels++;
                unsigned char G = *Pixels++;
                unsigned char B = *Pixels++;
                if(PixelSize >= 4)
                {
                    unsigned char A = *Pixels++;
                }
                float Avg = (R + G + B) / 3.0f;
                int CharIndex =(int)(CharsLen * (Avg / 255.0f));
                putchar(Chars[CharIndex]);
            }    
            putchar('\n');
        }    
    }
    else
    {
        printf("failed to load image %s\n", argv[1]);
    }
    return 0;

}