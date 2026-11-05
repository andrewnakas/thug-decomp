struct Mgr_0023D1D8 {
    int m0;
    char m_4[0x18];
    int Call();
};

extern "C" int func_0023BF98(Mgr_0023D1D8* self, int flag);
extern "C" void* func_00243C18(void* list, int* index, int* out);
extern "C" int func_00245C10(void* item);

int Mgr_0023D1D8::Call()
{
    int i = func_0023BF98(this, 1);
    int tmp;
    if (i == -1) {
        return 0;
    }
    return func_00245C10(func_00243C18(m_4, &i, &tmp));
}
