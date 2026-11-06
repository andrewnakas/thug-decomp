extern char D_003C38C0[];
extern char D_0038A058[];
extern char D_0035E030[];
extern void* D_00393EF4;
extern void* D_00393EF8;
extern "C" void func_0013AC30(void* table, int n);
extern "C" void* func_00139AC0(const char* name);

extern "C" void func_0013ACD8(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        func_0013AC30(D_003C38C0, 4);
        D_00393EF4 = func_00139AC0(D_0038A058);
        D_00393EF8 = func_00139AC0(D_0035E030);
    }
}
