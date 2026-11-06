/* const: 0x149960 */
extern void* D_003942CC;
extern "C" int func_0010E1E8(const char* name, int* size, void* buf, int max);
extern "C" bool func_0017D6D8(void* data, int size, void* obj, int a, int b, int c, int d);

extern "C" void* func_0017D978(const char* name, void* obj, int a, int b, int c, int d)
{
    int size;
    void* data = (void*)func_0010E1E8(name, &size, D_003942CC, 0x149960);
    func_0017D6D8(data, size, obj, a, b, c, d);
    return obj;
}
