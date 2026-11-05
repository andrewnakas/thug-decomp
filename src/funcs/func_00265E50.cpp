extern "C" void* func_00265EA0(void* self, int a);
extern "C" int func_00265250(void* p, int n);

bool Send_00265E50(void* self, int a, int n)
{
    void* p = func_00265EA0(self, a);
    if (p) {
        func_00265250(p, n == -1 ? -1 : n + 1);
        return true;
    }
    return false;
}
