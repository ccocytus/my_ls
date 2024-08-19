/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** typedef
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>

    #define MAX_PATH_LEN 256

struct option {
    char *directoryname;
    int showhidden;
    int reverseorder;
    int showdetails;
    int showcurrdir;
    int sort_time;
};

struct fileinfo {
    struct stat filestat;
    char *filename;
};
typedef struct flag_s {
    char flag;
    int (*ptr_function)(va_list);
} flag_t;

char *getusername(struct stat *fileStat);
char *getgroupname(struct stat *fileStat);
void printdirinfo(struct option *op);
void freedirectory(struct fileinfo **f, int num);
void disp_d(struct option *op, struct fileinfo **f, int num, int total);
void collec_f(struct option *op, struct fileinfo ***f, int *num, int *total);
void processf(struct option *op, struct fileinfo **f, int num, int total);
void processdir(struct option *op);
void printperm(struct stat *fileStat);
void printinfo(struct fileinfo *fileinfo);
void disp_f(struct option *op, struct fileinfo **f, int num, int total);
char *getfilepath(struct option *op, const char *fileName);
void check_flag(char option, struct option *op);
void option(int argc, char **argv, struct option *op);
void count_files(struct option *op, DIR *dir, int *num, int *total);
void collect_fileinfo(struct option *op, DIR *dir, struct fileinfo ***f);
int entity_process(struct option *p, struct dirent *entity);
int should_collect_file(struct option *op, struct dirent *entity);
void process_order(struct option *op, struct fileinfo **f, int num);
void collect_in(struct option *o, struct dirent *entity, struct fileinfo **f);
void processdet(struct option *op, struct fileinfo **f, int num, int total);
void processo_rder(struct option *op, struct fileinfo **f, int num);
void disp_ds(struct option *op, struct fileinfo **f, int num);
void process_e(struct option *p, struct dirent *entity, int *num, int *total);
void option_s(int argc, char **argv, struct option *op, int i);
void disp_file_names(struct fileinfo **f, int num, struct option *op);
void disp_file_details(struct fileinfo **f, int num, struct option *op);
void int_to_string(long long value, char *str);

#endif
