/* sym: _vt$12Ctx_00254C98 = 0x00367278 */
struct Entry_00254C98 {
    int m0;
    char m4[0x4C];
    char m50[0x94 - 0x50];
};

struct Table_00254C98 {
    char pad0[0x8];
    Entry_00254C98 m8[1];
};

struct Text_00254C98 {
    char pad0[0x1C];
    char* m1C;
    int m20;
};

extern char D_00375220[];
extern char D_00375240[];

extern "C" Table_00254C98* func_00183098(int v);
extern "C" void func_001830E8();
extern "C" void func_001048F0(Text_00254C98* t);
extern "C" void func_00105260(char* dst, Text_00254C98* t);
extern "C" void func_00103F28(const char* fmt, ...);

struct Ref_00254C98 {
    int m0;
    Table_00254C98* m4;
    Ref_00254C98(Table_00254C98* p) { m4 = p; }
};

class Ctx_00254C98 {
public:
    int m0;
    Ref_00254C98 m4;
    Ctx_00254C98() : m4(func_00183098(0)) {}
    Ref_00254C98* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_00254C98() { func_001830E8(); }
};

struct Obj_00254C98 {
    char pad0[0x28];
    Text_00254C98* m_text[2];
    int m_index[2];
    void Refresh();
};

void Obj_00254C98::Refresh()
{
    Ctx_00254C98 ctx;
    for (int i = 0; i < 2; i++) {
        func_00103F28(D_00375220, i, m_index[i]);
        Text_00254C98* t = m_text[i];
        if (t) {
            func_00103F28(D_00375240);
            Table_00254C98* tab = ctx.GetRef()->m4;
            int idx = m_index[i];
            func_001048F0(t);
            func_00105260(tab->m8[idx].m4, t);
            t->m1C = tab->m8[idx].m50;
            t->m20 = tab->m8[idx].m0;
        }
    }
}
