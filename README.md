# antman
Lossless compressor and decompressor for lyrics and ppm images.

Antman binary takes a file as input and compresses it, works well for lyrics, having between a 20-40% compression rate. 
For .ppm images has a minimum of 40% of compression rate, up to 90%.

Giantman binary takes the compressed file as input and translates it back to its original state.

1. Compile with make at the root of the repository.
2. Execute the following command to see the compressing in file 'compressed.data', n has to be 1 for text files, 3 for .ppm:

./antman/antman file.txt n > compressed.data;

3. And then run giantman in 'uncompressed.data', see it return to its original state:
./giantman/giantman compressed.data n > uncompressed.data

Hint: Replace file.txt for the desired text or ppm image you want to compress.
