typedef int qword_00259480 __attribute__((mode(TI)));

struct Vec_00259480 {
    union {
        struct { float x, y, z, w; };
        qword_00259480 q;
    };
};

extern "C" void* func_00229EB0(int node);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" bool func_001A6BA8(void* comp);
extern "C" void* func_00100030(void* p);
extern "C" int func_00229F48(int node, void* p);

struct Obj_00259480;
extern "C" void func_00259428(Obj_00259480* self);

struct Obj_00259480 {
    char m_pad0[0x20];
    void* m20;
    char m_pad24[0x4C];
    int m70;
    int m74;
    char m_pad78[0x8];
    Vec_00259480 m80;
    Vec_00259480 m90;
    bool Advance();
};

bool Obj_00259480::Advance()
{
    void* n = func_00229EB0(m74);
    if (!n)
        return false;
    m70 = m74;
    if (func_001A6BA8(func_00185578(m20, 0x0A015E17)))
        m74 = func_00229F48(m74, func_00100030(n));
    else
        m74 = func_00229F48(m74, 0);
    m80 = m90;
    func_00259428(this);
    return true;
}
