struct Entry_0010DFF8 {
    char pad[0xA];
    unsigned short mA;
    int mC;
    char name[4];
};

struct Pack_0010DFF8 {
    int m0;
    int m4;
    int count;
    Entry_0010DFF8 first;
};

struct Rec_0010DFF8 {
    int used;
    unsigned int id;
    int m8;
    int mC;
};

extern char D_0035B720[];
extern char D_0035B730[];
extern char D_0035B748[];
extern char D_0035B760[];
extern char D_0035B780[];
extern char D_0035B790[];
extern char D_0035B7A8[];
extern char* D_00396568[100];
extern Rec_0010DFF8 D_003966F8[200];

extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" Pack_0010DFF8* func_0010D4E0(char* name);
extern "C" Entry_0010DFF8* func_0010D4A0(Entry_0010DFF8* e, int n);
extern "C" const char* func_001E61F0(unsigned int id);

extern "C" bool func_0010DFF8(void* params)
{
    int detail = func_001E87B8(params, D_0035B720);
    int recs = func_001E87B8(params, D_0035B730);
    int nonzero = func_001E87B8(params, D_0035B748);
    func_00103F28(D_0035B760);
    for (int i = 0; i < 100; i++) {
        if (D_00396568[i]) {
            func_00103F28(D_0035B780, D_00396568[i]);
            if (detail) {
                Pack_0010DFF8* pack = func_0010D4E0(D_00396568[i]);
                int n = pack->count;
                Entry_0010DFF8* e = &pack->first;
                for (int j = 0; j < n; j++) {
                    if (!nonzero || e->mA != 0) {
                        func_00103F28(D_0035B790, e->mA, e->name);
                        for (volatile int k = 0; k <= 99999; k++) {
                        }
                    }
                    e = func_0010D4A0(e, 1);
                }
            }
        }
    }
    if (recs) {
        func_00103F28(D_0035B7A8);
        for (int i = 0; i < 200; i++) {
            if (D_003966F8[i].used) {
                func_00103F28(D_0035B790, D_003966F8[i].mC, func_001E61F0(D_003966F8[i].id));
            }
        }
    }
    return true;
}
