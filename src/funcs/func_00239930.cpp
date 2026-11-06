struct Item_00239930 {
    char pad[8];
    int m_8;
    int m_C;
    int m_10;
};

struct List_00239930;
extern "C" Item_00239930* func_0023AFE8(List_00239930* list, int index);
extern "C" int abs(int x);
extern "C" int func_001E53A0(unsigned int name, int def);

struct List_00239930 {
    char pad[0x14];
    int m_count;
    Item_00239930* Get(int i) { return func_0023AFE8(this, i); }
};

struct Obj_00239930 {
    char pad[0x44];
    List_00239930 m_44;
    bool Matches(int index, int id, int angle, int strict);
};

bool Obj_00239930::Matches(int index, int id, int angle, int strict)
{
    if (index >= m_44.m_count) return false;
    if (m_44.Get(index)->m_10 == id) {
        if (!angle) return true;
        if (angle == m_44.Get(index)->m_8) {
            if (!strict) return true;
            if (abs(abs(m_44.Get(index)->m_C) - angle * 180) < func_001E53A0(0xFCFACAB8, 0)) return true;
        }
    }
    return false;
}
