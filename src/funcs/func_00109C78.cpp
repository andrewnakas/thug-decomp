extern "C" int func_00105520(const void* name);
extern "C" void func_00109BC0(void* self, const int* key, void* value);

void func_00109C78(void* self, const void* name, void* value)
{
    int key = func_00105520(name);
    func_00109BC0(self, &key, value);
}
