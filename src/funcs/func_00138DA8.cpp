/* sym: _vt$13Node_00138DA8 = 0x0035DE98 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00139628(void* self, int n);
extern void* D_00388A70;
extern "C" int func_00105520(const char* s);

class Node_00138DA8 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    Node_00138DA8(const char* name, int withList);
    virtual ~Node_00138DA8();
};

Node_00138DA8::Node_00138DA8(const char* name, int withList)
{
    m0 = func_00105520(name);
    m4 = 1;
    if (withList)
        m8 = func_00139628(func_0010A638(D_00388A70, 0x18, 1, 0), 5);
    else
        m8 = 0;
}
