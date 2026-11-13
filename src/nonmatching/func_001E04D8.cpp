/* fuzzy: 99.1 */
typedef unsigned long u64_001E04D8;

extern int D_0038E130;
extern int D_0038E140;
extern int D_0038E150;
extern int D_0038E154;
extern int D_0038E158;
extern int D_0038E15C;
extern int D_0038E12C;
extern char D_003F21F8[];
extern char D_00364418[];
extern char D_003643E8[];
extern int D_003F2230[];

struct Slot_001E04D8 {
    char pad[0x28];
};

struct Lobby_001E04D8 {
    Slot_001E04D8 m_slots[80];
    int mC80;
    int padC84;
    u64_001E04D8 mC88;
    u64_001E04D8 mC90;
    u64_001E04D8 mC98;
    u64_001E04D8 mCA0;
    int mCA8;
    int padCAC;
};

extern Lobby_001E04D8 D_003F0898[];

extern "C" int func_001DED20();
extern "C" int func_001E3C08();
extern "C" void func_001E04A8();
extern "C" void func_001DFDD0(void*, int);
extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" void func_001E7200(void*, unsigned int, int);
extern "C" void func_001F0370(const char*, void*, int, int);
extern "C" void func_001E6AE8(void*, int);
extern "C" int func_00103F28(const char*, ...);
extern "C" int func_00100030(int);

static inline bool Clear_001E04D8(u64_001E04D8 v, int i)
{
    return !((int)(v >> i) & 1);
}

static inline void Swap_001E04D8(int a, int b)
{
    int t = D_003F2230[a];
    D_003F2230[a] = D_003F2230[b];
    D_003F2230[b] = t;
}

void func_001E04D8()
{
    Lobby_001E04D8* p = &D_003F0898[D_0038E130];
    if (func_001DED20())
        return;
    if (p->mCA8)
        return;
    int r = func_001E3C08();
    if (r != 1)
        return;
    D_0038E150 = 0;
    func_001E04A8();
    if (D_0038E140) {
        func_001DFDD0(D_003F21F8, 1);
        return;
    }
    if (!p->mC80)
        return;
    if (D_0038E154) {
        int last = D_003F2230[D_0038E158 - 1];
        D_0038E158 = 0;
        for (int i = 0; i < p->mC80; i++) {
            bool clear;
            if (i < 64)
                clear = Clear_001E04D8(p->mC88, i);
            else
                clear = Clear_001E04D8(p->mC90, i - 64);
            if (clear)
                D_003F2230[D_0038E158++] = i;
        }
        func_00103F28(D_003643E8, D_0038E158);
        for (int k = 0; k < 2000; k++) {
            int a = func_00100030(D_0038E158);
            int b = func_00100030(D_0038E158);
            if (a != b)
                Swap_001E04D8(a, b);
        }
        int cur = 0;
        if (D_003F2230[cur] == last) {
            int j = D_0038E158 < 2 ? 0 : func_00100030(D_0038E158 - 1) + 1;
            Swap_001E04D8(cur, j);
        }
        D_0038E15C = cur;
        D_0038E154 = 0;
        p->mC98 = 0;
        p->mCA0 = 0;
    } else {
        D_0038E15C++;
        if (!(D_0038E15C < D_0038E158 - 1))
            D_0038E154 = r;
    }
    for (int i = 0; i < p->mC80; i++) {
        int s = D_003F2230[D_0038E15C];
        if (Clear_001E04D8(p->mC88, s) && s < 64 && Clear_001E04D8(p->mC98, s)) {
            p->mC98 |= (u64_001E04D8)1 << s;
            func_001DFDD0(&p->m_slots[s], 0);
            D_0038E12C = s;
            void* m = func_001E6978(func_001190D0(8));
            func_001E7200(m, 0x8D02705D, D_0038E12C);
            func_001F0370(D_00364418, m, 0, 0);
            if (m)
                func_001E6AE8(m, 3);
            return;
        }
        if (Clear_001E04D8(p->mC90, s - 64) && s >= 64 && Clear_001E04D8(p->mCA0, s - 64)) {
            p->mCA0 |= (u64_001E04D8)1 << (s - 64);
            func_001DFDD0(&p->m_slots[s], 0);
            D_0038E12C = s;
            void* m = func_001E6978(func_001190D0(8));
            func_001E7200(m, 0x8D02705D, D_0038E12C);
            func_001F0370(D_00364418, m, 0, 0);
            if (m)
                func_001E6AE8(m, 3);
            return;
        }
    }
}
