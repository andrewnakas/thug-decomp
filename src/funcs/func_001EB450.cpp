typedef unsigned char uchar_1EB450;

struct Heap_001EB450 {
    char pad[0xEC];
    int m_EC;
};
extern Heap_001EB450* D_00388A70;

struct Vec_001EB450 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Pair_001EB450 {
    int m0;
    int m4;
    int m8;
};

extern "C" uchar_1EB450* func_001ECA68(uchar_1EB450* p);
extern "C" uchar_1EB450* func_001EB070(uchar_1EB450* p);
extern "C" uchar_1EB450* func_001EB338(uchar_1EB450* p);
extern "C" int func_001EC7A0(uchar_1EB450* p);
extern "C" void func_0010A950(Heap_001EB450* h, int ctx);
extern "C" void func_0010A9B0(Heap_001EB450* h);
extern "C" void func_001E8E98(void* arr, int count, int type);
extern "C" void* func_001E9038(void* arr);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" uchar_1EB450* func_001EC088(void* s, uchar_1EB450* p, void* a);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" char* func_001E4DE0(uchar_1EB450* p);
extern "C" void* func_001E8C80(int size);
extern "C" Vec_001EB450* func_001E4C68(void* p);
extern "C" void* func_001E8C30(int size);
extern "C" Pair_001EB450* func_001E4C80(void* p);

static inline int Tok_1EB450(uchar_1EB450* p) { return *p; }

extern "C" uchar_1EB450* func_001EB450(void* arr, uchar_1EB450* p, void* a)
{
    uchar_1EB450* start = p;
    int type = 0;
    int count = 0;

    for (p = func_001ECA68(p + 1); Tok_1EB450(p) != 6; p = func_001ECA68(p)) {
        switch (*p) {
        case 1:
            break;
        case 22:
            type = 13;
            break;
        case 23:
        case 24:
            if (type != 2) type = 1;
            break;
        case 26:
            type = 2;
            break;
        case 31:
            type = 5;
            break;
        case 30:
            type = 6;
            break;
        case 27:
            type = 3;
            break;
        case 28:
            type = 4;
            break;
        case 3:
            type = 10;
            break;
        case 5:
            type = 12;
            break;
        }
switch (*p) {
        case 1:
        case 2:
        case 9:
            p = func_001EB070(p);
            break;
        case 3:
        case 5:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
        case 28:
        case 30:
        case 31:
            count++;
            p = func_001EB338(p);
            break;
        }
    }
    if (!type) return p + 1;

    p = start;
    func_0010A950(D_00388A70, D_00388A70->m_EC);
    func_001E8E98(arr, count, type);
    func_0010A9B0(D_00388A70);

    switch (type) {
    case 1: {
        int* d = (int*)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); Tok_1EB450(p) != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 9:
                break;
            case 23:
            case 24: {
                int* q = d++;
                *q = func_001EC7A0(p);
            }
            case 2:
                p += 4;
                break;
            }
        }
        p++;
        break;
    }
    case 2: {
        float* d = (float*)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); Tok_1EB450(p) != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 9:
                break;
            case 23:
            case 24: {
                float* q = d++;
                *q = func_001EC7A0(p);
                p += 4;
                break;
            }
            case 26: {
                float* q = d++;
                *(int*)q = func_001EC7A0(p);
            }
            case 2:
                p += 4;
                break;
            }
        }
        p++;
        break;
    }
    case 13: {
        int* d = (int*)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 2:
                p += 4;
                break;
            case 9:
                break;
            case 22: {
                int* q = d++;
                *q = func_001EC7A0(p);
                p += 4;
                break;
            }
            }
        }
        p++;
        break;
    }
    case 10: {
        void** d = (void**)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            switch (*p) {
            case 1:
            case 9:
                p++;
                break;
            case 2:
                p += 5;
                break;
            case 3: {
                void* s = func_001E6978(func_001190D0(8));
                p = func_001EC088(s, p, a);
                *d++ = s;
                break;
            }
            }
        }
        p++;
        break;
    }
    case 12: {
        void** d = (void**)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 2:
                p += 4;
                break;
            case 5: {
                void* s = func_001E8DD0(func_00122CF8(0x10));
                p = func_001EB450(s, p - 1, a);
                *d++ = s;
                break;
            }
            }
        }
        p++;
        break;
    }
    case 3: {
        char** d = (char**)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 2:
                p += 4;
                break;
            case 9:
                break;
            case 27: {
                int len = func_001EC7A0(p);
                p += 4;
                *d++ = func_001E4DE0(p);
                p += len;
                break;
            }
            }
        }
        p++;
        break;
    }
    case 4: {
        char** d = (char**)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 2:
                p += 4;
                break;
            case 9:
                break;
            case 28: {
                int len = func_001EC7A0(p);
                p += 4;
                *d++ = func_001E4DE0(p);
                p += len;
                break;
            }
            }
        }
        p++;
        break;
    }
    case 6: {
        Vec_001EB450** d = (Vec_001EB450**)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 2:
                p += 4;
                break;
            case 9:
                break;
            case 30: {
                Vec_001EB450* v = func_001E4C68(func_001E8C80(0x10));
                v->m4 = func_001EC7A0(p);
                p += 4;
                v->m8 = func_001EC7A0(p);
                p += 4;
                v->mC = func_001EC7A0(p);
                p += 4;
                *d++ = v;
                break;
            }
            }
        }
        p++;
        break;
    }
    case 5: {
        Pair_001EB450** d = (Pair_001EB450**)func_001E9038(arr);
        for (p = func_001ECA68(p + 1); *p != 6; p = func_001ECA68(p)) {
            int t = *p++;
            switch (t) {
            case 1:
                break;
            case 2:
                p += 4;
                break;
            case 9:
                break;
            case 31: {
                Pair_001EB450* v = func_001E4C80(func_001E8C30(0xC));
                v->m4 = func_001EC7A0(p);
                p += 4;
                v->m8 = func_001EC7A0(p);
                p += 4;
                *d++ = v;
                break;
            }
            }
        }
        p++;
        break;
    }
    }
    return p;
}
