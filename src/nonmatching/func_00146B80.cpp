/* fuzzy: 83.7 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00146B80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00146B80 {
    Vec_00146B80 r[4];
    Mat_00146B80() {}
    const Vec_00146B80& operator[](int i) const { return r[i]; }
    Mat_00146B80(const Mat_00146B80& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

struct Rgba_00146B80 {
    unsigned char r, g, b, a;
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00170C30(void* src, Mat_00146B80* m, int a);

class B_00146B80 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    Vec_00146B80 m10;
    int m20;
    int m24;
    virtual void v0();
};

class C_00146B80 : public B_00146B80 {
public:
    void* m30;
    Mat_00146B80 m40;
    Rgba_00146B80 m80;
    int m84;
    int m88;
    virtual void v0();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    C_00146B80* Clone(int a);
};

C_00146B80* C_00146B80::Clone(int a)
{
    C_00146B80* c = new C_00146B80(*this);
    if (c && m30) {
        c->m30 = func_00170C30(m30, &c->m40, 0);
    }
    return c;
}
