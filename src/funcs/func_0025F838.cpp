struct List_0025F838;
extern "C" int func_0025F0F0(List_0025F838* self);
extern "C" void* func_0025F1C8(List_0025F838* self, int a);

struct List_0025F838 {
    bool Fn(int a);
};

bool List_0025F838::Fn(int a)
{
    if (!func_0025F0F0(this)) return true;
    if (a) return func_0025F1C8(this, a) == 0;
    return false;
}
