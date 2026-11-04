extern char D_00392288[];
extern char D_00378E38[];
extern char D_00378E58[];
extern char D_00378E68[];

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

bool func_002ACD38()
{
    void* p = func_001E6978(func_001190D0(8));
    func_001E73C8(p, D_00392288, func_001F0D78(D_00378E38));
    func_001E73C8(p, D_00378E58, 0);
    func_001F0370(D_00378E68, p, 0, 0);
    if (p) {
        func_001E6AE8(p, 3);
    }
    return true;
}
