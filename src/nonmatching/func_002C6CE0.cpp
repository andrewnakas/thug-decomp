/* fuzzy: 92.5 */
/* blocked: `tab += k` fixes the register roles; the game still forms tab[k].m58 from the old pointer
   (addu $v0,$v1,$s0 at 0x002C6D40, a separate addu $s0,$s0,$v1) where ours reuses the bumped pointer
   (one insn short). tab[k] before the bump, a saved name pointer and (tab + k)->mC all CSE back. */
struct Entry_002C6CE0 {
    char pad0[0x8];
    int m8;
    char mC[0x58 - 0xC];
    char m58[0x94 - 0x58];
};

struct Item_002C6CE0 {
    char pad0[0x1C];
    char* m1C;
    int m20;
    int m24;
};

struct Obj_002C6CE0 {
    char pad0[0x3C];
    void* m3C;
    void* m40;
    Item_002C6CE0* m44;
    void Register();
};

extern char* D_0038C308;
extern Entry_002C6CE0* D_0038C3C0;

extern "C" void func_00105260(void* list, void* p);

void Obj_002C6CE0::Register()
{
    char* q = D_0038C308;
    func_00105260(q + 8, m3C);
    Item_002C6CE0* it = m44;
    Entry_002C6CE0* tab = D_0038C3C0;
    func_00105260(tab[it->m24].mC, it);
    tab += it->m24;
    it->m1C = tab->m58;
    it->m20 = tab->m8;
    func_00105260(q + 0x54, m40);
}
