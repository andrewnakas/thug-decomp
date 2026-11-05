struct Mgr_0023BEF8 {
    bool Call(int id, int v);
};

extern "C" void* func_0023BAD8(Mgr_0023BEF8* self, int id, int create);
extern "C" void func_00244530(void* item);
extern "C" void func_002445E8(void* item, int v);

bool Mgr_0023BEF8::Call(int id, int v)
{
    void* item = func_0023BAD8(this, id, 1);
    if (item) {
        if (v == -1) {
            func_00244530(item);
        } else {
            func_002445E8(item, v);
        }
    }
    return item != 0;
}
