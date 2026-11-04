struct G_002CA6E8 {
    char pad[0xB8];
    int mB8;
};

struct Scr_002CA6E8 {
    char pad[0x18];
    void* m18;
};

extern G_002CA6E8* D_00392808;
extern "C" void func_001E7360(void* p, unsigned int name, int v);

extern "C" bool func_002CA6E8(void* params, Scr_002CA6E8* s)
{
    int v = D_00392808->mB8;
    if (v) {
        func_001E7360(s->m18, 0x4C72ED98, v);
        return true;
    }
    return false;
}
