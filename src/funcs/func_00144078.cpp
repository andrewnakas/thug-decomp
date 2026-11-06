extern void* D_0038A63C;
extern "C" void func_00144A28(void* list);
extern "C" void* func_00144A38(void* list, int a);
extern "C" void func_00151D40(void* p);

extern "C" void func_00144078()
{
    if (D_0038A63C) {
        func_00144A28(D_0038A63C);
        void* p;
        while ((p = func_00144A38(D_0038A63C, 0))) {
            func_00151D40(p);
        }
    }
}
