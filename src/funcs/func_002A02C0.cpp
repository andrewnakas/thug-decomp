extern "C" void func_00183C98(void* p, void* r);
extern "C" void func_00183CB8(void* p, void* r);

struct Ref_002A02C0 {
    void* p;
    void* a;
    void* b;
    void Copy(const Ref_002A02C0* o) {
        void* q = o->p;
        a = 0;
        b = 0;
        p = q;
        if (q) func_00183C98(q, this);
    }
    void Release() {
        void* t = p;
        if (t) { func_00183CB8(t, this); p = 0; }
    }
};

struct Sub_002A02C0 {
    char pad[0xA0];
    void* mA0;
};

extern void* D_00389A30;
extern int D_003920A8;
extern unsigned int D_0039416C;
extern char D_00377F18[];
extern char D_00377F38[];
extern char D_00377F58[];
extern "C" int func_002A5928(Sub_002A02C0* s);
extern "C" int func_002A1A38(Sub_002A02C0* s);
extern "C" int func_002A9D58(int a, int b);
extern "C" unsigned int func_0010FC30();
extern "C" void func_002A71E0(Sub_002A02C0* s);
extern "C" void func_001048F0(void* p);
extern "C" void func_0012DB48(Ref_002A02C0* out, void* t, int crc, int a);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" int func_001F0D78(char* s);
extern "C" void func_002A7B50(Sub_002A02C0* s, int a, int b, int c, int d, int e, char* f, int g, int h);

struct Obj_002A02C0 {
    char pad[0x20];
    Sub_002A02C0* m20;
    void Update();
};

void Obj_002A02C0::Update()
{
    Sub_002A02C0* s = m20;
    if (func_002A5928(s) > 0) {
        if (func_002A1A38(s)) {
            if (D_003920A8) return;
            Ref_002A02C0 r2;
            Ref_002A02C0 r1;
            Ref_002A02C0* p1 = &r1;
            func_0012DB48(p1, D_00389A30, 0xF53D1D83, 0);
            Ref_002A02C0* p2 = &r2;
            p2->Copy(p1);
            p1->Release();
            if (!p2->p) {
                func_001F0370(D_00377F18, 0, 0, 0);
                D_003920A8 = 1;
            }
            p2->Release();
        } else {
            if (D_003920A8) return;
            func_002A7B50(s, 1, func_001F0D78(D_00377F38), 0, 0, 0, D_00377F58, 0, 0x7D0);
            D_003920A8 = 1;
        }
    } else {
        if (!func_002A9D58(0, 0)) return;
        if (func_0010FC30() < D_0039416C) return;
        D_003920A8 = 0;
        func_002A71E0(s);
        func_001048F0(s->mA0);
    }
}
