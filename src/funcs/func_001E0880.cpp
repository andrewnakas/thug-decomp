typedef unsigned long u64_001E0880;

extern int D_0038E130;
extern int D_0038E140;
extern int D_0038E150;
extern int D_0038E12C;
extern void* D_0038FC78;
extern char D_003F21F8[];
extern char D_00364418[];

struct Slot_001E0880 {
    char pad[0x28];
};

struct Lobby_001E0880 {
    Slot_001E0880 m_slots[80];
    int mC80;
    int padC84;
    u64_001E0880 mC88;
    u64_001E0880 mC90;
    u64_001E0880 mC98;
    u64_001E0880 mCA0;
    int mCA8;
    int padCAC;
};

extern Lobby_001E0880 D_003F0898[];

extern "C" int func_001DED20();
extern "C" void* func_0022E358(void*);
extern "C" int func_0024F860(void*);
extern "C" int func_001E3C08();
extern "C" void func_001E04A8();
extern "C" void func_001DFDD0(void*, int);
extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" void func_001E7200(void*, unsigned int, int);
extern "C" void func_001F0370(const char*, void*, int, int);
extern "C" void func_001E6AE8(void*, int);

static inline bool Clear_001E0880(u64_001E0880 v, int i)
{
    return !((int)(v >> i) & 1);
}

void func_001E0880()
{
    if (func_001DED20())
        return;
    int idx = D_0038E130;
    if (func_0024F860(func_0022E358(D_0038FC78)))
        idx = 1;
    Lobby_001E0880* p = &D_003F0898[idx];
    if (p->mCA8)
        return;
    if (func_001E3C08() != 1)
        return;
    D_0038E150 = 0;
    func_001E04A8();
    if (D_0038E140) {
        func_001DFDD0(D_003F21F8, 1);
        return;
    }
    for (int i = 0; i < p->mC80; i++) {
        if (Clear_001E0880(p->mC88, i) && i < 64 && Clear_001E0880(p->mC98, i)) {
            p->mC98 |= (u64_001E0880)1 << i;
            func_001DFDD0(&p->m_slots[i], 0);
            D_0038E12C = i;
            void* s = func_001E6978(func_001190D0(8));
            func_001E7200(s, 0x8D02705D, D_0038E12C);
            func_001F0370(D_00364418, s, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
            return;
        }
        if (Clear_001E0880(p->mC90, i - 64) && i >= 64 && Clear_001E0880(p->mCA0, i - 64)) {
            p->mCA0 |= (u64_001E0880)1 << (i - 64);
            func_001DFDD0(&p->m_slots[i], 0);
            D_0038E12C = i;
            void* s = func_001E6978(func_001190D0(8));
            func_001E7200(s, 0x8D02705D, D_0038E12C);
            func_001F0370(D_00364418, s, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
            return;
        }
    }
    p->mC98 = 0;
    p->mCA0 = 0;
}
