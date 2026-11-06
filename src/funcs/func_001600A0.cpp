/* sym: __12Res_001600A0 = 0x0015F8D8 */

class Res_001600A0 {
public:
    float m0;
    float m4[4];
    float m14;
    char m18;
    Res_001600A0();
};

extern "C" void func_0015FE60(void* a, unsigned char* key, int n, void* b, Res_001600A0* out);

static inline Res_001600A0 Find_001600A0(void* a, unsigned char* key, int n, void* b) return r
{
    func_0015FE60(a, key, n, b, &r);
}

Res_001600A0 func_001600A0(void* a, void* b)
{
    unsigned char key[4];
    key[0] = 0;
    key[1] = 0;
    key[2] = 0;
    key[3] = 0;
    return Find_001600A0(a, key, 5, b);
}
