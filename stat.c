#include "types.h"
#include "stat.h"
#include "user.h"

/*
 *
#define T_DIR  1   // Directory
#define T_FILE 2   // File
#define T_DEV  3   // Device

struct stat {
  short type;  // Type of file
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes
};
 *
 *
 */

struct stat status;

void print_type(char* type_str) {
    printf(1, "TYPE: %s\n", type_str);
}

void det_and_print_type(short type) {
    if (type == T_DIR) {
        print_type("Directory");
    } else if (type == T_FILE) {
        print_type("File");
    } else if (type == T_DEV) {
        print_type("Device");
    } else {
        print_type("Unknown");
    }
}

void print_addrs() {
    printf(1, "FILE DISK BLOCK ADDRESSES:\n");
    uint i;
    for (i = 0; i < MAXFILE; i++) {
        if (status.addrs[i] == -1) {
            return;
        }
        printf(1, "%d: %d\n", i, status.addrs[i]);
    }
}

int main(int argc, char *args[]) {
    int i;

    if(argc < 1) {
        printf(2, "usage: stat path/to/file\n");
        exit();
    }
    for(i=1; i<argc; i++) {
        stat(args[i], &status);
        printf(1, "NAME: %s\n", args[i]);
        det_and_print_type(status.type);
        printf(1, "DEV: %d\n", status.dev);
        printf(1, "INODE NUM: %d\n", status.ino);
        printf(1, "NUM LINKS: %d\n", status.nlink);
        printf(1, "SIZE IN BYTES: %d\n", status.size);
        print_addrs();
    }
    exit();
}
