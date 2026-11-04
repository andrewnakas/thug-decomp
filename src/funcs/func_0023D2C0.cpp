extern char D_00373810[];

struct Mgr_0023D2C0 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023BF98(Mgr_0023D2C0* self, int a);
extern "C" void* func_00243C18(void* table, int* key, int* out);
extern "C" void* func_00244528(void* goal);
extern "C" bool func_00245DE8(void* goal);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" bool func_00245E10(void* goal);
extern "C" int func_00246258(void* goal);
extern "C" void func_0023BD18(Mgr_0023D2C0* self, int id);
extern "C" bool func_00245F90(void* goal);
extern "C" void func_0024D350(void* goal);
extern "C" bool func_00248738(void* goal);
extern "C" void func_0024E550(void* goal);

void func_0023D2C0(Mgr_0023D2C0* self)
{
    int key = func_0023BF98(self, 1);
    if (key == -1) {
        return;
    }
    int out;
    void* goal = func_00243C18(self->m_table, &key, &out);
    void* params = func_00244528(goal);
    if (func_00245DE8(goal) || func_001E8708(params, 0x8E6014F6)) {
        if (!func_001E87B8(params, D_00373810) && func_00245E10(goal)) {
            func_0023BD18(self, func_00246258(goal));
        }
    } else if (func_00245F90(goal)) {
        func_0024D350(goal);
    } else if (func_00248738(goal)) {
        func_0024E550(goal);
    }
}
