struct Vec3_001E66C0 {
    float x, y, z;
};

struct Vec4_001E66C0 {
    float x, y, z, w;
};

struct Array_001E66C0 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern "C" void func_001E6518(Array_001E66C0*);
extern "C" void func_001E8E98(Array_001E66C0*, unsigned int, int);
extern "C" void** func_001E9038(Array_001E66C0*);
extern "C" void* func_001E4DE0(void*);
extern "C" void* func_001E8C30(unsigned int);
extern "C" Vec3_001E66C0* func_001E4C80(void*);
extern "C" void* func_001E8C80(unsigned int);
extern "C" Vec4_001E66C0* func_001E4C68(void*);
extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" void func_001E6A00(void*, void*);
extern "C" void* func_00122CF8(unsigned int);
extern "C" Array_001E66C0* func_001E8DD0(void*);

extern "C" void func_001E66C0(Array_001E66C0* dst, Array_001E66C0* src)
{
    func_001E6518(dst);
    unsigned int n = src->mC;
    int type = src->m8;
    func_001E8E98(dst, n, type);
    if (!n)
        return;
    void** s = func_001E9038(src);
    void** d = func_001E9038(dst);
    switch (type) {
    case 1:
    case 2:
    case 13:
        {
            void** sp = s;
            void** dp = d;
            for (unsigned int i = 0; i < n; i++)
                *dp++ = *sp++;
        }
        break;
    case 3:
    case 4:
        {
            void** sp = s;
            void** dp = d;
            for (unsigned int i = 0; i < n; i++) {
                if (*sp)
                    *dp = func_001E4DE0(*sp);
                sp++;
                dp++;
            }
        }
        break;
    case 5:
        {
            void** sp = s;
            void** dp = d;
            for (unsigned int i = 0; i < n; i++) {
                Vec3_001E66C0* v = (Vec3_001E66C0*)*sp;
                if (v) {
                    Vec3_001E66C0* c = func_001E4C80(func_001E8C30(12));
                    *c = *v;
                    *dp = c;
                }
                sp++;
                dp++;
            }
        }
        break;
    case 6:
        {
            void** sp = s;
            void** dp = d;
            for (unsigned int i = 0; i < n; i++) {
                Vec4_001E66C0* v = (Vec4_001E66C0*)*sp;
                if (v) {
                    Vec4_001E66C0* c = func_001E4C68(func_001E8C80(16));
                    *c = *v;
                    *dp = c;
                }
                sp++;
                dp++;
            }
        }
        break;
    case 10:
        {
            void** sp = s;
            void** dp = d;
            for (unsigned int i = 0; i < n; i++) {
                void* v = *sp;
                if (v) {
                    void* c = func_001E6978(func_001190D0(8));
                    func_001E6A00(c, v);
                    *dp = c;
                }
                sp++;
                dp++;
            }
        }
        break;
    case 12:
        {
            void** sp = s;
            void** dp = d;
            for (unsigned int i = 0; i < n; i++) {
                Array_001E66C0* v = (Array_001E66C0*)*sp;
                if (v) {
                    Array_001E66C0* c = func_001E8DD0(func_00122CF8(16));
                    func_001E66C0(c, v);
                    *dp = c;
                }
                sp++;
                dp++;
            }
        }
        break;
    }
}
