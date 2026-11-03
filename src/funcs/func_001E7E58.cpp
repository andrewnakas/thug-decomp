extern "C" void* func_00105520(void* p);
extern "C" void func_001E7DE8(void* self, void* obj, void* a, void* b);

struct Obj_001E7E58 {
    void SetFromOwner(void* src, void* a, void* b);
};

void Obj_001E7E58::SetFromOwner(void* src, void* a, void* b)
{
    func_001E7DE8(this, func_00105520(src), a, b);
}
