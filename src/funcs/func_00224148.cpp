extern char D_0038F808[];
extern char D_00371C38[];
extern char D_00371C48[];
extern "C" int func_00113E98(char* buf);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_001E7360(void* s, unsigned int a, unsigned int b);
extern "C" bool func_0018A370(void* s, int a);
extern "C" void func_001F0370(char* name, int a, int b, int c);
extern "C" void func_00113EE8();
extern "C" void func_001E6AE8(void* s, int flags);

bool Cmd_00224148(void* params, void* script)
{
    char buf[0x100];
    if (func_00113E98(buf) > 0 && buf[0] == ' ') {
        void* s = func_001E6978(func_001190D0(8));
        unsigned int a = func_001F0D78(D_0038F808);
        unsigned int b = func_001F0D78(D_00371C38);
        func_001E7360(s, a, b);
        if (!func_0018A370(s, 0)) {
            func_001F0370(D_00371C48, 0, 0, 0);
            func_00113EE8();
        }
        if (s) func_001E6AE8(s, 3);
    }
    return true;
}
