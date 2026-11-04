extern "C" int func_00105520(const void* name);
extern "C" void func_0010A230(void* self, const int* key, void* value);

void func_0010A298(void* self, const void* name, void* value)
{
    int key = func_00105520(name);
    func_0010A230(self, &key, value);
}
