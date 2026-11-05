struct Mgr_0023FB80 {
    int Call(int id, int v);
};

extern "C" void* func_0023BAD8(Mgr_0023FB80* self, int id, int create);
extern "C" int func_00246740(void* item);
extern "C" int func_0024A3E8(void* item, int v);

int Mgr_0023FB80::Call(int id, int v)
{
    void* item = func_0023BAD8(this, id, 1);
    if (item && func_00246740(item)) {
        return func_0024A3E8(item, v);
    }
    return 0;
}
