extern int D_0038881C;
extern char D_00375EF0[];
extern "C" void* func_001317D0(int id);
extern "C" void func_00134F60(void* p);
extern "C" int func_001E5648(char* name, int a);
extern "C" bool func_00264E38(void* self, int a);

struct Obj_00264DD8 {
    char pad[0x18];
    int m18;
    bool Refresh();
};

bool Obj_00264DD8::Refresh()
{
    func_00134F60(func_001317D0(m18));
    if (!D_0038881C && func_001E5648(D_00375EF0, 0))
        func_00264E38(this, 2);
    return true;
}
