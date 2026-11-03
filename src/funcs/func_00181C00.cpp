extern char D_003E2798[];
extern "C" void func_00166D18(void* ctx, int w, int h, char* src, char* dst);
extern "C" void func_00166648(void* ctx, int w, int h, char* src, char* dst);
extern "C" void func_001669B8(void* ctx, int w, int h, char* src, char* dst);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct C_00181C00 {
    int m0;
    int m4;
    unsigned int m_levels;
    char padC[0x28 - 0xC];
    char* m_pixels;
    char pad2C[0x38 - 0x2C];
    unsigned int m_flags;
    int GetBpp();
    int GetWidth();
    int GetHeight();
    void Upload(char* src);
};

void C_00181C00::Upload(char* src)
{
    int bpp = GetBpp();
    int width = GetWidth();
    int height = GetHeight();
    char* dst = m_pixels;
    unsigned int i = 0;
    do {
        int w = width >> i;
        int h = height >> i;
        unsigned int size = (unsigned int)(w * h * bpp) >> 3;
        if (m_flags & (0x40000 << i)) {
            if (bpp == 4) func_00166D18(D_003E2798, w, h, src, dst);
        } else if (m_flags & (0x2000000 << i)) {
            if (bpp != 4) {
                if (bpp == 8) func_001669B8(D_003E2798, w, h, src, dst);
            } else {
                func_00166648(D_003E2798, w, h, src, dst);
            }
        } else {
            func_00331404(dst, src, size);
        }
        dst += size;
        src += size;
        i++;
    } while (i <= m_levels);
}
