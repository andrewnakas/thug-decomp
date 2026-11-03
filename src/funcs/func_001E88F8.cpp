extern "C" void func_001E7E58(void* self, void* a, void* b, bool flag);

struct Obj_001E88F8 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E88F8::SetFlagged(void* a, void* b, int flag)
{
    func_001E7E58(this, a, b, flag != 0);
}
