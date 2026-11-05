struct Mgr_0023C9D8 {
    int Call(int id);
};

extern "C" void* func_0023BAD8(Mgr_0023C9D8* self, int id, int create);
extern "C" int func_00245428(void* item);

int Mgr_0023C9D8::Call(int id)
{
    void* item = func_0023BAD8(this, id, 1);
    if (item) {
        return func_00245428(item);
    }
    return 0;
}
