extern "C" void func_0011F930(void* dst, void* src);
extern "C" void func_001E6A00(void* dst, void* src);

struct Obj_002610C0 {
    int m0;
    char m4[0x58];
    char m5C[4];
    Obj_002610C0& operator=(Obj_002610C0& o);
};

Obj_002610C0& Obj_002610C0::operator=(Obj_002610C0& o)
{
    if (&o == this) return o;
    func_0011F930(m4, o.m4);
    func_001E6A00(m5C, o.m5C);
    return *this;
}
