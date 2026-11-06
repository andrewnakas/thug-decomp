extern "C" int func_00183348(void* p);
struct Obj_001ABFF8 {
    char pad[0xA04];
    int mA04[8];
    int Get(void* key);
};

int Obj_001ABFF8::Get(void* key)
{
    return mA04[func_00183348(key)];
}
