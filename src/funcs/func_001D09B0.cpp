extern "C" void* func_001F0D78(void* p);
extern "C" void func_001D08E8(void* self, void* obj, void* a, void* b);

struct Obj_001D09B0 {
    void SetFromOwner(void* src, void* a, void* b);
};

void Obj_001D09B0::SetFromOwner(void* src, void* a, void* b)
{
    func_001D08E8(this, func_001F0D78(src), a, b);
}
