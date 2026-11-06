typedef int qword_001B8148 __attribute__((mode(TI)));

struct Row_001B8148 {
    qword_001B8148 q;
};

struct Mat_001B8148 {
    Row_001B8148 r[4];
    Mat_001B8148() {}
    const Row_001B8148& operator[](int i) const { return r[i]; }
    Mat_001B8148(const Mat_001B8148& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    void Method(float a);
};

extern "C" Mat_001B8148* func_00100890(Mat_001B8148* m, float a);
extern "C" void func_00323318(Mat_001B8148* out, const Mat_001B8148* a, const Mat_001B8148* b);

static inline Mat_001B8148 operator*(const Mat_001B8148& a, const Mat_001B8148& b)
{
    Mat_001B8148 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

void Mat_001B8148::Method(float a)
{
    Mat_001B8148 tmp;
    *this = *this * *func_00100890(&tmp, a);
}
