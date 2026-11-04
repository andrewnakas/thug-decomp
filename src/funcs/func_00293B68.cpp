extern char D_003773F0[];

struct Arr_00293B68 {
    char pad[8];
    int m8;
    unsigned int mC;
};

struct Rec_00293B68 {
    unsigned char id;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E8248(void* p, unsigned int key, Arr_00293B68** out, int req);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001E9300(void* p, int i);
extern "C" void func_001E6AC8(void* s, void* q);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);

struct Obj_00293B68 {
    char pad[0x2CC];
    int m2CC;
    char pad2D0[0x10];
    Rec_00293B68 m2E0[10];
    int m308;
    void Fill(void* out);
};

void Obj_00293B68::Fill(void* out)
{
    if (m308 == 0) {
        func_00103F28(D_003773F0, 1);
        func_001E7360(out, 0x7BE1E689, 0x6D641BCB);
        return;
    }
    void* arr = func_001E55B8(0xBA9358A5, 1);
    int total = 0;
    for (int i = 0; i < m308; i++) {
        void* e = func_001E9378(arr, m2E0[i].id);
        Arr_00293B68* a = 0;
        func_001E8248(e, 0x79704516, &a, 0);
        total += a->mC;
    }
    void* res = func_001E8DD0(func_00122CF8(16));
    func_001E8E98(res, total, 10);
    int k = 0;
    for (int i = 0; i < m308; i++) {
        void* e = func_001E9378(arr, m2E0[i].id);
        Arr_00293B68* a = 0;
        func_001E8248(e, 0x79704516, &a, 0);
        for (unsigned int j = 0; j < a->mC; j++, k++) {
            void* s = func_001E6978(func_001190D0(8));
            if (a->m8 == 13)
                func_001E7360(s, 0xACFDB27A, func_001E9300(a, j));
            else
                func_001E6AC8(s, func_001E9378(a, j));
            if (m2E0[i].m3)
                func_001E7200(s, 0xA4BEE6A1, m2E0[i].m3);
            if (m2E0[i].m1)
                func_001E7360(s, 0, 0x687E2C25);
            if (m2CC)
                func_001E7200(s, 0x8C8ABD19, m2CC);
            func_001E9170(res, k, s);
        }
    }
    func_001E7720(out, 0x7BE1E689, res);
}
