struct Item_002407D8 {
    char pad[0x18];
    void* m_18;
};

struct Mgr_002407D8 {
    int m0;
    char m_4[0x18];
    void ApplyAll(void* params);
};

extern "C" int func_0023C040(Mgr_002407D8* self);
extern "C" Item_002407D8* func_00243C18(void* list, int* index, int* out);
extern "C" void func_00249E90(void* a, void* params);

void Mgr_002407D8::ApplyAll(void* params)
{
    int i = 0;
    int tmp;
    while (i < func_0023C040(this)) {
        func_00249E90(func_00243C18(m_4, &i, &tmp)->m_18, params);
        i++;
    }
}
