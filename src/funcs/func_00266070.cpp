extern "C" void func_00265EA0(void* self, int a);
extern "C" void* func_00265EC8(void* self, int b);
extern "C" int func_00266AA0(void* map, int* key, void* v);

struct Obj_00266070 {
    char pad[0x20];
    int m20;
    bool Link(int a, int b);
};

bool Obj_00266070::Link(int a, int b)
{
    func_00265EA0(this, a);
    void* node = func_00265EC8(this, b);
    func_00266AA0(&m20, &a, node);
    return true;
}
