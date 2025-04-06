#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to map grayscale value to ASCII character
char pixel_to_ascii(int gray_value) {
    const char *ascii_chars = "@%#*+=-:. ";
    int num_chars = 10;
    int index = gray_value * (num_chars - 1) / 255;
    return ascii_chars[index];
}

// Main function to process the image and print ASCII
void image_to_ascii(const char *filename, int width, int height) {
    int x, y, channels;
    printf("Trying to load image from: %s\n", filename);  // Debugging output
    
    uint8_t *image_data = stbi_load(filename, &width, &height, &channels, 0);
    
    if (image_data == NULL) {
        printf("Error in loading the image: %s\n", stbi_failure_reason());  // Print the error reason
        exit(1);
    }

    // Loop through the image and convert each pixel to ASCII
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * channels;

            // Get RGB values
            uint8_t r = image_data[pixel_index];
            uint8_t g = image_data[pixel_index + 1];
            uint8_t b = image_data[pixel_index + 2];

            // Convert to grayscale (using the luminance formula)
            int gray_value = (r * 299 + g * 587 + b * 114) / 1000;

            // Map the grayscale value to an ASCII character
            char ascii_char = pixel_to_ascii(gray_value);

            // Print the ASCII character
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    // Free the image data
    stbi_image_free(image_data);
}

int main() {
    const char *image_file = "path_to_your_image.jpg"; // Replace with your image file path
    int width = 0, height = 0;

    // Display the image as ASCII
    image_to_ascii(image_file, width, height);

    return 0;
}
