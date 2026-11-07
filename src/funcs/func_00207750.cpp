typedef int qword __attribute__((mode(TI)));

struct Row_00207750 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00207750 {
    Row_00207750 r[4];
    Mat_00207750() {}
    const Row_00207750& operator[](int i) const { return r[i]; }
    Mat_00207750(const Mat_00207750& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

extern "C" void func_00323318(Mat_00207750* d, const Mat_00207750* a, const Mat_00207750* b);

static inline Mat_00207750 operator*(const Mat_00207750& a, const Mat_00207750& b)
{
    Mat_00207750 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

void func_00207750(const Mat_00207750& a, const Mat_00207750& b)
{
    Mat_00207750 r;
    r = b * a;
}
