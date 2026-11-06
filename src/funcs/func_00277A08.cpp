extern "C" void func_002369D0(void* p);
extern "C" int func_00263BD8(void* p, unsigned int name);
extern "C" void* func_001E53A0(unsigned int name, int a);
extern "C" void func_00263C18(void* p, void* q);
extern "C" void func_00238058(void* p);
extern int D_00390EF8;

struct Game_00277A08 {
    char pad[0x24];
    void* m24;
};

extern Game_00277A08* D_0038FC78;

struct Info_00277A08 {
    char pad[0x230];
    int m230;
    char pad2[0x31C - 0x234];
    int m31C;
};

class Base_00277A08 {
public:
    int m0;
    int m4;
    int m8;
    Info_00277A08* mC;
    int m10;
    int m14;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int a);
};

class Obj_00277A08 : public Base_00277A08 {
public:
    void* m1C;
    void Run();
};

void Obj_00277A08::Run()
{
    if (!mC->m31C) {
        V6(1);
        return;
    }
    func_002369D0(m1C);
    if (mC->m230 || func_00263BD8(D_0038FC78->m24, 0xEEFECF1B)) {
        void* list = D_0038FC78->m24;
        func_00263C18(list, func_001E53A0(0xEEFECF1B, 0));
        func_00238058(m1C);
        D_00390EF8 = 1;
    }
}
