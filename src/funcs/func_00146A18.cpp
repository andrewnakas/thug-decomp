typedef int qword __attribute__((mode(TI)));

struct Vec_00146A18 {
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
};

struct Mat_00146A18;
extern "C" void func_00323318(Mat_00146A18* d, const Mat_00146A18* a, Mat_00146A18* b);
extern "C" Mat_00146A18* func_00100928(Mat_00146A18* out, float a);

struct Mat_00146A18 {
    Vec_00146A18 r[4];
    Mat_00146A18() {}
    const Vec_00146A18& operator[](int i) const { return r[i]; }
    Mat_00146A18(const Mat_00146A18& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_00146A18 operator*(const Mat_00146A18& b) const;
};

inline Mat_00146A18 Mat_00146A18::operator*(const Mat_00146A18& b) const
{
    Mat_00146A18 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

class Obj_00146A18 {
public:
    char pad[0x40];
    Mat_00146A18 m_mat;
    void Turn(int quarters);
};

extern "C" void func_00146B18(Obj_00146A18* self);

void Obj_00146A18::Turn(int quarters)
{
    Mat_00146A18 m = m_mat;
    Mat_00146A18 r;
    func_00100928(&r, (float)quarters * 1.57079637f);
    Vec_00146A18 v;
    v.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m.r[3] = v;
    r = m * r;
    m_mat.r[0] = r.r[0];
    m_mat.r[1] = r.r[1];
    m_mat.r[2] = r.r[2];
    func_00146B18(this);
}
