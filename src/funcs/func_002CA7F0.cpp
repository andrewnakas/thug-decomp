extern void* D_0038C608;
extern void* D_00392808;
extern char D_00392860[];
extern char D_0037ACF8[];

extern "C" void* func_00187B48(void* p, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* p, char* name, unsigned int v);
extern "C" void* func_001E55F8(char* s, int f);
extern "C" void func_00186D60(void* m, void* a, void* s, int f);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_002C5410(void* p);

extern "C" bool func_002CA7F0()
{
    if (!func_00187B48(D_0038C608, 0x64716BEE)) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E73C8(s, D_00392860, 0x64716BEE);
        void* m = D_0038C608;
        func_00186D60(m, func_001E55F8(D_0037ACF8, 0), s, 1);
        if (s) func_001E6AE8(s, 3);
    }
    func_002C5410(D_00392808);
    return true;
}
