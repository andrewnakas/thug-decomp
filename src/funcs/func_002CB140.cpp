struct Color_002CB140 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

extern int D_00394188;
extern Color_002CB140 D_00394180;
extern char D_003928B8[];
extern char D_0037AD50[];
extern char D_0037AD60[];
extern "C" Color_002CB140* func_002BAA28(Color_002CB140* c, int a, int b, int d, int e, int f, int g);
extern "C" int func_001E8180(void* p, unsigned int key, void** out, int v);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int v);
extern "C" void func_002CABF0(Color_002CB140* out, void* p);
extern "C" int func_001E87B8(void* p, char* name);
extern "C" void* func_002C0368();
extern "C" bool func_002BFB80(void* p, Color_002CB140* c);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002CB050(Color_002CB140* c);

bool Cmd_002CB140(void* params)
{
    if (!D_00394188) {
        func_002BAA28(&D_00394180, 0, 0, 0, 0, 0, 0);
        D_00394188 = 1;
    }
    Color_002CB140 c;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    void* sub = 0;
    if (func_001E8180(params, 0xB4F88771, &sub, 0)) {
        int a, b, d, e;
        func_001E7DE8(sub, 0x7323E97C, &a, 0);
        func_001E7DE8(sub, 0x9D2D8850, &b, 0);
        func_001E7DE8(sub, 0xE39CF4ED, &d, 0);
        func_001E7DE8(sub, 0x69F93D01, &e, 0);
        c.m0 = a;
        c.m1 = 0;
        c.m2 = b;
        c.m3 = d;
        c.m4 = 1;
        c.m5 = e;
    } else {
        Color_002CB140 t;
        func_002CABF0(&t, params);
        c = t;
    }
    if (func_001E87B8(params, D_003928B8)) {
        D_00394180 = c;
    } else {
        if (func_001E87B8(params, D_0037AD50))
            c = D_00394180;
        {
            Color_002CB140 c2 = c;
            bool bad = !func_002BFB80(func_002C0368(), &c2);
            if (bad) {
                func_001F0370(D_0037AD60, 0, 0, 0);
                return false;
            }
        }
        {
            Color_002CB140 c3 = c;
            func_002CB050(&c3);
        }
    }
    return true;
}
