struct Vec_00162150 {
    float x, y, z, w;
};

struct Mat_00162150;

extern "C" void func_00323298(Vec_00162150* out, Mat_00162150* m, Vec_00162150* in);
extern "C" unsigned char* func_00164D20(unsigned char* p);

void Xform_00162150(unsigned short* hdr, Mat_00162150* m)
{
    unsigned char* p = (unsigned char*)(hdr + 4);
    unsigned char* end = (unsigned char*)hdr + (hdr[0] * 16 + 0x10);
    Vec_00162150 v;
    do {
        int cmd = p[3];
        int t = cmd & 0x6E;
        if (t == 0x64) {
            int n = (unsigned char)(p[2] - 1) + 1;
            if ((cmd & 0x6F) == t) {
                float* f = (float*)(p + 4);
                for (int i = 0; i < n; i++) {
                    v.x = f[0];
                    v.y = f[1];
                    v.z = 0.0f;
                    v.w = 1.0f;
                    func_00323298(&v, m, &v);
                    *f++ = v.x;
                    *f++ = v.y;
                }
            } else {
                short* s = (short*)(p + 4);
                for (int i = 0; i < n; i++) {
                    v.x = s[0] - 0x2000;
                    v.y = s[1] - 0x2000;
                    v.z = 0.0f;
                    v.w = 1024.0f;
                    func_00323298(&v, m, &v);
                    *s++ = (int)v.x + 0x2000;
                    *s++ = (int)v.y + 0x2000;
                }
            }
        }
        p = func_00164D20(p);
    } while (p < end);
}
