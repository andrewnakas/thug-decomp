class ItemBase_0025FBB8 {
public:
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int V5();
};

class Item_0025FBB8 : public ItemBase_0025FBB8 {
public:
    char pad18[0x10];
    int m28;
};

struct Mgr_0025FBB8 {
    char pad0[0x120];
    unsigned int m120;
    int m124;
};

struct Game_0025FBB8 {
    char pad0[0x38];
    int m38;
};

extern Game_0025FBB8* D_00390828;
extern int D_0038FBFC;
extern "C" unsigned long func_0010FA80();
extern "C" int func_0025F0F0(Mgr_0025FBB8* m);
extern "C" Item_0025FBB8* func_0025F128(Mgr_0025FBB8* m, int a);
extern "C" void func_0025F620(Mgr_0025FBB8* m, int a);

bool func_0025FBB8(Mgr_0025FBB8* m)
{
    if (m->m124) {
        unsigned long t = m->m120;
        if (func_0010FA80() >= t) {
            m->m124 = 0;
            func_0025F0F0(m);
        }
    }
    Item_0025FBB8* it = func_0025F128(m, 0);
    if (!it) return false;
    if (D_00390828->m38 && !D_0038FBFC) {
        if (!it->m28) {
            it->V2();
        }
    } else {
        it->V2();
    }
    if (it->V5()) {
        func_0025F620(m, 0);
    }
    return func_0025F0F0(m) != 0;
}
