/* fuzzy: 71.7 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00207750 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00207750;
extern "C" void func_00323318(Mat_00207750* d, const Mat_00207750* a, Mat_00207750* b);

struct Mat_00207750 {
    Vec_00207750 r[4];
    Mat_00207750() {}
    Mat_00207750(const Mat_00207750& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
    }
    Mat_00207750& operator=(const Mat_00207750& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Mat_00207750& operator*=(const Mat_00207750& b)
    {
        func_00323318(this, &b, this);
        return *this;
    }
    Mat_00207750 operator*(const Mat_00207750& b) const
    {
        Mat_00207750 t;
        t = *this;
        t *= b;
        return t;
    }
};

void func_00207750(const Mat_00207750& a, const Mat_00207750& b)
{
    Mat_00207750 r;
    r = a * b;
}
