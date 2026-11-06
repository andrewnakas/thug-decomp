typedef int qword __attribute__((mode(TI)));

struct Row_0014E080 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Mat_0014E080 {
    Row_0014E080 r[4];
    Mat_0014E080& operator=(const Mat_0014E080& m)
    {
        r[0] = m.r[0];
        r[1] = m.r[1];
        r[2] = m.r[2];
        r[3] = m.r[3];
        return *this;
    }
};

struct Inst_0014E080 {
    Mat_0014E080 m0;
    void SetMatrix(Mat_0014E080 m) { m0 = m; }
};

extern "C" void func_001726E0(Inst_0014E080* o, int a);
extern "C" void func_00170490(void* o, int a);

struct Obj_0014E080 {
    char pad0[0x18];
    Inst_0014E080* m18;
    int m1C;
    void* m20;
    char pad24[0x30 - 0x24];
    Mat_0014E080 m30;
    bool Fn(const Mat_0014E080& m, int a, int n);
};

bool Obj_0014E080::Fn(const Mat_0014E080& m, int a, int n)
{
    if (m18) {
        if (n > 0)
            func_001726E0(m18, a);
        m18->SetMatrix(m);
    }
    if (m20) {
        m30 = m;
        if (n)
            func_00170490(m20, a);
    }
    return true;
}
