extern "C" int func_0026E160(void* self, int a);
extern "C" void func_0026E060(void* self, int on);
extern "C" void func_0026E050(void* self, int a);
extern "C" void func_0026E058(void* self, int b);

int Set_0026E188(void* self, int a, int b)
{
    if (func_0026E160(self, a)) {
        func_0026E050(self, a);
        func_0026E058(self, b);
        func_0026E060(self, 1);
        return 1;
    }
    func_0026E060(self, 0);
    return 0;
}
