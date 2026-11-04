typedef int qword __attribute__((mode(TI)));

extern char D_003792A0[];
extern char D_003792C0[];
extern char D_003792E0[];
extern char D_003922E8[];

struct Inner_002AE538 {
    char pad[0x18];
    int m18;
};

struct Elem_002AE538 {
    char pad[0x18];
    Inner_002AE538* m18;
};

struct Elem2_002AE538 {
    char pad[0x18];
    int m18;
};

union Vec_002AE538 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Thing_002AE538 {
    char pad[0x50];
    Vec_002AE538 m50;
};

struct Arr_002AE538 {
    char pad[0xC];
    int mC;
};

extern "C" int func_001F0D78(char* s);
extern "C" Elem_002AE538* func_002A5820(void* s);
extern "C" void func_002B2BC0(void* p, int v);
extern "C" int func_002B1FC8(void* item);
extern "C" int func_002A19A8(void* s);
extern "C" void func_002A7B50(void* s, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" Elem2_002AE538* func_002A52F0(void* s, unsigned short id);
extern "C" Thing_002AE538* func_002A8498(void* s);
extern "C" Arr_002AE538* func_001E55F8(char* name, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E84E8(void* s, char* name, int* out, int v);
extern "C" void func_00229FF8(void* q, Vec_002AE538* out);
extern "C" void func_00268100(void* p);

struct Obj_002AE538 {
    char* m0;
    char pad[0x18];
    void* m1C;
};

bool Cmd_002AE538(Obj_002AE538* o)
{
    void* mgr = o->m1C;
    Elem_002AE538* e = func_002A5820(mgr);
    char cnt[4];
    cnt[0] = *o->m0;
    if (e) {
        func_002B2BC0(e, 0);
        if (func_002B1FC8(e)) {
            func_002A7B50(mgr, 0, func_001F0D78(D_003792A0), 0, 0, (int)e->m18, 0, 0, 2000);
            goto done;
        }
    }
    if (func_002A19A8(mgr)) {
        func_002A7B50(mgr, 0, func_001F0D78(D_003792C0), 0, 0, 0, 0, 0, 2000);
    } else if (e && e->m18) {
        Elem2_002AE538* f = func_002A52F0(mgr, e->m18->m18 == 0);
        if (f)
            func_002A7B50(mgr, 0, func_001F0D78(D_003792C0), 0, 0, f->m18, 0, 0, 2000);
    }
done:
    Thing_002AE538* th = func_002A8498(mgr);
    if (th) {
        bool found = false;
        for (int k = 1; k != 50; k++) {
            Arr_002AE538* a = func_001E55F8(D_003792E0, 0);
            int i = 0;
            if (i < a->mC) do {
                void* q = func_001E9378(a, i);
                Vec_002AE538 tmp;
                int v = 0;
                func_001E84E8(q, D_003922E8, &v, 0);
                if (v == (int)0xAF86421B) {
                    if (cnt[0] == 0) {
                        func_00229FF8(q, &tmp);
                        found = true;
                        th->m50 = tmp;
                        break;
                    }
                    cnt[0]--;
                }
                i++;
            } while (i < a->mC);
            if (found)
                break;
        }
        func_00268100(th);
    }
    return true;
}
