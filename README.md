# ANIASCII

`ANIASCII` is a c library for animation of `ascii` arts.Try the `example.c` first `cd` ( change directory ) to `animation_in_c` and execute the following commands,

```bash
make
make run
```

```bash
make clean
```

Check out the video on [YOUTUBE 🔗🔗](https://www.youtube.com/watch?v=VaIm3Gz-rxA).

![animation in c](/assets/animationInC.gif)

## How to use it?

There is a single function `animateAscii()`, the parameters are as follows,

- `Choice Of animation` of type `int`, type of animation,
- `First Art` of type `2D array`,
- `Second Art` of type `2D array`,
- `Rows` of type `int`, the number of rows in the art,
- `Columns` of type `int`, the number of columns in the art,
- `A Value at which the animation stops` of type `int`, it is not related to type but to the loop,
- `Speed` of type `macro`, the available options are `FAST`, `MEDIUM` and `SLOW`,
- `Color` of type `macro`, the available options are `RED` and `GREEN`.
