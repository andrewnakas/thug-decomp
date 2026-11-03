extern "C" int func_003237F8(int a, int b, int c);

struct Strm1130B0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int Open(int mode);
};

extern "C" int func_00113000(Strm1130B0* s);

int Strm1130B0::Open(int mode)
{
    if (func_003237F8(m4, m8, mode)) {
        mC = 8;
        return 0;
    }
    int r = func_00113000(this);
    if (r == -4) {
        r = 0;
    }
    return r == 0;
}
