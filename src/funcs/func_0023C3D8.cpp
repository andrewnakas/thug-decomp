struct Mgr_0023C3D8 {
    int m0;
    char m_4[0x18];
    void ResetAll();
};

extern "C" int func_0023C040(Mgr_0023C3D8* self);
extern "C" void* func_00243C18(void* list, int* index, int* out);
extern "C" void func_00244378(void* item, int a, int b);

void Mgr_0023C3D8::ResetAll()
{
    int i = 0;
    int tmp;
    while (i < func_0023C040(this)) {
        func_00244378(func_00243C18(m_4, &i, &tmp), 0, 0);
        i++;
    }
}
