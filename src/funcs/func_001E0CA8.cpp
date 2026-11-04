typedef unsigned long u64_001E0CA8;

struct Slot_001E0CA8 {
    char pad[0x28];
};

struct Lobby_001E0CA8 {
    Slot_001E0CA8 m_slots[80];
    int mC80;
    int padC84;
    u64_001E0CA8 mC88;
    u64_001E0CA8 mC90;
    u64_001E0CA8 mC98;
    u64_001E0CA8 mCA0;
    int mCA8;
    int padCAC;
};

extern Lobby_001E0CA8 D_003F0898[];
extern int D_0038E154;

extern "C" int func_001DED20();
extern "C" int func_001E0E20(int lobby, int slot);
extern "C" void func_001DEEE0();

static inline bool Clear_001E0CA8(u64_001E0CA8 v, int i)
{
    return !((int)(v >> i) & 1);
}

void SetReady_001E0CA8(int slot, int ready, int lobby)
{
    if (func_001DED20())
        return;
    D_0038E154 = 1;
    Lobby_001E0CA8* p = &D_003F0898[lobby];
    if (ready) {
        if (slot < 64)
            p->mC88 |= (u64_001E0CA8)1 << slot;
        else
            p->mC90 |= (u64_001E0CA8)1 << (slot - 64);
        if (func_001E0E20(lobby, slot))
            func_001DEEE0();
        for (int i = 0; i < p->mC80; i++) {
            if (Clear_001E0CA8(p->mC88, i) || Clear_001E0CA8(p->mC90, i - 64)) {
                p->mCA8 = 0;
                return;
            }
        }
        p->mCA8 = 1;
    } else {
        if (slot < 64)
            p->mC88 &= ~((u64_001E0CA8)1 << slot);
        else
            p->mC90 &= ~((u64_001E0CA8)1 << (slot - 64));
        p->mCA8 = 0;
    }
}
