struct MemMgr_00261118 {
    char m_pad[0x3EC];
    void* m_heap;
};

extern MemMgr_00261118* D_00388A70;

extern "C" void func_0010A950(MemMgr_00261118* mgr, void* heap);
extern "C" void func_0010A9B0(MemMgr_00261118* mgr);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6B30(void* s);
extern "C" void func_00120120(void* p);
extern "C" void func_0011FA48(void* p);
extern "C" void func_001200E8(void* p);
extern "C" void func_0011FB18(void* p, int v, int a);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void* func_001E5548(unsigned int name, int a);

struct Goal_00261118 {
    int m_0;
    char m_4[0x5C - 0x4];
    char m_params[0x10];
    bool Init(void* params);
};

extern "C" int func_002623B8(Goal_00261118* self);

bool Goal_00261118::Init(void* params)
{
    func_0010A950(D_00388A70, D_00388A70->m_heap);
    func_00120120(m_4);
    func_0011FA48(m_4);
    func_001E6B30(m_params);
    func_001E7A68(m_params, 0xD544AA2D, 0xB, (int)func_001E6978(func_001190D0(8)));
    func_001E7A68(m_params, 0xDDBEE809, 0xB, (int)func_001E6978(func_001190D0(8)));
    func_0010A9B0(D_00388A70);
    if (params) {
        int v;
        func_001E8A30(params, 0x1D6F290C, &v, 1);
        func_0011FB18(m_4, v, 1);
        func_001E6B30(m_params);
        func_001E6AC8(m_params, params);
        if (!func_002623B8(this)) {
            func_0010A950(D_00388A70, D_00388A70->m_heap);
            func_001200E8(m_4);
            func_0010A9B0(D_00388A70);
        }
        unsigned int name;
        func_001E8398(params, 0xE365363E, &name, 1);
        void* src = func_001E5548(name, 1);
        void* dst;
        func_001E8180(m_params, 0xD544AA2D, &dst, 1);
        func_001E6B30(dst);
        func_001E6AC8(dst, src);
    }
    return true;
}
