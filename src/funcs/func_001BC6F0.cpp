extern "C" void* func_001190D0(unsigned int size);

class Struct1E6978 {
public:
    int m_w[2];
    Struct1E6978();
    ~Struct1E6978();
    static void* operator new(unsigned int size) { return func_001190D0(size); }
};

class Obj_001BC6F0 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void Run(Struct1E6978* params);
};

struct Handle_001BC6F0;
extern "C" void func_00183CB8(Obj_001BC6F0* o, Handle_001BC6F0* h);

struct Handle_001BC6F0 {
    Obj_001BC6F0* m_obj;
    Handle_001BC6F0* m_prev;
    Handle_001BC6F0* m_next;
    ~Handle_001BC6F0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    operator Obj_001BC6F0*() const { return m_obj; }
};

struct Pos_001BC6F0 {
    char pad[0x50];
    float x, y, z;
};

extern "C" void func_001E7360(Struct1E6978* s, unsigned int name, int v);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001E70C0(Struct1E6978* s, unsigned int name, const char* v);
extern "C" void func_001E7410(Struct1E6978* s, unsigned int name, float x, float y, float z);
extern "C" Handle_001BC6F0 func_0012DB48(void* mgr, int id, int a);
extern "C" void func_001F0210(unsigned int type, Struct1E6978* s, int a, int b, int c);
extern char D_0038D5B0[];
extern void* D_00389A30;

struct C_001BC6F0 {
    char pad[0xC];
    Pos_001BC6F0* mC;
    char pad10[0xC];
    char m1C[0x40];
    int m5C;
    float m60;
    int m64;
    void Send();
};

void C_001BC6F0::Send()
{
    Struct1E6978* s = new Struct1E6978;
    func_001E7360(s, 0x40C698AF, m64);
    char buf[64];
    func_003331D0(buf, D_0038D5B0, m5C, m1C);
    func_001E70C0(s, 0xC4745838, buf);
    func_001E7410(s, 0x4B491900, mC->x, mC->y + m60, mC->z);
    Obj_001BC6F0* o = func_0012DB48(D_00389A30, m64, 0);
    if (o)
        o->Run(s);
    else
        func_001F0210(0x6A060CF0, s, 0, 0, 0);
    delete s;
}
