/* fuzzy: 72.0 */
struct Sub_001B9E30 {
    char pad[0x1C];
    int m1C;
    int m20;
    char pad24[0x40 - 0x24];
    int m40;
    char pad44[0x64 - 0x44];
    int m64;
    char pad68[0xAC - 0x68];
    int mAC;
    char padB0[0x150 - 0xB0];
    int m150;
};

static inline int Check_001B9E30(Sub_001B9E30* p)
{
    if (p->m1C == 3 || (p->m40 && !p->m64 && !p->mAC))
        return 1;
    return p->m150 != 0;
}

struct Obj_001B9E30 {
    char pad[0x168];
    void* m168;
    void* m16C;
    int Method();
};

int Obj_001B9E30::Method()
{
    if (m168) {
        Sub_001B9E30* p = (Sub_001B9E30*)m16C;
        if (!p->m20) {
            if (p->m1C == 3 || (p->m40 && !p->m64 && !p->mAC))
                return 1;
            return p->m150 != 0;
        }
    }
    return 0;
}
