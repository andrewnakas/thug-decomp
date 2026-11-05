struct Item_001E0E20 {
    char m_data[0x28];
};

struct Entry_001E0E20 {
    Item_001E0E20 m_items[80];
    int m_count;
    char pad[0x2C];
};

extern Entry_001E0E20 D_003F0898[];
extern char D_003F21F8[];

extern "C" int func_001DED20();
extern "C" int func_001E3C08();
extern "C" int func_001F0D78(void* p);

extern "C" bool func_001E0E20(int idx, int sub)
{
    if (func_001DED20())
        return false;
    if (func_001E3C08() == 1)
        return false;
    if (sub >= (D_003F0898 + idx)->m_count)
        return false;
    int a = func_001F0D78(D_003F21F8);
    if (a == func_001F0D78(&D_003F0898[idx].m_items[sub]))
        return true;
    return false;
}
