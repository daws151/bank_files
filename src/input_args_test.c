#include <stdio.h>
// using namespace std;

int main(int argc, char* argv[]) {
    printf("argc is: %u\n", argc);
    for(int i=0; i<argc; i++){
        printf("argv is: %s\n", argv[i]);
    }
}
