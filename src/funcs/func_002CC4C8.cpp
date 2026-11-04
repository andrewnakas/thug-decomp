struct Item_002CC4C8 {
    char pad0[0xC];
    int mC[2];
    char pad14[0xC0 - 0x14];
    char mC0[0x20];
    int mE0;
    int Key(int n) { return mC[n]; }
};

extern char D_0037AED8[];
extern char D_0037AEE8[];
extern char D_0037AF08[];
extern "C" int func_001E5648(char* name, int v);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);

struct Obj_002CC4C8 {
    int m0;
    Item_002CC4C8* m4[32];
    int m84[32];
    int Find(int key);
};

int Obj_002CC4C8::Find(int key)
{
    for (int i = 0; i < 32; i++) {
        if (m4[i] && m4[i]->Key(!m84[i]) == key) {
            if (i & 1) {
                if (func_001E5648(D_0037AED8, 0))
                    func_00103F28(D_0037AEE8, m4[i]->mE0, m4[i]->mC0);
            }
            char buf[48];
            func_003331D0(buf, D_0037AF08, i);
            return func_001F0D78(buf);
        }
    }
    return 0;
}
