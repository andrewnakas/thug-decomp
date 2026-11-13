typedef int qword __attribute__((mode(TI)));

struct Vec_00167F00 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Scale(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
};

struct Mat_00167F00;
extern "C" void func_00323318(Mat_00167F00* d, const Mat_00167F00* a, const Mat_00167F00* b);

struct Mat_00167F00 {
    Vec_00167F00 row[4];

    Mat_00167F00() {}
    const Vec_00167F00& operator[](int i) const { return row[i]; }
    Mat_00167F00(const Mat_00167F00& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
    }
    void Scale(const Vec_00167F00& s)
    {
        row[0].Scale(s.x);
        row[1].Scale(s.y);
        row[2].Scale(s.z);
    }
    Mat_00167F00& operator=(const Mat_00167F00& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
    Mat_00167F00 operator*(const Mat_00167F00& b) const
    {
        Mat_00167F00 t = *this;
        func_00323318(&t, &b, &t);
        return t;
    }
};

struct Obj_00167F00 {
    Mat_00167F00 m;
    Vec_00167F00 pos;
    char pad50[0x70 - 0x50];
    Mat_00167F00 m70;

    void Init();
};

extern Mat_00167F00 D_003E1080;
extern Mat_00167F00 D_003E1240;
extern Mat_00167F00 D_003E1500;

void Obj_00167F00::Init()
{
    m = D_003E1080;
    m.row[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    pos.Set(0.0f, 0.0f, 0.0f, 1.0f);
    Mat_00167F00 tmp = m;
    Vec_00167F00 s;
    s.Set(0.0625f, 0.0625f, 0.0625f, 1.0f);
    tmp.Scale(s);
    m70 = tmp * D_003E1240 * D_003E1500;
}
