extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void* func_001200E0(void* p);
extern "C" int func_00123420(void* p);
extern "C" void func_00123288(void* p, void* s);

struct Goal_00261BC0 {
    int m_0;
    char m_4[0x4C - 0x4];
    char m_params[0x5C - 0x4C];
    char m_extra[0x10];
    void Save(void* out);
};

extern "C" int func_002623B8(Goal_00261BC0* self);
extern "C" unsigned int func_00262388(Goal_00261BC0* self);

void Goal_00261BC0::Save(void* out)
{
    void* s = func_001E6978(func_001190D0(8));
    func_001E7A68(s, 0x1902C8F0, 1, 2);
    if (!func_002623B8(this)) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E6AC8(p, m_params);
        func_001E7A68(s, 0x554C7D6F, 0xB, (int)p);
    }
    void* q = func_001200E0(m_4);
    if (q && func_00123420(q)) {
        void* p = func_001E6978(func_001190D0(8));
        func_00123288(q, p);
        func_001E7A68(s, 0xF0D3BC94, 0xB, (int)p);
    }
    void* e = func_001E6978(func_001190D0(8));
    func_001E6AC8(e, m_extra);
    func_001E7A68(s, 0x3476CEA8, 0xB, (int)e);
    unsigned int name = func_00262388(this);
    func_001E7A68(s, 0x95388A60, 1, 0);
    func_001E7A68(out, name, 0xB, (int)s);
}
