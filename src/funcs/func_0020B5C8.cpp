extern char D_0038F358[];
extern char D_0036FEB0[];

struct Array_0020B5C8 {
    int pad0;
    int pad4;
    unsigned char m_type;
    char pad9[3];
    unsigned int m_size;
};

extern "C" bool func_001E8AA0(void* params, const char* name, Array_0020B5C8** out, int required);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E88F8(void* params, const char* name, int* out, int required);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" const char* func_001E91C0(Array_0020B5C8* arr, unsigned int i);
extern "C" int func_001E9270(Array_0020B5C8* arr, unsigned int i);
extern "C" unsigned int func_001E9300(Array_0020B5C8* arr, unsigned int i);
extern "C" int func_00336228(const char* a, const char* b);

bool Cmd_0020B5C8(void* params, void* script)
{
    Array_0020B5C8* arr;
    func_001E8AA0(params, D_0038F358, &arr, 1);
    unsigned char type = arr->m_type;
    for (unsigned int i = 0; i < arr->m_size; i++) {
        switch (type) {
        case 1: {
            int v;
            func_001E88F8(params, D_0036FEB0, &v, 1);
            if (v == func_001E9270(arr, i))
                return true;
            break;
        }
        case 0xD: {
            unsigned int v;
            func_001E8A50(params, D_0036FEB0, &v, 1);
            if (v == func_001E9300(arr, i))
                return true;
            break;
        }
        case 3: {
            const char* s;
            func_001E8890(params, D_0036FEB0, &s, 1);
            if (!func_00336228(s, func_001E91C0(arr, i)))
                return true;
            break;
        }
        default:
            break;
        }
    }
    return false;
}
