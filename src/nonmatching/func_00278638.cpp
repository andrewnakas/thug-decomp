/* fuzzy: 95.2 */
class Ptr_00278638;

extern "C" void func_00183CB8(void* p, Ptr_00278638* ref);

class Ret_00278638 {
public:
    void* m_ptr;
    Ptr_00278638* m_prev;
    Ptr_00278638* m_next;

    Ret_00278638(const Ret_00278638& other);
    ~Ret_00278638()
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, (Ptr_00278638*)this);
            m_ptr = 0;
        }
    }
    operator void*() const { return m_ptr; }
};

class Handler_00278638 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void Handle(void* params);
};

struct Conn_00278638 {
    char pad0[0x30];
    int m30;
};

struct Sk_00278638 {
    char pad0[0x18];
    int m18;
    char pad1C[0x50 - 0x1C];
    float m50;
    float m54;
    float m58;
};

struct Net_00278638;
extern Net_00278638* D_00392068;
extern void* D_0038FC78;
extern void* D_00389A30;
extern char D_00391998[];

extern "C" int func_002A19A8(Net_00278638* n);
extern "C" int func_002A78C0(Net_00278638* n);
extern "C" int func_00206A00(Sk_00278638* s);
extern "C" Conn_00278638* func_002A52F0(Net_00278638* n, unsigned short id);
extern "C" Conn_00278638* func_002A49B0(Net_00278638* n);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, int value);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" char* func_00206A08(Sk_00278638* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" Ret_00278638 func_0012DB48(void* mgr, int id, int v);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

class Base_00278638 {
public:
    int m0;
    int m4;
    int m8;
    Sk_00278638* mC;
    int m10;
    int m14;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int v);
};

class Obj_00278638 : public Base_00278638 {
public:
    int m1C;
    void Fn();
};

void Obj_00278638::Fn()
{
    if (!func_002A19A8(D_00392068) || !func_002A78C0(D_00392068)) {
        V6(1);
        return;
    }
    if (!func_00206A00(mC))
        return;
    float off = 120.0f;
    Conn_00278638* c = func_002A52F0(D_00392068, mC->m18);
    if (func_002A49B0(D_00392068) == c)
        off = 96.0f;
    void* p = func_001E6978(func_001190D0(8));
    func_001E7360(p, 0x40C698AF, m1C);
    int num;
    if (func_0024F540(func_0022E358(D_0038FC78)))
        num = c->m30 + 2;
    else
        num = mC->m18 + 2;
    char buf[0x40];
    func_003331D0(buf, D_00391998, num, func_00206A08(mC));
    func_001E70C0(p, 0xC4745838, buf);
    func_001E7410(p, 0x4B491900, mC->m50, mC->m54 + off, mC->m58);
    void* o = func_0012DB48(D_00389A30, m1C, 0);
    if (o)
        ((Handler_00278638*)o)->Handle(p);
    else
        func_001F0210(0x6A060CF0, p, 0, 0, 0);
    if (p)
        func_001E6AE8(p, 3);
}
