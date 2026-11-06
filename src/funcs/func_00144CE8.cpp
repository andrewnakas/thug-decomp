extern "C" void* func_0013CA80(void* key, int arg);
extern "C" void func_00144CB0(void* self, int v);

struct Obj_00144CE8 {
    int m0;
    void* m4;
    void* m8;
    void Init(void* key);
};

void Obj_00144CE8::Init(void* key)
{
    m8 = key;
    m4 = func_0013CA80(key, 1);
    func_00144CB0(this, 0);
}
