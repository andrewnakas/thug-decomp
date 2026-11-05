extern void* D_00388A70;
extern int D_00392754;
extern "C" void func_002B7320(void* p, int v);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002BC970 {
    void* m0;
    char pad4[0x7C - 4];
    int m7C;
    char pad80[0x6A60 - 0x80];
    void* m6A60;
    void Destroy(int flags);
};

void Obj_002BC970::Destroy(int flags)
{
    if (m7C)
        m7C = 0;
    if (m0)
        func_002B7320(m0, 3);
    func_0010A8D8(D_00388A70, m6A60);
    D_00392754 = 0;
    if (flags & 1)
        func_0010A8D8(D_00388A70, this);
}
