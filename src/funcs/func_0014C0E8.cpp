/* sym: _$_13Base_0014C0E8 = 0x00132C48 */
/* sym: _vt$13Scrn_0014C0E8 = 0x0035F4E8 */
/* sym: _$_12Grp_0014C0E8 = 0x00134B50 */
extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

class Elem_0014C0E8 {
public:
    char pad[0x28];
    virtual ~Elem_0014C0E8();
};

class Grp_0014C0E8 {
public:
    int m0;
    ~Grp_0014C0E8();
};

struct Data_0014C0E8 {
    int m0;
    static void operator delete(void* p) { if (p) func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_00132A80(Grp_0014C0E8* g);
extern "C" Elem_0014C0E8* func_00132A90(Grp_0014C0E8* g, int a);
extern "C" void func_00135590(Elem_0014C0E8* e, int f);
extern "C" void func_00170BF0(Data_0014C0E8* d);

class Base_0014C0E8 {
public:
    char pad[0xD0];
    Grp_0014C0E8* mD0;
    char padD4[0x1AC];
    virtual ~Base_0014C0E8();
};

class Scrn_0014C0E8 : public Base_0014C0E8 {
public:
    char pad284[0x10];
    Data_0014C0E8* m294;
    virtual void V1();
    virtual ~Scrn_0014C0E8();
};

Scrn_0014C0E8::~Scrn_0014C0E8()
{
    if (m294) {
        func_00132A80(mD0);
        Elem_0014C0E8* e;
        while ((e = func_00132A90(mD0, 0)) != 0) {
            func_00135590(e, 0x40);
            delete e;
        }
        delete mD0;
        mD0 = 0;
        func_00170BF0(m294);
        delete m294;
    }
}
