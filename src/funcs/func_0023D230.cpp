struct Obj_0023D230 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023BF98(Obj_0023D230* o, int a);
extern "C" void* func_00243C18(void* table, int* idx, int* out);
extern "C" int func_00245BE8(void* p);
extern "C" void func_00245C68(void* p, int a, int b);
extern "C" void func_00245B68(void* p, int a);

extern "C" void func_0023D230(Obj_0023D230* o, int a, int b)
{
    int idx = func_0023BF98(o, 1);
    if (idx == -1)
        return;
    int tmp;
    void* p = func_00243C18(o->m_table, &idx, &tmp);
    if (func_00245BE8(p))
        func_00245C68(p, a, b);
    else
        func_00245B68(p, a);
}
