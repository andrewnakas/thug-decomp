extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* pool, int size, int a, int b);
extern "C" int func_0010FC30();
extern "C" int func_00209A00(void* src);
extern "C" void* func_00209A30(void* src);

struct Ref_001CE768;
extern "C" void func_00183CB8(void* p, Ref_001CE768* ref);
extern "C" Ref_001CE768* func_0020A6C0(void* mem, void* target);

struct Ref_001CE768 {
    void* m_p;

    void Release()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Obj_001CE768 {
    char pad[0x1C];
    Ref_001CE768* m_ref;
    int m_time;

    bool Valid()
    {
        if (m_ref) {
            if (!m_ref->m_p) {
                func_0010A8D8(D_00388A70, m_ref);
                m_ref = 0;
                m_time = func_0010FC30();
                return false;
            }
            return true;
        }
        return false;
    }
    void Clear()
    {
        if (m_ref) {
            Ref_001CE768* r = m_ref;
            r->Release();
            func_0010A8D8(D_00388A70, r);
            m_ref = 0;
            m_time = func_0010FC30();
        }
    }
    bool Set(void* src);
};

bool Obj_001CE768::Set(void* src)
{
    if (func_00209A00(src)) {
        if (Valid()) {
            void* cur = m_ref->m_p;
            if (cur != func_00209A30(src)) {
                Clear();
            }
        }
        if (!Valid()) {
            void* mem = func_0010A638(D_00388A70, 0xC0, 1, 0);
            m_ref = func_0020A6C0(mem, func_00209A30(src));
            return true;
        }
        return false;
    }
    if (Valid()) {
        Clear();
    }
    return false;
}
