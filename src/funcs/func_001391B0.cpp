extern "C" unsigned int func_00105520(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331678(char* dst, const char* src);
extern int D_0034D6D0[];
extern char D_0035DDF8[];

struct TexDict_001391B0;
extern "C" void* func_00139468(TexDict_001391B0* d, unsigned int key);

extern "C" void* func_001391B0(TexDict_001391B0* d, const char* name)
{
    void* tex = 0;
    unsigned int crc = func_00105520(name);
    for (int i = 0; D_0034D6D0[i] > 0; i++) {
        tex = func_00139468(d, crc * D_0034D6D0[i]);
        if (tex) {
            break;
        }
    }
    if (!tex) {
        char buf[512];
        func_00331A9C(buf, name);
        if (func_00331BB8(buf) >= 5) {
            buf[func_00331BB8(buf) - 4] = 0;
            func_00331678(buf, D_0035DDF8);
        }
        crc = func_00105520(buf);
        for (int i = 0; D_0034D6D0[i] > 0; i++) {
            tex = func_00139468(d, crc * D_0034D6D0[i]);
            if (tex) {
                break;
            }
        }
    }
    return tex;
}
