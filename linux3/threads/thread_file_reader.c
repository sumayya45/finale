#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

void *read_file(void *file_path) {
    char *path = (char *)file_path; // Cast the argument to a string (char *)
    FILE *file = fopen(path, "r"); // Open the file for reading
    if (file == NULL) { // Check if the file was opened successfully
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END); // Move to the end of the file to determine its size
    long file_size = ftell(file); // Get the file size
    fseek(file, 0, SEEK_SET); // Move back to the beginning of the file

    char *content = malloc(file_size + 1); // Allocate memory for the file content
    fread(content, 1, file_size, file); // Read the file content into memory
    content[file_size] = '\0'; // Null-terminate the content

    fclose(file); // Close the file

    printf("File: %s, Content Length: %ld\n", path, file_size); // Print the file path and content length
    free(content); // Free the allocated memory

    return NULL;
}

int main() {
    pthread_t threads[MAX_FILES]; // Array to hold thread identifiers
    char *file_paths[MAX_FILES] = {"file1.txt", "file2.txt", "file3.txt"}; // Array of file paths to be processed

    for (int i = 0; i < 3; i++) {
        // Create a new thread for each file path
        if (pthread_create(&threads[i], NULL, read_file, (void *)file_paths[i]) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }

    return 0;
}
