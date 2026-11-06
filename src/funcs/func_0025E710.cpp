/* sym: __13Base_0025A878 = 0x0025A878 */
/* sym: _vt$12Obj_0025E710 = 0x003757E8 */
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);

struct Base_0025A878 {
    char pad[0x14];
    Base_0025A878();
    virtual void V0();
};

struct Obj_0025E710 : Base_0025A878 {
    char pad18[0x24];
    int m3C;
    int m40;
    char pad44[0xC];
    void* m50;
    char pad54[0xC];
    int m60;
    int m64;
    Obj_0025E710();
    virtual void V0();
};

Obj_0025E710::Obj_0025E710()
{
    m3C = 0;
    m40 = 0;
    m50 = func_001E6978(func_001190D0(8));
    m64 = 0;
    m60 = 0;
}
