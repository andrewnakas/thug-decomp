typedef int qword __attribute__((mode(TI)));

struct Row_0014D170 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0014D170 {
    Row_0014D170 r[4];
    Mat_0014D170()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
    Mat_0014D170(const Mat_0014D170& o)
    {
        r[0].q = o.r[0].q; r[1].q = o.r[1].q; r[2].q = o.r[2].q; r[3].q = o.r[3].q;
    }
};

struct Arg_0014D170 {
    char pad0[8];
    int m8;
};

struct Src_0014D170 {
    char pad0[4];
    int m4;
    char pad8[0xC0 - 8];
    void* mC0;
};

struct Obj_0014D170 {
    char pad0[0x18];
    void* m18;
    Src_0014D170* m1C;
    void* m20;
    char pad24[0x30 - 0x24];
    char m30[0x40];
    int m70;
    int Init(Src_0014D170* src, Arg_0014D170* arg, int a3);
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" int func_00149BC8(int id);
extern "C" int func_0014C9A8(Arg_0014D170* arg);
extern "C" void* func_00170C30(void* p, void* dst, int n);
extern "C" void* func_00170CE0(void* p, void* dst, int n, int m, int z);
extern "C" void* func_001723A0(void* mem, int a, Mat_0014D170 m, int b);
extern "C" void* func_001724A8(void* mem, int a, Mat_0014D170 m, int b, int c, int d);

int Obj_0014D170::Init(Src_0014D170* src, Arg_0014D170* arg, int a3)
{
    int n = arg->m8;
    Mat_0014D170 m;
    m70 = func_0014C9A8(arg);
    if (src->mC0) {
        if (n) {
            m20 = func_00170CE0(src->mC0, m30, n, m70, 0);
        } else {
            m20 = func_00170C30(src->mC0, m30, 0);
        }
    } else {
        int id = func_00149BC8(src->m4);
        if (n) {
            m18 = func_001724A8(func_0010A638(D_00388A70, 0x80, 1, 0), id, m, a3, n, m70);
        } else {
            m18 = func_001723A0(func_0010A638(D_00388A70, 0x80, 1, 0), id, m, a3);
        }
    }
    m1C = src;
    return 1;
}
