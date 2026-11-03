extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* s, unsigned int name, void** out, int required);
extern "C" void* func_0022E050(void* game);
extern "C" int func_00262828(void* list);
extern "C" char* func_00262860(void* list, int i);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);

extern void* D_0038FC78;

bool Cmd_0021CF08(void* params, void* script)
{
    unsigned int sname;
    func_001E8398(params, 0x62BA3F6A, &sname, 1);
    void* sparams = 0;
    func_001E8180(params, 0x7031F10C, &sparams, 0);
    void* list = func_0022E050(D_0038FC78);
    int count = func_00262828(list);
    for (int i = 0; i < count; i++) {
        char* profile = func_00262860(list, i) + 0x5C;
        void* p = func_001E6978(func_001190D0(8));
        func_001E6AC8(p, sparams);
        func_001E6AC8(p, profile);
        func_001F0210(sname, p, 0, 0, 0);
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
    return true;
}
