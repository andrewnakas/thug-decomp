extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8540(void* params, unsigned int name, const char** out, int required);
extern "C" unsigned short* func_00229C20(const char* text, unsigned short* count);
extern "C" unsigned short func_00229668(const char* text, int a);
extern "C" bool func_00211710(unsigned short key, int type, int a, void* params);

bool func_002118A8(void* params, int a, int type)
{
    if (func_001E8708(params, 0x2E7D5EE7)) {
        return true;
    }
    if (func_001E8708(params, 0xBCEB479A)) {
        return true;
    }
    const char* text;
    if (func_001E8540(params, 0x6C4E7971, &text, 0)) {
        unsigned short count = 0;
        unsigned short* keys = func_00229C20(text, &count);
        for (int i = 0; i < count; i++) {
            if (func_00211710(keys[i], type, a, params) && type == 5) {
                return true;
            }
        }
        return true;
    }
    const char* key;
    if (func_001E8540(params, 0xA1DC81F9, &key, 0)) {
        return func_00211710(func_00229668(key, 1), type, a, params);
    }
    return false;
}
