/* sym: _vt$12Obj_00265420 = 0x00376000 */
/* sym: __12Obj_00265420 = 0x00265420 */
/* sym: __12Arr_00265420i = 0x002666E8 */
struct Arr_00265420 {
    char m[0x18];
    Arr_00265420(int n);
};
extern "C" void func_0010A950(void* heap, void* ctx);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* mem);

struct Heap_00265420 {
    char pad[0xEC];
    void* mEC;
};
extern Heap_00265420* D_00388A70;

class Obj_00265420 {
public:
    int m0;
    int m4;
    Arr_00265420 m8;
    Arr_00265420 m20;
    void* m38;
    Obj_00265420();
    virtual void V0();
};

Obj_00265420::Obj_00265420() : m8(8), m20(8)
{
    func_0010A950(D_00388A70, D_00388A70->mEC);
    m38 = func_001E6978(func_001190D0(8));
    func_0010A9B0(D_00388A70);
}
