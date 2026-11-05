struct Mgr_0023BEB0 {
    bool Call(int id, int v);
};

extern "C" void* func_0023BAD8(Mgr_0023BEB0* self, int id, int create);
extern "C" void func_00245190(void* item, int v);

bool Mgr_0023BEB0::Call(int id, int v)
{
    void* item = func_0023BAD8(this, id, 1);
    if (item) {
        func_00245190(item, v);
    }
    return item != 0;
}
