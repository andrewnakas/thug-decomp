struct Mat_0012AC20 {
    float m[4][4];
};

extern "C" Mat_0012AC20* func_00100890(Mat_0012AC20* out, float a);
extern "C" Mat_0012AC20* func_00100928(Mat_0012AC20* out, float a);
extern "C" Mat_0012AC20* func_001009C0(Mat_0012AC20* out, float a);
extern "C" void func_00323318(Mat_0012AC20* d, Mat_0012AC20* a, Mat_0012AC20* b);

extern "C" void func_0012AC20(Mat_0012AC20* m, unsigned int order, float x, float y, float z)
{
    Mat_0012AC20 t;
    switch (order) {
    case 0:
        func_00323318(m, func_00100890(&t, x), m);
        func_00323318(m, func_00100928(&t, y), m);
        func_00323318(m, func_001009C0(&t, z), m);
        break;
    case 1:
        func_00323318(m, func_00100890(&t, x), m);
        func_00323318(m, func_001009C0(&t, z), m);
        func_00323318(m, func_00100928(&t, y), m);
        break;
    case 2:
        func_00323318(m, func_00100928(&t, y), m);
        func_00323318(m, func_00100890(&t, x), m);
        func_00323318(m, func_001009C0(&t, z), m);
        break;
    case 3:
        func_00323318(m, func_00100928(&t, y), m);
        func_00323318(m, func_001009C0(&t, z), m);
        func_00323318(m, func_00100890(&t, x), m);
        break;
    case 4:
        func_00323318(m, func_001009C0(&t, z), m);
        func_00323318(m, func_00100890(&t, x), m);
        func_00323318(m, func_00100928(&t, y), m);
        break;
    case 5:
        func_00323318(m, func_001009C0(&t, z), m);
        func_00323318(m, func_00100928(&t, y), m);
        func_00323318(m, func_00100890(&t, x), m);
        break;
    }
}
