typedef int qword_001A6EF0 __attribute__((mode(TI)));

struct Row_001A6EF0 {
    qword_001A6EF0 q;
};

struct Mat_001A6EF0 {
    Row_001A6EF0 r[4];
    Mat_001A6EF0() {}
    Mat_001A6EF0(const Mat_001A6EF0& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
    }
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" void* func_00102FD0(void* p);
extern "C" void func_00103000(void* anim, void* mat, Mat_001A6EF0 target);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

struct Model_001A6EF0 {
    char pad[0x70];
    char m70[0x40];
};

struct Obj_001A6EF0 {
    char pad[0xC];
    Model_001A6EF0* mC;
    char pad10[0xC];
    int m1C;
    char pad20[0x1F4 - 0x20];
    float m1F4;
    float m1F8;
    void* m1FC;
    void Method(void* params, Mat_001A6EF0* target);
};

void Obj_001A6EF0::Method(void* params, Mat_001A6EF0* target)
{
    if (!m1FC)
        m1FC = func_00102FD0(func_0010A638(D_00388A70, 0xA0, 1, 0));
    func_00103000(m1FC, mC->m70, *target);
    m1F8 = 0.0f;
    m1F4 = 0.0f;
    func_001E7EB0(params, 0x906B67BA, &m1F4, 0);
    m1C |= 0x20;
}
