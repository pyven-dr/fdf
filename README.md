
# FDF

### This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

## Screenshots

![42fdf](https://github.com/pyven-dr/fdf/assets/150053673/8ab6378c-46ca-44d0-89d2-f19ff3656c3c)

![t1fdf](https://github.com/pyven-dr/fdf/assets/150053673/2690666c-9eed-480a-b726-8728985692b7)

![juliafdf](https://github.com/pyven-dr/fdf/assets/150053673/c474a53f-3b96-4ce1-b5f3-97def94632a4)

## How to use

Clone the project
```bash
git clone https://github.com/pyven-dr/fdf.git
```

Compile
```bash
make
```

Launch with a map
```bash
./fdf map.fdf
```

## Map example

```bash
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

## Controls


| Key                   | Action                                   |
| :--------             | :-------                                 |
| `Arrows`              | `Translation`                            |
| `Q/E`                 | `Z axis rotation`                        |
| `W/S`                 | `X axis rotation`                        |
| `A/D`                 | `Y axis rotation`                        |
| `Mouse (Left Click)`  | `Rotation`                               |
| `Mouse (Right Click)` | `Translation`                            |
| `Mouse Scroll`        | `Zoom`                                   |
| `Space`               | `Change projection (Isometric/Cavalier)` |
| `Left alt`            | `Show lines ON/OFF`                      |
| `R/F`                 | `Change points height`                   |
| `ESC`                 | `Close the window`                       |
