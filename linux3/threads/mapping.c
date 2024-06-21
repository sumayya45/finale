#include <stdio.h> 

#include <stdlib.h> 

#include <unistd.h> 

#include <fcntl.h> 

#include <sys/mman.h> 
#include <sys/stat.h> 

 

int main() { 

    int src_fd, dest_fd; 

    char *src_data; 

    struct stat src_stat; 

 

    // Open source file for reading 

    src_fd = open("source.txt", O_RDONLY); 

    if (src_fd < 0) { 

        perror("Error opening source file"); 

        exit(EXIT_FAILURE); 

    } 

 

    // Open destination file for writing 

    dest_fd = open("destination.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644); 

    if (dest_fd < 0) { 

        perror("Error opening destination file"); 

        close(src_fd); 

        exit(EXIT_FAILURE); 

    } 

 

    // Get source file size 

    if (fstat(src_fd, &src_stat) < 0) { 

        perror("Error getting source file size"); 

        close(src_fd); 

        close(dest_fd); 

        exit(EXIT_FAILURE); 

    } 

 

    // Memory map source file 

    src_data = mmap(NULL, src_stat.st_size, PROT_READ, MAP_PRIVATE, src_fd, 0); 

    if (src_data == MAP_FAILED) { 

        perror("Error mapping source file"); 

        close(src_fd); 

        close(dest_fd); 

        exit(EXIT_FAILURE); 

    } 

 

    // Write source data to destination file 

    if (write(dest_fd, src_data, src_stat.st_size) != src_stat.st_size) { 

        perror("Error writing to destination file"); 

        munmap(src_data, src_stat.st_size); 

        close(src_fd); 

        close(dest_fd); 

        exit(EXIT_FAILURE); 

    } 

 

    // Clean up 

    munmap(src_data, src_stat.st_size); 

    close(src_fd); 

    close(dest_fd); 

 

    printf("File transfer completed successfully.\n"); 

 

    return 0; 

} 
