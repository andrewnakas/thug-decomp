extern "C" int func_00105520(const void* name);
extern "C" void func_00109B10(void* self, const int* key, void* value);

void func_00109B78(void* self, const void* name, void* value)
{
    int key = func_00105520(name);
    func_00109B10(self, &key, value);
}
