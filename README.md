# BiRandom
This PRNG uses Bijective AES CPU encryption to produce good pseudo-random numbers, very, _very_ fast. For more info see [here](http://www.jandrewrogers.com/2019/02/12/fast-perfect-hashing).

See `Main.c` for a usage example.

This PRNG makes use of the AES encryption instructions found on most modern CPUs - and therefore must be compiled with `-maes` on gcc:

Example: `gcc -O3 -std=c99 -maes Main.c`

For even faster PRNG see [here](https://github.com/Computeiful/QuickRandom).
