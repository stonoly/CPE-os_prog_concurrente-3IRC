/* File: telecharge.c
 * Write a program (telecharge.c) which takes a file list and a destination directory into arguments.
 * The program recovers the files in parallel and save them in the destination folder
 * autor: Pierre MOLY
 * Exercice 4
 */

#include "telecharge.h"

void download_files(char* files[], int file_count, const char* destination) {
    int max_child = 4;
    int compt_child = 0;

    for (int i = 0; i < file_count; i++) {
        pid_t fils_download = fork();

        if (fils_download == 0) {

            char output_path[1024];
            snprintf(output_path, sizeof(output_path), "%s/%s", destination, strrchr(files[i], '/') + 1);

            printf("Début download: %s (PID: %d)\n", files[i], getpid());

            char* exec_download[6] = {"wget", "-P", destination, files[i], NULL};
            int error = execvp("wget", exec_download);

            if (error == -1) {
                perror("execvp");
                exit(-1);
            }

            printf("Finished download: %s (PID: %d)\n", files[i], getpid());
            exit(0);

        } else {
            compt_child++;

            if (compt_child >= max_child) {
                wait(NULL);
                compt_child--;
            }
        }
    }

    while (compt_child > 0) {
        wait(NULL);
        compt_child--;
    }
}

int main(int argc, char* argv[]){
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <destination>\n", argv[0]);
        return 1;
    }

    int file_count = argc - 2;
    char* files[file_count];
    for (int i = 0; i < file_count; i++) {
        files[i] = argv[i + 1];
    }

    const char* destination = argv[argc - 1];

    pid_t fils = fork();
    if (fils == 0) {
        download_files(files, file_count, destination);
        exit(0);
    } else {
        wait(NULL);
    }

    return 0;
}