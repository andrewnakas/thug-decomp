struct Obj_002622B8;
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_00262300(Obj_002622B8* self, int a, unsigned int name);

struct Obj_002622B8 {
    int m0;
    Obj_002622B8(int a, const char* name);
};

Obj_002622B8::Obj_002622B8(int a, const char* name)
{
    func_00262300(this, a, func_001F0D78(name));
}
