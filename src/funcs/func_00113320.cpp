extern "C" int func_003241C0(int a, int b, int c);

struct Strm113320 {
    int m0;
    int m4;
    int m8;
    int mC;
    int Open(int mode);
};

extern "C" int func_00113000(Strm113320* s);

int Strm113320::Open(int mode)
{
    if (func_003241C0(m4, m8, mode)) {
        mC = 8;
        return 0;
    }
    int r = func_00113000(this);
    if (r == -4) {
        r = 0;
    }
    return r == 0;
}
