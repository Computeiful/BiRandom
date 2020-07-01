# BiRandom
This prng uses Bijective AES CPU encryption to produce good pseudo-random numbers, very _very_ fast. For more info see [here](http://www.jandrewrogers.com/2019/02/12/fast-perfect-hashing).

See `Main.c` for a usage example.

This generator makes use of the AES instructions on most modern CPUs (and therefore must be compiled with `-maes` on gcc).
