extern "C" void* func_0022E358(int a);
extern "C" int func_0024F938(void* a);
extern "C" int func_001F0D78(char* name);
extern "C" int func_002448C0(void* self, int a, int b);
extern int D_0038FC78;
extern char D_003741B0[];

struct Obj_0024B898 {
    int Check(int a, int b);
};

int Obj_0024B898::Check(int a, int b)
{
    int g = D_0038FC78;
    if (a == 0) {
        int mode = func_0024F938(func_0022E358(g));
        if (mode == func_001F0D78(D_003741B0)) {
            return 0;
        }
    }
    return func_002448C0(this, a, b);
}
