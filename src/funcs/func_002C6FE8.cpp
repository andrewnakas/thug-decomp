struct Entry_002C6FE8 {
    int m0;
    char m4[0x4C];
    char m50[0x94 - 0x50];
};

struct Table_002C6FE8 {
    char pad0[0x8];
    Entry_002C6FE8 m8[1];
};

struct Text_002C6FE8 {
    char pad0[0x1C];
    char* m1C;
    int m20;
};

extern "C" Table_002C6FE8* func_00183098(int v);
extern "C" void func_001830E8();
extern "C" void func_001048F0(Text_002C6FE8* t);
extern "C" void func_00105260(char* dst, Text_002C6FE8* t);

struct Ref_002C6FE8 {
    int m0;
    Table_002C6FE8* m4;
    Ref_002C6FE8(Table_002C6FE8* p) { m4 = p; }
};

class Ctx_002C6FE8 {
public:
    int m0;
    Ref_002C6FE8 m4;
    Ctx_002C6FE8() : m4(func_00183098(0)) {}
    Ref_002C6FE8* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_002C6FE8() { func_001830E8(); }
};

struct Obj_002C6FE8 {
    char pad0[0x44];
    Text_002C6FE8* m44;
    void Show(int idx);
};

void Obj_002C6FE8::Show(int idx)
{
    Ctx_002C6FE8 ctx;
    Text_002C6FE8* t = m44;
    Table_002C6FE8* tab = ctx.GetRef()->m4;
    func_001048F0(t);
    func_00105260(tab->m8[idx].m4, t);
    t->m1C = tab->m8[idx].m50;
    t->m20 = tab->m8[idx].m0;
}
