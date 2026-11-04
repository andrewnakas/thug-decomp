struct Vec_001EA0B8 {
    int m0;
    float m4;
    float m8;
    float mC;
};

struct Array_001EA0B8 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern "C" unsigned char* func_001EC860(unsigned char*, unsigned short);
extern "C" void** func_001E9038(Array_001EA0B8*);
extern "C" unsigned char* func_001EC7F8(unsigned char*, void*);
extern "C" unsigned char* func_001EC828(unsigned char*, float);
extern "C" unsigned int func_001E9B08(void*, unsigned char*, unsigned int, int);

extern "C" unsigned int func_001EA0B8(Array_001EA0B8* a, unsigned char* buf, unsigned int size, int flags)
{
    if (size < 3)
        return 0;
    unsigned int type = a->m8;
    unsigned int n = a->mC;
    unsigned int left = size - 3;
    *buf = type;
    buf = func_001EC860(buf + 1, n);
    switch (type) {
    case 0:
        break;
    case 1:
    case 2:
    case 13: {
        if (left < n * 4)
            return 0;
        void** data = func_001E9038(a);
        for (unsigned int i = 0; i < n; i++)
            buf = func_001EC7F8(buf, *data++);
        left -= n * 4;
        break;
    }
    case 3:
    case 4: {
        void** data = func_001E9038(a);
        for (unsigned int i = 0; i < n; i++) {
            char* s = (char*)*data++;
            while (*s) {
                if (!left)
                    return 0;
                left--;
                *buf++ = *s++;
            }
            if (!left)
                return 0;
            *buf++ = 0;
            left--;
        }
        return size - left;
    }
    case 5: {
        if (left < n * 8)
            return 0;
        void** data = func_001E9038(a);
        for (unsigned int i = 0; i < n; i++) {
            Vec_001EA0B8* v = (Vec_001EA0B8*)*data++;
            buf = func_001EC828(buf, v->m4);
            buf = func_001EC828(buf, v->m8);
        }
        left -= n * 8;
        break;
    }
    case 6: {
        if (left < n * 12)
            return 0;
        void** data = func_001E9038(a);
        for (unsigned int i = 0; i < n; i++) {
            Vec_001EA0B8* v = (Vec_001EA0B8*)*data++;
            buf = func_001EC828(buf, v->m4);
            buf = func_001EC828(buf, v->m8);
            buf = func_001EC828(buf, v->mC);
        }
        left -= n * 12;
        break;
    }
    case 10: {
        void** data = func_001E9038(a);
        for (unsigned int i = 0; i < n; i++) {
            unsigned int w = func_001E9B08(*data++, buf, left, flags);
            if (!w)
                return 0;
            left -= w;
            buf += w;
        }
        return size - left;
    }
    case 12: {
        void** data = func_001E9038(a);
        for (unsigned int i = 0; i < n; i++) {
            unsigned int w = func_001EA0B8((Array_001EA0B8*)*data++, buf, left, flags);
            if (!w)
                return 0;
            left -= w;
            buf += w;
        }
        break;
    }
    }
    return size - left;
}
