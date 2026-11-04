extern "C" short func_0013E9D8(void* self);
extern "C" void* func_0013E9B8(void* self, int i);
extern "C" void func_0013C518(void* p, int a);

class C_0013ED40 {
public:
    bool SetAll(int a);
};

bool C_0013ED40::SetAll(int a)
{
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        func_0013C518(func_0013E9B8(this, i), a);
    }
    return true;
}
