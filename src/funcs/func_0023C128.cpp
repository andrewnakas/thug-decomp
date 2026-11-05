struct Mgr_0023C128 {
    int m0;
    char m_4[0x18];
    int Count();
};

extern "C" int func_0023C040(Mgr_0023C128* self);
extern "C" void* func_00243C18(void* list, int* index, int* out);
extern "C" int func_002463A0(void* item);

int Mgr_0023C128::Count()
{
    int n = 0;
    int i = 0;
    int tmp;
    while (i < func_0023C040(this)) {
        if (func_002463A0(func_00243C18(m_4, &i, &tmp))) {
            n++;
        }
        i++;
    }
    return n;
}
