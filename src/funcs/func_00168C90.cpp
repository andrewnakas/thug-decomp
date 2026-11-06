typedef int qword __attribute__((mode(TI)));

struct Vec_00168C90 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Mat_00168C90 {
    Vec_00168C90 r[4];
};

extern Mat_00168C90 D_003E13C0;
extern char D_3A8[];
extern "C" void func_00164E48(unsigned int eop, unsigned int prim);
extern "C" void func_00164F48(const Mat_00168C90* m);
extern "C" void func_00164EB8(unsigned int eop);

void func_00168C90(float t)
{
    Mat_00168C90 m = D_003E13C0;
    m.r[0].z += m.r[0].w * t * 64.0f;
    m.r[1].z += m.r[1].w * t * 64.0f;
    m.r[2].z += m.r[2].w * t * 64.0f;
    m.r[3].z += m.r[3].w * t * 64.0f;
    func_00164E48(0, (unsigned int)D_3A8 >> 3);
    func_00164F48(&m);
    func_00164EB8(0);
}
