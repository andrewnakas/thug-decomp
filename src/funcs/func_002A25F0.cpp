extern void* D_0038FC78;
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_0024F540(void* p);
extern "C" int func_00203018(void* p, unsigned int a, unsigned int b);

struct Obj_002A25F0 {
    char pad[0xBC];
    char mBC[4];
    bool Check();
};

bool Obj_002A25F0::Check()
{
    void* q = D_0038FC78;
    if (func_0024F938(func_0022E358(q)) == (int)0x1C471C60)
        return false;
    if (!func_0024F540(func_0022E358(q)))
        return false;
    return func_00203018(mBC, 0x92A6A8C8, 0x21902065) == (int)0xD071112F;
}
