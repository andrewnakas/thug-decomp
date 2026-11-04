extern char D_003737F8[];

struct Mgr_0023C6C0 {
    int pad0;
    char m_list[4];
};

extern "C" int func_0023C040(Mgr_0023C6C0* mgr);
extern "C" void* func_00243C18(void* list, int* i, int* out);
extern "C" bool func_002463A0(void* goal);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void* func_00244528(void* goal);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_00243FB0(void* goal);

void func_0023C6C0(Mgr_0023C6C0* mgr)
{
    int i;
    for (i = 0; i < func_0023C040(mgr); i++) {
        int key;
        void* goal = func_00243C18(mgr->m_list, &i, &key);
        if (func_002463A0(goal)) {
            func_001F0210(func_001F0D78(D_003737F8), func_00244528(goal), 0, 0, 0);
            func_00243FB0(goal);
        }
    }
}
