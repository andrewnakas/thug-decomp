struct Slot_001DEF68 {
    char m_pad[0x1C];
    int m_ids[3];
};

struct Entry_001DEF68 {
    int m0;
    int m_id;
    char m_pad[0x28 - 0x8];
};

extern Slot_001DEF68* D_003F2220[3];
extern Entry_001DEF68 D_003EE8E0[];

extern "C" bool func_001DED40(int id);
extern "C" int func_001DEDE0(int id, int a);
extern "C" void func_001E3978(int index, int a);

extern "C" void func_001DEF68(int id)
{
    if (func_001DED40(id))
        return;
    int index = func_001DEDE0(id, 1);
    if (index >= 0) {
        func_001E3978(index, 1);
        id = D_003EE8E0[index].m_id;
    }
    for (int i = 0; i < 3; i++) {
        if (D_003F2220[i]) {
            for (int j = 0; j < 3; j++) {
                if (D_003F2220[i]->m_ids[j] == id) {
                    D_003F2220[i]->m_ids[j] = 0;
                    D_003F2220[i] = 0;
                    return;
                }
            }
        }
    }
}
