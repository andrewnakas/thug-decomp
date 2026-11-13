/* fuzzy: 67.8 */
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
    Mat_00167F00(const Mat_00167F00& o)
    {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
    }
    Mat_00167F00& operator=(const Mat_00167F00& o)
    {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
        return *this;
    }
    Mat_00167F00 Mul(const Mat_00167F00& b)
    {
        func_00323318(this, &b, this);
        return *this;
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
    Mat_00167F00 tmp;
    Vec_00167F00 s;
    Vec_00167F00* ps = &s;
    ps->Set(0.0625f, 0.0625f, 0.0625f, 1.0f);
    tmp = m;
    Vec_00167F00* r0 = &tmp.row[0];
    Vec_00167F00* r1 = &tmp.row[1];
    Vec_00167F00* r2 = &tmp.row[2];
    r0->Scale(s.x);
    r1->Scale(s.y);
    r2->Scale(s.z);
    Mat_00167F00 r(tmp);
    Mat_00167F00* pr = &r;
    *pr = pr->Mul(D_003E1240);
    m70 = pr->Mul(D_003E1500);
}
