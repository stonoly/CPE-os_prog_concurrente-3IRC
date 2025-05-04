/* File: miniature.c
 * Write a program (miniature.c) which takes the path of an argument file and which resize
 * All images within this file at 10% of their original size. The number of conversion processes
 * at the same time should never exceed eight.
* autor: Pierre MOLY
* Exercice 3
*/

#include "miniature.h"


void list_directory_downsize(const char *path) {
    char golden_path[1024];
    snprintf(golden_path, sizeof(golden_path), "%s/images", path);
    DIR *directory = opendir(golden_path);

    if (directory == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    int max_child = 8;
    int compt_child = 0;

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        pid_t fils_downsize = fork();
        if (fils_downsize == 0){

            char input_path[1024];
            snprintf(input_path, sizeof(input_path), "%s/images/%s", path, entry->d_name);

            char output_path[1024];
            snprintf(output_path, sizeof(output_path), "%s/sortie/%s", path, entry->d_name);

            printf("Processing: %s\n", entry->d_name);
            char* exec_downsize[6] = {"convert", input_path, "-resize", "10%", output_path, NULL};
            int error = execvp("convert", exec_downsize);
            if (error == -1){
                exit(-1);
            }
        } else {
            compt_child ++;
            if (compt_child >= max_child){
                wait(NULL);
                max_child--;
            }
        }
    }

    while (compt_child > 0) {
        wait(NULL);
        compt_child--;
    }

    closedir(directory);
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    pid_t fils = fork();
    if (fils == 0){

        list_directory_downsize(argv[1]);
        exit(0);

    } else {
        wait(NULL);
    }

    return 0;
}