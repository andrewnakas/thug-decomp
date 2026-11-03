typedef int qword __attribute__((mode(TI)));

struct Row {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat {
    Row r[4];
    Mat() {}
    const Row& operator[](int i) const { return r[i]; }
    Mat(const Mat& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

struct Vec {
    float x, y, z, w;
};

extern "C" Mat* func_00100890(Mat* out, float a);
extern "C" Mat* func_00100928(Mat* out, float a);
extern "C" Mat* func_001009C0(Mat* out, float a);
extern "C" void func_00323318(Mat* dst, const Mat* a, const Mat* b);

static inline Mat operator*(const Mat& a, const Mat& b)
{
    Mat r = b;
    func_00323318(&r, &a, &r);
    return r;
}

extern "C" void func_00101238(Mat* m, const Vec* ang)
{
    if (ang->x != 0.0f) {
        Mat tmp;
        *m = *m * *func_00100890(&tmp, ang->x);
    }
    if (ang->y != 0.0f) {
        *m = *m * *func_00100928((Mat*)0x70003FC0, ang->y);
    }
    if (ang->z != 0.0f) {
        Mat tmp;
        *m = *m * *func_001009C0(&tmp, ang->z);
    }
}
