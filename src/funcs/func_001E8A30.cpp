extern "C" void func_001E8398(void* self, void* a, void* b, bool flag);

struct Obj_001E8A30 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8A30::SetFlagged(void* a, void* b, int flag)
{
    func_001E8398(this, a, b, flag != 0);
}
