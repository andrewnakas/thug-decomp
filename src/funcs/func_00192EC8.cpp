/* sym: _$_13Base_00192EC8 = 0x00184DD8 */
/* sym: _vt$12Der_00192EC8 = 0x00362140 */
/* sym: _$_12Sub_00192EC8 = 0x001DA8C0 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00183CB8(void* p, void** ref);

static inline void Release_00192EC8(void** pp)
{
    if (*pp) {
        func_00183CB8(*pp, pp);
        *pp = 0;
    }
}

struct Wheel_00192EC8 {
    char pad0[0x200];
    void* m200;
    char pad204[0x220 - 0x204];
    ~Wheel_00192EC8() { Release_00192EC8(&m200); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

class Sub_00192EC8 {
public:
    char m0[0x10];
    ~Sub_00192EC8();
};

class Base_00192EC8 {
public:
    char pad0[0x18];
    virtual void F();
    virtual ~Base_00192EC8();
};

class Der_00192EC8 : public Base_00192EC8 {
public:
    char pad1C[0x318 - 0x1C];
    Wheel_00192EC8* m318;
    char pad31C[0x360 - 0x31C];
    Sub_00192EC8 m360;
    virtual void F();
    virtual ~Der_00192EC8();
};

Der_00192EC8::~Der_00192EC8()
{
    if (m318)
        delete[] m318;
}
