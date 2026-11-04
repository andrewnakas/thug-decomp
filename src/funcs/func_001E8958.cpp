extern "C" void func_001E7FA8(void* self, void* a, void* b, bool flag);

struct Obj_001E8958 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8958::SetFlagged(void* a, void* b, int flag)
{
    func_001E7FA8(this, a, b, flag != 0);
}
