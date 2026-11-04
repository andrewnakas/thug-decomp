extern void* D_0038C608;
extern char D_00375E60[];
extern char D_00375E70[];
extern char D_00375E98[];

extern "C" bool func_001E86D0(void* params, const char* name);
extern "C" void* func_001E55F8(const char* name, int a);
extern "C" void func_00186D60(void* mgr, void* s, void* params, int a);

void func_00264A38(void* self, void* params)
{
    if (func_001E86D0(params, D_00375E60)) {
        void* mgr = D_0038C608;
        func_00186D60(mgr, func_001E55F8(D_00375E70, 0), params, 1);
    } else {
        void* mgr = D_0038C608;
        func_00186D60(mgr, func_001E55F8(D_00375E98, 0), params, 1);
    }
}
