struct Sub_0017AEC0 {
    int m0[4];
    unsigned int m10;
};

struct Node_0017AEC0 {
    Node_0017AEC0* m_next;
    int m4[2];
    unsigned int mC;
    unsigned char* m10[2];
    void* m18[12];
    Sub_0017AEC0* m48;
};

struct Obj_0017AEC0 {
    int m0[75];
    unsigned int m12C;
    unsigned int m130;
    int m134[26];
    Obj_0017AEC0* m19C;
};

struct Ent_0017AEC0 {
    int m0;
    int m4;
    unsigned int m8;
    int mC[16];
    Ent_0017AEC0* m4C;
};

extern Node_0017AEC0* D_003942F4;
extern Node_0017AEC0* D_00394298;
extern Node_0017AEC0* D_003942A0;
extern Node_0017AEC0* D_003942FC;
extern Node_0017AEC0* D_0039427C;
extern Obj_0017AEC0* D_00393F60;
extern Ent_0017AEC0* D_0038C0F8;
extern int D_00394094;
extern int D_0039429C;
extern unsigned char* D_003942C0;
extern int D_0038C000;
extern int D_0038C004;
extern int D_0038C008;
extern int D_0038BFF0;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern char D_0034C4D8[];
extern char D_003484E0[];
extern char D_280[];
extern "C" void func_001617A0(Node_0017AEC0* n);
extern "C" void func_00161650(Node_0017AEC0* n);
extern "C" void* func_00161250(void* p);
extern "C" void func_001644E8(int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_001647B0(int reg, unsigned long v);
extern "C" int func_001686B0(int a);
extern "C" void func_00168700(int a);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Cycle(int n)
{
    Put(0x01000000 | (n << 8) | n);
    D_0039429C = n;
}

static inline void Close()
{
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}

static inline void Flush()
{
    if (D_0039427C) {
        func_001617A0(0);
    }
}

extern "C" void func_0017AEC0()
{
    Node_0017AEC0* cur = D_00394298;
    if (D_0039427C != cur) {
        func_001617A0(cur);
    }
    int n = (D_0034C4D8 - D_003484E0 + 15) / 16;
    unsigned int* t = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)t;
    t[1] = (unsigned int)D_003484E0;
    t[0] = n | 0x30000000;
    D_00394274 = (unsigned char*)(t + 2);
    Put(0);
    Put(0);
    Tag(0x10000000, 0);
    Put(0x11000000);
    Put(0x20000000);
    Put(0);
    Put(0x05000000);
    Cycle(1);
    Put(0x03000000);
    Put(0x02000000);
    Put((((unsigned int)D_280 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = 0;
    D_00394280 = 0;
    Close();
    Flush();
    Node_0017AEC0* s;
    for (s = D_003942F4; s; s = s->m_next) {
        func_00161650(s);
    }
    Flush();
    D_003942A0->m10[D_00394094] = D_00394274;
    unsigned int* p = (unsigned int*)D_00394274;
    for (Obj_0017AEC0* o = D_00393F60; o; o = o->m19C) {
        *p++ = ((o->m130 + 15) >> 4) + 0x30000000;
        *p++ = o->m12C;
        *p++ = 0;
        *p++ = 0;
    }
    for (Ent_0017AEC0* e = D_0038C0F8; e; e = e->m4C) {
        if ((e->m4 >> 1) & 1) {
            *p++ = 0x50000000;
            *p++ = e->m8;
            *p++ = 0;
            *p++ = 0;
        }
    }
    D_00394274 = (unsigned char*)p;
    Tag(0x70000000, 0);
    Put(0);
    Put(0);
    func_001644E8(0xE, 1, 0, 0, 0, 1, 1);
    func_001647B0(0x3F, 0);
    Close();
    int r = func_001686B0(1);
    for (s = D_003942F4; s != D_003942A0; s = s->m_next) {
        if ((s->mC & 4) && s != D_003942FC && s->m48 && (s->m48->m10 & 2)) {
            s->m18[D_00394094] = func_00161250(s->m18[D_00394094]);
        }
    }
    if (r) {
        func_00168700(1);
    }
    unsigned char* tmp = D_00394298->m10[D_00394094];
    D_00394298->m10[D_00394094] = D_003942A0->m10[D_00394094];
    D_003942A0->m10[D_00394094] = tmp;
    int used = D_00394274 - D_003942C0;
    if (D_0038C000 < used) {
        D_0038C000 = used;
    }
    if (D_0038C004 < used) {
        D_0038C004 = used;
    }
    D_0038C008 = (D_0038C008 + 1) & 0x1F;
    if (D_0038C008 == 0) {
        D_0038C004 -= 50000;
    }
    if (D_0038BFF0) {
        D_0038BFF0--;
    }
}
