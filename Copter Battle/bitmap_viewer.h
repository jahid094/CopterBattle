/*
 * bitmap_viewer.h
 *
 *  Created on: Jan 8, 2017
 *      Author: Jisan Mahmud
 */

#include <stdio.h>
#define RGB_TO_INT(rgb) ((rgb).rgbtRed | ((rgb).rgbtGreen << 8) | ((rgb).rgbtBlue << 16))

//
// Puts a BMP image on screen
//
// parameters:
//  x - x coordinate
//  y - y coordinate
//  fileName - name of the BMP file
//  ignoreColor - A specified color that should not be rendered. If you have an
//                image strip that should be rendered on top of another back
//                ground image, then the background of the image strip should
//                not get rendered. Use the background color of the image strip
//                in ignoreColor parameter. Then the strip's background does
//                not get rendered.
//
//                To disable this feature, put -1 in this parameter
//
void iShowBMPAlternative2(int x, int y, char fileName[], int ignoreColor)
{
	int i, j = 0;
	FILE *bmpFile;

	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER infoheader;
	RGBTRIPLE rgb;

	if ((bmpFile = fopen(fileName, "rb")) == NULL)
		return;

	fread(&fileheader, sizeof(fileheader), 1, bmpFile);
	fread(&infoheader, sizeof(infoheader), 1, bmpFile);

	int *pixelMap = (int *) malloc(infoheader.biWidth * infoheader.biHeight * sizeof(int));
	int curPixel, r, c;

	for (r = 0; r < infoheader.biHeight; r++)
	{
		for (c = 0; c < infoheader.biWidth; c++)
		{
			fread(&rgb, sizeof(rgb), 1, bmpFile);
			curPixel = RGB_TO_INT(rgb);
			pixelMap[r * infoheader.biWidth + c] = curPixel | ((curPixel == ignoreColor ? 0 : 0xFF) << 24);
		}
	}

	fclose(bmpFile);

	glRasterPos2f(x, y);
	glDrawPixels(infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, pixelMap);

	free(pixelMap);
}

//
// Puts a BMP image on screen
//
// parameters:
//  x - x coordinate
//  y - y coordinate
//  fileName - name of the BMP file
//
void iShowBMPAlternative(int x, int y, char fileName[])
{
	iShowBMPAlternative2(x, y, fileName, -1);
}
