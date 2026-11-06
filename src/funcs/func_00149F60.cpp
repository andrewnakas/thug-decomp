/* sym: __12Img_00149F60RC12Img_00149F60 = 0x00146D00 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

class Img_00149F60 {
public:
    char pad[0x30];
    Img_00149F60(const Img_00149F60& o);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class Fac_00149F60 {
public:
    Img_00149F60* Clone(int a, const Img_00149F60* o);
};

Img_00149F60* Fac_00149F60::Clone(int a, const Img_00149F60* o)
{
    return new Img_00149F60(*o);
}
