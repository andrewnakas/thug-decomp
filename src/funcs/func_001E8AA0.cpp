extern "C" void func_001E82B8(void* self, void* a, void* b, bool flag);

struct Obj_001E8AA0 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8AA0::SetFlagged(void* a, void* b, int flag)
{
    func_001E82B8(this, a, b, flag != 0);
}
