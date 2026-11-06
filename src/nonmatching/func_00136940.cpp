/* fuzzy: 95.7 */
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

struct Rgba_00136940 {
    unsigned char r, g, b, a;
    Rgba_00136940(unsigned char ar, int ag, int ab, int aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
    Rgba_00136940(const Rgba_00136940& o) { *this = o; }
};

extern "C" void func_00135E88(int id, Rgba_00136940 c);

extern "C" void func_00136940(void* params)
{
    int id, r, g, b;
    func_001E7DE8(params, 0x7F8C98FE, &id, 0);
    func_001E7DE8(params, 0x93F60062, &r, 0);
    func_001E7DE8(params, 0xFE2BE489, &g, 0);
    func_001E7DE8(params, 0x8E411006, &b, 0);
    Rgba_00136940 c(r, g, b, 0x80);
    func_00135E88(id, c);
}
