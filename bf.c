#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define cell_t uint8_t

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    if(argc != 2) {
        fprintf(stderr, "Usage: %s [brainfuck program]\n", argv[0]);
        return 1;
    }

    FILE* bf_prog = fopen(argv[1], "rb");
    if(!bf_prog) {
        perror(argv[1]);
        return 1;
    }

    fseek(bf_prog, 0, SEEK_END);
    size_t prog_size = ftell(bf_prog);
    fseek(bf_prog, 0, SEEK_SET);

    char* prog_data = (char*)calloc(1, prog_size + 1); // +1 so the whole program can be stored in memory as a null-terminated string
    if(!prog_data) {
        fprintf(stderr, "Failed to allocate memory of %zd bytes\n", prog_size + 1);
        fclose(bf_prog);
        return 1;
    }

    size_t chars_read = fread(prog_data, prog_size, 1, bf_prog);
    // TODO: check for read error
}