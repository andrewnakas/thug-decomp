extern "C" void func_001E7C80(void* self, void* a, void* b, bool flag);

struct Obj_001E88B0 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E88B0::SetFlagged(void* a, void* b, int flag)
{
    func_001E7C80(this, a, b, flag != 0);
}
