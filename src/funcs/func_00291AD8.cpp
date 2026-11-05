struct Comp_00291AD8 {
    char pad[0x34];
    int m34;
};

struct Info_00291AD8 {
    int m0;
};

struct Owner_00291AD8 {
    char pad[0x18];
    int m18;
    char pad1C[0x304];
    int m320;
};

extern int D_00392068;
extern "C" Info_00291AD8* func_002A39E0(int mgr, int id);
extern "C" Comp_00291AD8* func_00185578(Owner_00291AD8* o, unsigned int type);
extern "C" void func_001A2610(void* a, int b, int c, int d, int e);

struct Obj_00291AD8 {
    char pad[0xC];
    Owner_00291AD8* mC;
    char pad10[0x1C];
    void* m2C;
    void Update();
};

void Obj_00291AD8::Update()
{
    Info_00291AD8* info = func_002A39E0(D_00392068, mC->m320);
    int id = mC->m18;
    func_001A2610(m2C, id, func_00185578(mC, 0x43686585)->m34, info->m0, 1);
}
