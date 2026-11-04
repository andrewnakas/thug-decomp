extern "C" void func_001E84E8(void* self, void* a, void* b, bool flag);

struct Obj_001E8A50 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8A50::SetFlagged(void* a, void* b, int flag)
{
    func_001E84E8(this, a, b, flag != 0);
}
