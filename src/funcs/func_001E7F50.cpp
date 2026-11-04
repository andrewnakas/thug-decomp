extern "C" void* func_00105520(void* p);
extern "C" void func_001E7EB0(void* self, void* obj, void* a, void* b);

struct Obj_001E7F50 {
    void SetFromOwner(void* src, void* a, void* b);
};

void Obj_001E7F50::SetFromOwner(void* src, void* a, void* b)
{
    func_001E7EB0(this, func_00105520(src), a, b);
}
