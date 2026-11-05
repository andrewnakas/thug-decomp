typedef int qword __attribute__((mode(TI)));

union Vec_002BB468 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    void Set3(float x, float y, float z)
    {
        f.x = x;
        f.y = y;
        f.z = z;
    }
    void Copy(const Vec_002BB468& o)
    {
        q = o.q;
    }
    void Add(const Vec_002BB468& o)
    {
        f.x += o.f.x;
        f.y += o.f.y;
        f.z += o.f.z;
        f.w += o.f.w;
    }
};

struct Mat_002BB468 {
    Vec_002BB468 r[4];
    void Ident()
    {
        r[0].f.x = 1.0f; r[0].f.y = 0.0f; r[0].f.z = 0.0f; r[0].f.w = 0.0f;
        r[1].f.x = 0.0f; r[1].f.y = 1.0f; r[1].f.z = 0.0f; r[1].f.w = 0.0f;
        r[2].f.x = 0.0f; r[2].f.y = 0.0f; r[2].f.z = 1.0f; r[2].f.w = 0.0f;
        r[3].f.x = 0.0f; r[3].f.y = 0.0f; r[3].f.z = 0.0f; r[3].f.w = 1.0f;
    }
};

struct Cell_002BB468;

struct Base_002BB468 {
    int m0;
    int m4;
    int m8;
    virtual Vec_002BB468 GetSize();
};

struct Cell_002BB468 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    Base_002BB468* m8;
};

struct Grid_002BB468 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    char pad6[0x30 - 6];
    unsigned int m30;
    void Place(Vec_002BB468* off, float ang);
};

extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;
extern "C" Cell_002BB468* func_002BB3B0(Grid_002BB468* g, int i);
extern "C" void* func_002B6CF8(Base_002BB468* n);
extern "C" void func_002B6EE8(void* n, Vec_002BB468* v, int a);
extern "C" void func_002B6F70(void* n, float a);
extern "C" Mat_002BB468* func_00100928(Mat_002BB468* out, float angle);
extern "C" void func_00323318(Mat_002BB468* a, Mat_002BB468* b, Mat_002BB468* out);

void Grid_002BB468::Place(Vec_002BB468* off, float ang)
{
    Vec_002BB468 c;
    c.f.x = m3 * D_00392610 * 0.5f;
    c.f.y = 0.0f;
    c.f.z = m5 * D_00392618 * 0.5f;
    c.f.w = 1.0f;
    for (unsigned int k = 0; k < m30; k++) {
        Cell_002BB468* cell = func_002BB3B0(this, k);
        Vec_002BB468 sz = cell->m8->GetSize();
        Vec_002BB468 p;
        p.Set3(cell->m0 * D_00392610 + sz.f.x * 0.5f - c.f.x, cell->m1 * D_00392614 - c.f.y, cell->m2 * D_00392618 + sz.f.z * 0.5f - c.f.z);
        Vec_002BB468* pp = &p;
        pp->f.w = 1.0f;
        Mat_002BB468 m;
        Mat_002BB468 rot;
        m.Ident();
        Vec_002BB468* r3 = &m.r[3];
        r3->Copy(p);
        func_00323318(&m, func_00100928(&rot, ang * 0.01745329425f), &m);
        r3->Add(*off);
        func_002B6EE8(func_002B6CF8(cell->m8), r3, 1);
        float a = cell->m3 * 90.0f + ang;
        func_002B6F70(func_002B6CF8(cell->m8), a);
    }
}
