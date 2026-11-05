struct Mgr_0023BB00 {
    void* Find(void* key, int create);
};

extern "C" int func_0023FFC0(Mgr_0023BB00* self, void* key, int create);
extern "C" void* func_0023BAD8(Mgr_0023BB00* self, int id, int create);

void* Mgr_0023BB00::Find(void* key, int create)
{
    int id = func_0023FFC0(this, key, create);
    if (id) {
        return func_0023BAD8(this, id, create);
    }
    return 0;
}
