/*
    SHA256 implementation, test source file.

    This implementation was written by Kent "ethereal" Williams-King and is
    hereby released into the public domain. Do what you wish with it.

    No guarantees as to the correctness of the implementation are provided.
*/

#include <openssl/sha.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sha256.h"

int main() {
    FILE *rnd = fopen("/dev/urandom", "rb");
    if(!rnd) return 1;

    uint8_t data[1<<16];

    for(int i = 0; i < 1000000; i ++) {
        if(i % 1000 == 0) printf("Processed %d hashes . . .\n", i);
        uint16_t length;
        fread(&length, sizeof(length), 1, rnd);

        fread(data, 1, length, rnd);

        uint8_t md[32], openssl_md[32];
        
        sha256(data, length, md); // local implementation
        SHA256(data, length, openssl_md); // OpenSSL implementation

        if(memcmp(md, openssl_md, 32) != 0) {
            printf("Test failed!\n");
            printf("Local implementation says:   ");
            for(int i = 0; i < 32; i ++) printf("%02x", md[i]);
            printf("\n");
            printf("OpenSSL implementation says: ");
            for(int i = 0; i < 32; i ++) printf("%02x", openssl_md[i]);
            printf("\n");
            FILE *data = fopen("failed_testcase", "wb");
            fwrite(data, 1, length, data);
            fclose(data);
            break;
        }
    }
    fclose(rnd);
    return 0;
}
