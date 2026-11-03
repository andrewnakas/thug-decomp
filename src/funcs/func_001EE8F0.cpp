extern "C" void* func_00105520(void* p);
extern "C" void func_001EE8C8(void* self, void* obj, void* a, void* b);

struct Obj_001EE8F0 {
    void SetFromOwner(void* src, void* a, void* b);
};

void Obj_001EE8F0::SetFromOwner(void* src, void* a, void* b)
{
    func_001EE8C8(this, func_00105520(src), a, b);
}
