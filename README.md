# ANIASCII

`ANIASCII` is a c library for animation of `ascii` arts.Try the `example.c` first `cd` ( change directory ) to `animation_in_c` and execute the following commands,

Check out the video on [YOUTUBE 🔗🔗](https://www.youtube.com/watch?v=VaIm3Gz-rxA).

![animation in c](https://raw.githubusercontent.com/surajkareppagol/Assets/main/1%20-%20AniASCII/ANIASCII.gif)

---

```bash
make
make run
```

```bash
make clean
```

## How to use it?

There is a single function `animateAscii()`, the parameters are as follows,

```c
animateAscii(&choice, &rows, &columns, artOne, artTwo, 100, 10);
```

- `Choice Of animation` is a pointer pointing to `int` type,
- `Rows` is a pointer pointing to `int` type, the number of rows in the art,
- `Columns` is a pointer pointing to `int` type, the number of columns in the art,
- `First Art` is a pointer pointing to `2D array`,
- `Second Art` is a pointer pointing to `2D array`,
- `Speed` of type `int`, i.e 1000 = 1s,
- `column gap` of type `int`

To set color use `setColor()` function before calling the `animateAscii()`,

`setColor()` takes two macro parameters which are defined by `ncurses` library.

```c
setColor(COLOR_BLUE, COLOR_WHITE);
```
