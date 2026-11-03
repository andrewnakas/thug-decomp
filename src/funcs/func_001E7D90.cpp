extern "C" void* func_00105520(void* p);
extern "C" void func_001E7C80(void* self, void* obj, void* a, void* b);

struct Obj_001E7D90 {
    void SetFromOwner(void* src, void* a, void* b);
};

void Obj_001E7D90::SetFromOwner(void* src, void* a, void* b)
{
    func_001E7C80(this, func_00105520(src), a, b);
}
