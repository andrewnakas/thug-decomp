extern void* D_0038EB78;
extern char D_00392128[];
extern "C" void* func_001FA640(void* m);
extern "C" int func_00326E30(void* p);
extern "C" void* func_001F92B8(void* m, int a, char* name, int b, int c, unsigned int flags);

struct Obj_002A2AE8;
extern "C" void func_002AB2E8(Obj_002A2AE8* o, int a);

struct Obj_002A2AE8 {
    char pad[0x18];
    void* m18[4];
    char pad2[0x30 - 0x28];
    int m30;
    char pad3[0xB4 - 0x34];
    int mB4;
    char pad4[0x15C - 0xB8];
    int m15C;
    char pad5[0x16C - 0x160];
    int m16C;
    char pad6[0x18C - 0x170];
    int m18C;
    char pad7[0x1A8 - 0x190];
    int m1A8;
    void* Create(int a, int b, int c, int idx);
};

void* Obj_002A2AE8::Create(int a, int b, int c, int idx)
{
    void* m = D_0038EB78;
    unsigned int flags = a != 0;
    if (b)
        flags |= 8;
    else
        flags |= 0x14;
    if (c)
        flags |= 0x20;
    m18[idx] = func_001F92B8(m, idx, D_00392128, 0x141F, func_00326E30(func_001FA640(m)), flags);
    if (idx == 0 && m18[0]) {
        m15C = 0;
        m16C = 0;
        m1A8 = 0;
        func_002AB2E8(this, 0);
    }
    mB4 = 0;
    m30 = 0;
    m18C = 0;
    return m18[idx];
}
