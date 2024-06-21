#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include<aio.h>
#include<pthread.h>
#include<errno.h>

#define BUFFER_SIZE 4096

void *process_file (void *arg) {
    char *filename = (char *)arg;
    int fd;
    struct stat file_stat;
    char *buffer;
    struct aiocb aio;

    // Open file for reading

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    // Get file size

    if (fstat(fd, &file_stat) < 0) {
        perror("Error getting file size");
        close(fd);
        pthread_exit(NULL);
    }

    // Allocate buffer

    buffer = malloc(file_stat.st_size);
    if(!buffer) {
   perror(" Error allocating buffer ");
   close(fd);
   pthread_exit(NULL);
    }

    // perform asynchronous read memset(&aio,0,sizeof(struct aiocb));

    aio.aio_fildes = fd;
    aio.aio_buf = buffer;
    aio.aio_nbytes = file_stat.st_size;
    aio.aio_offset = 0;

    if(aio_read(&aio) < 0) {
   perror(" Error initiating asynchronous read ");
   free(buffer);
   close(fd);
   pthread_exit(NULL);
    }

    // wait for asynchronous read completion

    while(aio_error(&aio) == EINPROGRESS);
    if(aio_return(&aio) < 0) {
  perror(" Error reading file asynchronously ");
  free(buffer);
  close(fd);
  pthread_exit(NULL);
    }

    // process file data (simplified for demonstration

    printf("Thread processing file : %s \n",filename);

    //implement actual file processing logic here)

    //cleanup
    free(buffer);
    close(fd);

    pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
if(argc < 2){
fprintf(stderr,"Usage : %s <file1> <file2> ... <fileN> \n",argv[0]);
exit(EXIT_FAILURE);
}

int num_files = argc - 1;
pthread_t threads[num_files];
int i;

//create threads to process files
for(i=0;i<num_files;i++){
if(pthread_create(&threads[i],NULL,process_file,(void *)argv[i+1]) != 0) {
perror(" Error creating thread ");
exit(EXIT_FAILURE);
}
}

// wait for threads to complete
for (i=0;i < num_files; i++){
      if(pthread_join(threads[i], NULL) != 0){
perror(" Error joining thread ");
exit(EXIT_FAILURE);
      }
}

        printf(" All threads have completed processing \n");
return 0;
}

