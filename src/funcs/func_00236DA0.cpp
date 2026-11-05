struct Item_00236DA0 {
    char pad[0x10];
    int m_10;
};

struct Obj_00236DA0 {
    char pad[0x44];
    char m_44[0x18];
    int GetCurrent();
};

extern "C" bool func_0023B000(void* list);
extern "C" Item_00236DA0* func_0023B0A0(void* list);

int Obj_00236DA0::GetCurrent()
{
    if (func_0023B000(m_44)) {
        return func_0023B0A0(m_44)->m_10;
    }
    return 0;
}
