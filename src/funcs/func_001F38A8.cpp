extern void* D_0038C608;
extern char D_003660E8[];
extern char D_00366120[];
extern char D_00366130[];
extern char D_00366140[];
extern char D_00366150[];
extern char D_00366160[];
extern char D_00366170[];
extern char D_00366180[];
extern char D_00366190[];
extern char D_0038E918[];
extern char D_0038E920[];
extern char D_0038E928[];
extern "C" void* func_00187B48(void*, int);
extern "C" void func_001F47D8(void*, void*);
extern "C" void* func_00240850();
extern "C" int func_00240120(void*, int);
extern "C" void func_00103F28(const char*, ...);
extern "C" int func_001E5400(const char*, int);
extern "C" void* func_001E55F8(const char*, int);
extern "C" void* func_001E9378(void*, int);
extern "C" int func_001E86D0(void*, const char*);
extern "C" int func_001E84E8(void*, const char*, int*, int);
extern "C" int func_001E82B8(void*, const char*, int*, int);
extern "C" int func_001E7D18(void*, const char*, char**, int);
extern "C" int func_001E7E58(void*, const char*, int*, int);
extern "C" int func_001E9270(int, int);
extern "C" int func_001E91C0(int, int);
extern "C" int func_001E9300(int, int);

struct Arr_001F38A8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Info_001F38A8 {
    char pad[0x18];
    int m18;
};

struct Entry_001F38A8 {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    char* f5;
    int f6;
    int f7;
    int f8;
};

struct Obj_001F38A8 {
    char pad0[0xC];
    Info_001F38A8* mC;
    int pad10[3];
    int m1C;
    Entry_001F38A8 m_entries[64];
    char pad[0x9F8 - 0x20 - 64 * 0x24];
    int m9F8;
    int m9FC;
    int mA00;
    int padA04[8];
    int mA24;
    int mA28;
    int mA2C;
    int padA30[8];
    int mA50;
    int mA54;
    int mA58;
    int mA5C;
    int mA60;
    int padA64[11];
    int mA90;
    int mA94;
    int mA98;
    int mA9C;
    void Init();
};

void Obj_001F38A8::Init()
{
    mA00 = 0;
    m9F8 = 0;
    mA28 = 0;
    mA2C = 0;
    mA5C = 0;
    mA60 = 0;
    mA58 = 0;
    mA50 = 0;
    mA54 = 0;
    mA90 = 0;
    mA94 = 0;
    mA98 = 0;
    mA9C = 0;
    m1C = 1;
    func_001F47D8(this, func_00187B48(D_0038C608, mC->m18));
    mA24 = func_00240120(func_00240850(), 1);
    func_00103F28(D_003660E8, mA24);
    int v = func_001E5400(D_00366120, 1);
    if (v == 1)
        m9FC = v;
    Arr_001F38A8* arr = (Arr_001F38A8*)func_001E55F8(D_00366130, 1);
    int n = arr->mC;
    for (int i = 0; i < n; i++) {
        void* s = func_001E9378(arr, i);
        if (func_001E86D0(s, D_00366140)) {
            int t;
            func_001E84E8(s, D_00366140, &t, 1);
            m_entries[i].f0 = t;
        }
        if (func_001E86D0(s, D_00366150)) {
            int t;
            func_001E84E8(s, D_00366150, &t, 1);
            m_entries[i].f1 = t;
        }
        if (func_001E86D0(s, D_0038E918)) {
            int t = 0;
            func_001E82B8(s, D_0038E918, &t, 1);
            m_entries[i].f2 = func_001E9270(t, mA24);
        }
        if (func_001E86D0(s, D_00366160)) {
            int t = 0;
            func_001E82B8(s, D_00366160, &t, 1);
            m_entries[i].f6 = func_001E91C0(t, mA24);
        }
        if (func_001E86D0(s, D_0038E920)) {
            char* t = D_0038E928;
            func_001E7D18(s, D_0038E920, &t, 1);
            m_entries[i].f5 = t;
        }
        if (func_001E86D0(s, D_00366170)) {
            int t;
            func_001E7E58(s, D_00366170, &t, 1);
            m_entries[i].f4 = t;
        }
        if (func_001E86D0(s, D_00366180)) {
            int t = 0;
            func_001E82B8(s, D_00366180, &t, 1);
            m_entries[i].f7 = func_001E9300(t, mA24);
        }
        if (func_001E86D0(s, D_00366190)) {
            int t = 0;
            func_001E82B8(s, D_00366190, &t, 1);
            m_entries[i].f8 = func_001E9270(t, mA24);
        }
        m_entries[i].f3 = 0;
    }
}
