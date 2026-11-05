extern "C" int func_001E7200(void* p, unsigned int name, void* v);

struct Obj_0024F728 {
    int m0;
    char m4[0x10];
    int Set(void* v);
};

int Obj_0024F728::Set(void* v)
{
    return func_001E7200(m4, 0x4D42E61D, v);
}
