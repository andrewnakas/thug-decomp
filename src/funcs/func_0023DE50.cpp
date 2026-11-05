struct Mgr_0023DE50 {
    int m0;
    char m_4[0x3C];
    int m_40;
    void StartAll();
};

extern "C" int func_0023C040(Mgr_0023DE50* self);
extern "C" void* func_00243C18(void* list, int* index, int* out);
extern "C" void func_00246508(void* item);

void Mgr_0023DE50::StartAll()
{
    m_40 = 1;
    int i = 0;
    int tmp;
    while (i < func_0023C040(this)) {
        func_00246508(func_00243C18(m_4, &i, &tmp));
        i++;
    }
}
