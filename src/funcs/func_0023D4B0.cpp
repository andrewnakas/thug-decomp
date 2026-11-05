struct Mgr_0023D4B0 {
    void Toggle(int id);
};

extern "C" void* func_0023BAD8(Mgr_0023D4B0* self, int id, int create);
extern "C" int func_002463A0(void* item);
extern "C" void func_00246640(void* item);
extern "C" void func_00246630(void* item);

void Mgr_0023D4B0::Toggle(int id)
{
    void* item = func_0023BAD8(this, id, 1);
    if (func_002463A0(item)) {
        func_00246640(item);
    } else {
        func_00246630(item);
    }
}
