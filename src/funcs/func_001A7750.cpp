typedef int qword __attribute__((mode(TI)));

struct Vec_001A7750 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_001A7750 {
    Vec_001A7750 r[4];
    Mat_001A7750() {}
    const Vec_001A7750& operator[](int i) const { return r[i]; }
    Mat_001A7750(const Mat_001A7750& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_001A7750& operator=(const Mat_001A7750& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_001A7750 operator*(Mat_001A7750& b);
};

extern "C" void func_00323318(Mat_001A7750* d, Mat_001A7750* a, Mat_001A7750* b);
extern "C" Mat_001A7750* func_00100890(Mat_001A7750* m, float angle);
extern "C" Mat_001A7750* func_00100928(Mat_001A7750* m, float angle);
extern "C" Mat_001A7750* func_001009C0(Mat_001A7750* m, float angle);
extern "C" Mat_001A7750* func_00100DC0(Mat_001A7750* m, int axis);

inline Mat_001A7750 Mat_001A7750::operator*(Mat_001A7750& b)
{
    Mat_001A7750 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Obj_001A7750 {
    char pad0[0x70];
    Mat_001A7750 m_mat;
};

struct C_001A7750 {
    char pad0[0xC];
    Obj_001A7750* m_obj;
    void Rotate(int axis, float angle);
};

void C_001A7750::Rotate(int axis, float angle)
{
    switch (axis) {
    case 0: {
        Obj_001A7750* o = m_obj;
        Mat_001A7750 r;
        o->m_mat = *func_00100890(&r, angle) * o->m_mat;
        func_00100DC0(&m_obj->m_mat, 0);
        break;
    }
    case 1: {
        Obj_001A7750* o = m_obj;
        o->m_mat = *func_00100928((Mat_001A7750*)0x70003FC0, angle) * o->m_mat;
        func_00100DC0(&m_obj->m_mat, 1);
        break;
    }
    case 2: {
        Obj_001A7750* o = m_obj;
        Mat_001A7750 r;
        o->m_mat = *func_001009C0(&r, angle) * o->m_mat;
        func_00100DC0(&m_obj->m_mat, 2);
        break;
    }
    }
}
