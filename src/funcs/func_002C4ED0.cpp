extern void** D_0039274C;
extern char D_0037A768[];
extern char D_0037A780[];
extern char D_0037A798[];
extern char D_0037A7B8[];
extern char D_0037A7D0[];
extern char D_0037A7E8[];
extern char D_0037A800[];
extern "C" void func_002B8470(void* p, int v);
extern "C" void func_002B84C8(void* p, int v);
extern "C" void func_002B8540(void* p, int v);
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Obj_002C4ED0 {
    void Enable(int on);
};

void Obj_002C4ED0::Enable(int on)
{
    func_002B8470(*D_0039274C, 0);
    func_002B84C8(*D_0039274C, on);
    func_002B8540(*D_0039274C, on);
    if (on) {
        func_001F0370(D_0037A768, 0, 0, 0);
        func_001F0370(D_0037A780, 0, 0, 0);
        func_001F0370(D_0037A798, 0, 0, 0);
        func_001F0370(D_0037A7B8, 0, 0, 0);
    } else {
        func_001F0370(D_0037A7D0, 0, 0, 0);
        func_001F0370(D_0037A7E8, 0, 0, 0);
        func_001F0370(D_0037A800, 0, 0, 0);
    }
}
