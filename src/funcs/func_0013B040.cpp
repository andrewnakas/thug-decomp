struct Ref_0013B040;
extern "C" void func_00183CB8(void* tex, Ref_0013B040* ref);
extern "C" void func_00183C98(void* tex, Ref_0013B040* ref);

struct Ref_0013B040 {
    void* p;
    void Set(void* t)
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
        p = t;
        if (t)
            func_00183C98(t, this);
    }
};

struct Mat_0013B040 {
    char pad[0x18];
    Ref_0013B040 m18;
};

extern int* D_0038A0E4;
extern Mat_0013B040* D_004653C0[];
extern "C" void func_00114B50(Mat_0013B040* m);

extern "C" void func_0013B040(int index, void* tex)
{
    int slot = D_0038A0E4[index];
    if (slot == -1)
        return;
    Mat_0013B040* m = D_004653C0[slot];
    func_00114B50(m);
    m->m18.Set(tex);
}
