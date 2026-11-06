/* fuzzy: 64.7 */
/* nonmatch func_002CD5F0: best earlier draft (thug-claude-lane3/work/w53/p7/func_002CD5F0.fail), 68 of 139 words differ. */
struct Color_002CD5F0 {
    unsigned char m0;
    signed char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    void Set(unsigned char a, signed char b, unsigned char d)
    {
        m0 = a;
        m1 = b;
        m2 = d;
    }
};

struct Def_002CD5F0 {
    Color_002CD5F0 m0;
    char pad6[2];
    int m8;
    int mC;
    char pad10[0x24];
    unsigned int m34;
};

struct Node_002CD5F0 {
    int m0;
    int m4;
    unsigned char m8;
    signed char m9;
    unsigned char mA;
    char padB;
    int mC;
    unsigned char m10;
    unsigned char m11;
    char pad12[6];
    Node_002CD5F0* m18;
};

struct Obj_002CD5F0;

extern "C" void* func_002CE5C8(unsigned int size);
extern "C" Node_002CD5F0* func_002CC8A8(void* p);
extern "C" void* func_002C0368();
extern "C" int func_002BE5F0(void* p, unsigned int key, int v);
extern "C" int func_002C4750();
extern "C" int func_002C4770();
extern "C" int func_002CD820(Obj_002CD5F0* o, unsigned char a, signed char b, unsigned char d);
extern "C" void func_002CD5A0(Obj_002CD5F0* o, unsigned char a, unsigned char b);

struct Obj_002CD5F0 {
    char pad0[0xC];
    Node_002CD5F0* mC;
    bool Add(Def_002CD5F0* def, int delta);
};

bool Obj_002CD5F0::Add(Def_002CD5F0* def, int delta)
{
    Color_002CD5F0 c = def->m0;
    c.Set(c.m0, c.m1 + delta, c.m2);
    if ((def->m8 >> 3) & 1) {
        c.Set(c.m0, c.m1 + 1, c.m2);
        if (c.m1) {
            if (!func_002CD820(this, c.m0, c.m1, c.m2))
                return false;
        }
    }
    int id = func_002BE5F0(func_002C0368(), def->m34, 0);
    for (Node_002CD5F0* n = mC; n; n = n->m18) {
        if (n->m4 == id && n->m8 == c.m0 && n->m9 == c.m1 && n->mA == c.m2 && n->m10 == c.m3 &&
            n->m11 == c.m5 && n->mC == def->mC)
            return true;
    }
    if (func_002C4750() == func_002C4770())
        return false;
    Node_002CD5F0* n = func_002CC8A8(func_002CE5C8(0x1C));
    n->m4 = id;
    n->m8 = c.m0;
    n->m9 = c.m1;
    n->mA = c.m2;
    n->m10 = c.m3;
    n->m11 = c.m5;
    func_002CD5A0(this, c.m0, c.m2);
    func_002CD5A0(this, c.m0 + c.m3 - 1, c.m2 + c.m5 - 1);
    n->mC = def->mC;
    n->m18 = mC;
    mC = n;
    return true;
}
