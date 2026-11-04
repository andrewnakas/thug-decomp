extern void* D_0038EB78;
extern "C" int func_00201288(void* w);
extern "C" void func_002D2CF8(void* p);
extern "C" void func_00303958();
extern "C" void func_001F9400(void* m, void* w);
extern "C" void func_001048F0(void* p);

struct Obj_002A37D8;
extern "C" int func_002A1A28(Obj_002A37D8* o);

struct Obj_002A37D8 {
    int m0;
    void* m4;
    char pad[0x14 - 0x8];
    void* m14;
    char pad2[0x84 - 0x18];
    void* m84;
    char pad3[0xA0 - 0x88];
    void* mA0;
    char pad4[0x168 - 0xA4];
    int m168;
    void Close();
};

void Obj_002A37D8::Close()
{
    void* m = D_0038EB78;
    if (m14) {
        if (!func_00201288(m14) && func_002A1A28(this)) {
            func_002D2CF8(m4);
            func_00303958();
        }
        func_001F9400(m, m14);
        func_001048F0(m84);
        func_001048F0(mA0);
        m14 = 0;
    }
    m168 &= ~1;
}
