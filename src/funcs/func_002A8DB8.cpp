typedef int qword __attribute__((mode(TI)));

union Vec_002A8DB8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Arr_002A8DB8 {
    char pad[0xC];
    int mC;
};

struct Elem_002A8DB8 {
    char pad[0x18];
    void* m18;
};

struct Mgr_002A8DB8 {
    char pad[0x70];
    int m70;
    void* m74;
};

extern void* D_0038FC78;
extern Mgr_002A8DB8* D_00392068;
extern char D_003789E8[];
extern char D_003921B0[];
extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_00268048(void* p);
extern "C" Arr_002A8DB8* func_001E55F8(char* name, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E84E8(void* s, char* name, int* out, int v);
extern "C" void func_00229FF8(void* q, Vec_002A8DB8* out);
extern "C" int func_0022E040(void* p);
extern "C" void func_00268110(void* p, int a, void* q);
extern "C" Elem_002A8DB8* func_002A5820(Mgr_002A8DB8* m);
extern "C" void func_002680E8(void* p, void* s);

bool Cmd_002A8DB8(void* params, void* script)
{
    void* items[12];
    int idx[12];
    Vec_002A8DB8 pos;
    void* fc = D_0038FC78;
    Mgr_002A8DB8* mgr = D_00392068;
    mgr->m74 = func_00268048(func_001046B0(0x170));
    Arr_002A8DB8* a = func_001E55F8(D_003789E8, 0);
    if (!a) return false;
    int n = 0;
    int r = mgr->m70;
    for (int i = 0; i < a->mC; i++) {
        void* e = func_001E9378(a, i);
        int t = 0;
        func_001E84E8(e, D_003921B0, &t, 0);
        if (t == (int)0xAF86421B) {
            items[n] = e;
            idx[n] = i;
            n++;
        }
    }
    int k = r % n;
    func_00229FF8(items[k], &pos);
    func_00268110(mgr->m74, func_0022E040(fc), items[k]);
    Elem_002A8DB8* s = func_002A5820(mgr);
    if (s) func_002680E8(mgr->m74, s->m18);
    return true;
}
