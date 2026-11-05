struct Mgr_0023CF38 {
    bool Call(int id, int a, int b);
};

extern "C" void* func_0023BAD8(Mgr_0023CF38* self, int id, int create);
extern "C" int func_00245450(void* item, int a, int b);

bool Mgr_0023CF38::Call(int id, int a, int b)
{
    void* item = func_0023BAD8(this, id, 1);
    if (!item) {
        return false;
    }
    return func_00245450(item, a, b) != 0;
}
