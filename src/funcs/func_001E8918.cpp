extern "C" void func_001E7EB0(void* self, void* a, void* b, bool flag);

struct Obj_001E8918 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8918::SetFlagged(void* a, void* b, int flag)
{
    func_001E7EB0(this, a, b, flag != 0);
}
