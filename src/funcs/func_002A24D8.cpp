extern void* D_0038FC78;
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_00215EE0(int a, int b);
extern "C" int func_00203018(void* p, unsigned int a, unsigned int b);

struct Obj_002A24D8;
extern "C" int func_002A8560(Obj_002A24D8* o);

struct Obj_002A24D8 {
    char pad[0xBC];
    char mBC[4];
    bool Check();
};

bool Obj_002A24D8::Check()
{
    void* q = D_0038FC78;
    if (func_002A8560(this) || func_0024F938(func_0022E358(q)) == (int)0x34861A16
        || func_0024F938(func_0022E358(q)) == (int)0x9D65D0E7) {
        if (func_0024F938(func_0022E358(q)) != (int)0x1C471C60)
            return false;
    }
    if (func_00215EE0(0, 0) || func_00203018(mBC, 0x043EE978, 0x21902065) == (int)0xF81BC89B
        || func_0024F938(func_0022E358(q)) == (int)0xF9D5D933 || func_0024F938(func_0022E358(q)) == (int)0xCA1F360F)
        return true;
    return false;
}
