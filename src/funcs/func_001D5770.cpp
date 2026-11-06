/* sym: _vt$13Base_001D5770 = 0x003642D0 */
/* sym: _vt$12Mid_001D5770 = 0x00364180 */
/* sym: _vt$12Der_001D5770 = 0x00363F90 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001D8170(void* src, void* arg, int flag);

class Base_001D5770 {
public:
    int m0;
    unsigned short m4;
    void* m8;
    virtual ~Base_001D5770();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class Mid_001D5770 : public Base_001D5770 {
public:
    unsigned char m10;
    virtual ~Mid_001D5770();
};

class Der_001D5770 : public Mid_001D5770 {
public:
    Der_001D5770(const Der_001D5770& o, void* data) : Mid_001D5770(o)
    {
        m4 |= 0x8000;
        m8 = data;
    }
    virtual ~Der_001D5770();
    Der_001D5770* Clone(void* arg);
};

Der_001D5770* Der_001D5770::Clone(void* arg)
{
    void* data = func_001D8170(m8, arg, 1);
    if (!data) {
        return 0;
    }
    return new Der_001D5770(*this, data);
}
