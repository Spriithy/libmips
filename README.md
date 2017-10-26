# libmips
A library to help work with MIPS 32

## Building

To build the `libmips` library you simply need to :

```sh
cd release
make all
```

This will generate a file named `libmips.a`.

**Note**: *you can alternatively do the same in `debug/` to produce a debug build.*

## Using it in your project

To use the `libmips` in your project simply compile using these additional flags:

```sh
# To compile with the headers ...
gcc -I"/path/to/libmips" ...

# When invoking the linker ...
gcc -L"/path/to/libmips.a" -lmips ...
```

