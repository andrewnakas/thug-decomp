struct Slot_0021F898 {
    int m_a;
    int m_b;
    int m_index;
};

struct Mgr_0021F898 {
    char pad0[0x94];
    Slot_0021F898 m_slots[1];
};

extern Mgr_0021F898* D_0038FC78;
extern char D_0038F820[];
extern char D_003717A0[];
extern char D_0038F870[];

extern "C" bool func_001E88F8(void* params, const char* name, int* out, int required);
extern "C" bool func_001E8A50(void* params, const char* name, int* out, int required);

bool func_0021F898(void* params)
{
    int a;
    int b;
    int index;
    func_001E88F8(params, D_0038F820, &a, 1);
    func_001E8A50(params, D_003717A0, &b, 1);
    func_001E88F8(params, D_0038F870, &index, 1);
    Mgr_0021F898* mgr = D_0038FC78;
    mgr->m_slots[index].m_a = a;
    mgr->m_slots[index].m_b = b;
    mgr->m_slots[index].m_index = index;
    return true;
}
