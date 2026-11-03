extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_00229EB0(void* list);
extern "C" void* func_00229F48(void* list, int i);
extern "C" int func_00100030(int n);

struct C_001A7970 {
    int m_pad[7];
    int m1C;
    int m20[125];
    void* m214;
    void* m218;
    void Start(void* params);
};

extern "C" int func_001A6BA8(C_001A7970* self);
extern "C" void func_001A6AB8(C_001A7970* self, void* e);

void C_001A7970::Start(void* params)
{
    void* list;
    if (func_001E8708(params, 0x422E1FCE)) list = m214;
    else list = m218;
    int n = func_00229EB0(list);
    if (!n) return;
    if (n >= 2 && func_001A6BA8(this)) {
        func_001A6AB8(this, func_00229F48(list, func_00100030(n)));
    } else {
        func_001A6AB8(this, func_00229F48(list, 0));
    }
    m1C = (m1C | 0x10) & ~8;
}
