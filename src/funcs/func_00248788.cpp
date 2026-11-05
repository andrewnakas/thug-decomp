struct Obj_00248788;
extern "C" int func_001E8248(void* params, unsigned int name, void** out, int req);
extern "C" void* func_00240850();
extern "C" int func_00240120(void* p, int a);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_002440B0(Obj_00248788* self, void* params);

struct Obj_00248788 {
    char pad[0x20];
    void* m20;
    void Fn();
};

void Obj_00248788::Fn()
{
    void* arr;
    if (func_001E8248(m20, 0x85104AB3, &arr, 0)) {
        int i = func_00240120(func_00240850(), 0);
        func_001E6AC8(m20, func_001E9378(arr, i));
        func_002440B0(this, m20);
    }
}
