#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    if(argc != 2) {
        fprintf(stderr, "Usage: %s [brainf**k program]\n", argv[0]);
        return 1;
    }

    FILE* bfprog = fopen(argv[1], "rb");
    if(!bfprog) {
        perror(argv[1]);
        return 1;
    }
}