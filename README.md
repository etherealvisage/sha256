### Single-file SHA256 implementation ###

This is an ANSI C89 implementation of the SHA-256 hash algorithm. It's not
optimized, but also not done stupidly from a speed perspective. It's not
designed for streaming data (but would be simple to adapt to that if you care).
The code has been used in several personal projects and tested by passing the
algorithm many millions of random inputs < 64KB in size and comparing the
results against OpenSSL.

To use, simply copy the sha256.c file (or the `sha256` function out of it) and
call as expected. The interface is identical to the OpenSSL function `SHA256`.

The code is released into the public domain. Do what you like with it.
