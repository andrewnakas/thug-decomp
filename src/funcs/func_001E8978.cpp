extern "C" void func_001E8038(void* self, void* a, void* b, bool flag);

struct Obj_001E8978 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8978::SetFlagged(void* a, void* b, int flag)
{
    func_001E8038(this, a, b, flag != 0);
}
