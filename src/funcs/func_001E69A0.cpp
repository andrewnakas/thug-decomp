extern int D_0038E604;
extern int D_0038E608;
extern "C" void func_001E6970(void* self);
extern "C" void func_001E6A00(void* self, void* src);

void* func_001E69A0(void* self, void* src)
{
    func_001E6970(self);
    func_001E6A00(self, src);
    D_0038E604++;
    if (D_0038E608 < D_0038E604)
        D_0038E608 = D_0038E604;
    return self;
}
