extern "C" int func_002A19A8(void* net);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001841F0(void* obj, void* s);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void func_00183CB8(void* obj, void* ref);
extern void* D_00392068;
extern void* D_00389A30;

struct Ref_001BBD98 {
    void* p;
    Ref_001BBD98(const Ref_001BBD98& o);
    ~Ref_001BBD98()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
};

extern "C" Ref_001BBD98 func_0012DB48(void* mgr, unsigned int name, int flags);

int func_001BBD98()
{
    if (!func_002A19A8(D_00392068)) return 0;
    if (func_0012DB48(D_00389A30, 0x2EDB780F, 0).p) return 1;
    void* obj = func_0012DB48(D_00389A30, 0x56A1EAE3, 0).p;
    if (obj) {
        void* s = func_001E6978(func_001190D0(8));
        func_001841F0(obj, s);
        unsigned int type;
        func_001E8398(s, 0xCDC00E63, &type, 0);
        if (s) func_001E6AE8(s, 3);
        if (type == 0xF649D637) return 1;
    }
    void* last = func_0012DB48(D_00389A30, 0x31631B98, 0).p;
    return last != 0;
}
