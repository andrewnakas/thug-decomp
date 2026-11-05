extern char D_00390730[];
extern "C" void* func_001F0D78(char* name);
extern "C" void func_00258528(void* p, char* buf, int n);

struct Obj_002521A0 {
    void Fn();
};

void Obj_002521A0::Fn()
{
    char buf[0x200];
    func_00258528(func_001F0D78(D_00390730), buf, -1);
}
