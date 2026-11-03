struct Pool_002D2850 {
    char pad[0x104];
    int m104;
};

struct Cb_002D2850 {
    char pad[0x20];
    void* owner;
};

extern Pool_002D2850* D_00388A70;
extern int D_00392B18;
extern int D_00392B1C;
extern int D_0039418C;
extern unsigned int D_00394190;
extern unsigned int D_00394194;
extern int D_00394198;
extern void* D_00392068;
extern char D_004532C8[];
extern char D_00453AC8[];
extern char D_0037BC38[];
extern "C" unsigned int func_0010FC30();
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_002D3D30(void* m);
extern "C" void func_00306030(void* a, char* b, int c, char* d);
extern "C" void func_00304528(char* b, int c, char* d);
extern "C" int func_002A19A8(void* g);
extern "C" int func_002A1A38(void* g);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_00306F38(void* a);

static inline bool Elapsed_002D2850(unsigned int ms, unsigned int now, unsigned int start) { return now - start > ms; }

void func_002D2850(Cb_002D2850* c)
{
    void* m = c->owner;
    unsigned int now = func_0010FC30();
    func_0010A950(D_00388A70, D_00388A70->m104);
    if (D_00392B18 == 1) {
        func_00306030(func_002D3D30(m), D_004532C8, D_00392B1C, D_00453AC8);
        D_004532C8[0] = 0;
        D_00392B1C = 0;
        D_00392B18 = 0;
    } else if (D_00392B18 == 2) {
        func_00304528(D_004532C8, D_00392B1C, D_00453AC8);
        D_004532C8[0] = 0;
        D_00392B1C = 0;
        D_00392B18 = 0;
    } else if (!D_0039418C) {
        void* g = D_00392068;
        if (func_002A19A8(g) && func_002A1A38(g)) {
            if (now - D_00394190 > 90000) {
                if (!D_00394198) {
                    func_001F0370(D_0037BC38, 0, 0, 0);
                    D_00394198 = 1;
                }
            } else if (Elapsed_002D2850(5000, now, D_00394194)) {
                func_00306F38(func_002D3D30(m));
                D_00394194 = now;
            }
        }
    }
    func_0010A9B0(D_00388A70);
}
